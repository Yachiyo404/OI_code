#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
ll arr[N],g[125][125];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    if(n>=121){
        cout<<3;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            g[i][j]=1e9;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i]&arr[j]!=0&&i!=j)
                g[i][j]=1;
            if(i==j)
                g[i][j]=0;
        }
    }
    ll ans=LLONG_MAX;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&j!=k&&i!=k&&g[i][j]!=1e9&&g[i][k]!=1e9&&g[k][j]!=1e9)
                    ans=min(ans,g[i][j]+g[i][k]+g[k][j]);
            }
        }
    }
    if(ans==LLONG_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}