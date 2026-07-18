#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int main(){
    ios::sync_with_stdio(0);
    freopen("colony.in","r",stdin);
    freopen("colony.out","w",stdout);
    cin>>T;
    while(T--){
        int n,k,m,ans=1,sum=1;
        cin>>n>>k>>m;
        if(((n-k)*2-1)<=m&&k<n){
            ans+=(n-k);
            sum+=(n-k-1);
            m-=((n-k)*2-1);
        }
        else{
            m++;
            ans+=m/2;
            cout<<ans<<endl;
            continue;
        }
        if(((k-1)*2-sum)<=m&&k>1){
            cout<<n<<endl;
            continue;
        }
        else{
            ans+=m;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}