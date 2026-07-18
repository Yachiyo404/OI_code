#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T;
int main(){
    ios::sync_with_stdio(0);
    freopen("rain.in","r",stdin);
    freopen("rain.out","w",stdout);
    cin>>T;
    while(T--){
        int n,q;
        int a[N]={};
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>q;
        while(q--){
            int x,v;
            int f[N]={},g[N]={};
            cin>>x>>v;
            a[x]+=v;
            ll ans=0;
            int maxf=INT_MIN,maxg=INT_MIN;
            for(int i=1;i<=n;i++){
                maxf=max(maxf,a[i]);
                f[i]=maxf;
            }
            for(int i=n;i>=1;i--){
                maxg=max(maxg,a[i]);
                g[i]=maxg;
            }
            for(int i=1;i<=n;i++)
                ans+=min(g[i],f[i])-a[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}