#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510;
ll n;
ll g[N][N],arr[N],vis[N],ans[N];
signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)
            g[i][j]=1e6;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)
            cin>>g[i][j];
    }
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    for(ll k=n;k>=1;k--){
        ll del=arr[k];
        vis[del]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][del]+g[del][j]);
        }
        ll sum=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(vis[i]&&vis[j])
                    sum+=g[i][j];
            }
        }
        ans[k]=sum;
    }
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}