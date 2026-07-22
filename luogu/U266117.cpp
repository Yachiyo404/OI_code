#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+10;
ll n,m,ans;
ll a[N],b[N],f[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(ll i=1;i<=m;i++)
        cin>>b[i];
    for(ll i=1;i<=n;i++){
        ll maxx=1;
        for(ll j=1;j<=m;j++){
            if(a[i]==b[j])
                f[i][j]=max(f[i][j],maxx);
            else
                f[i][j]=f[i-1][j];
            if(b[j]<a[i])
                maxx=max(maxx,f[i-1][j]+1);
        }
    }
    for(ll i=1;i<=m;i++)
        ans=max(ans,f[n][i]);
    cout<<ans;
    return 0;
}