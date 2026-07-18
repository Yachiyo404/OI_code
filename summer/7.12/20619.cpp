#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
int mp[205][205],sum[205][205];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            sum[i][j]=mp[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(int x1=1;x1<=n;x1++){
        for(int y1=1;y1<=m;y1++){
            for(int x2=x1;x2<=n;x2++){
                for(int y2=y1;y2<=m;y2++){
                    int tmp=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
                    if(tmp==(x2-x1+1)*(y2-y1+1))
                        ans=max(tmp,ans);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}