#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+10,mod=998244353;
ll T,n,m,k,x,sum;
ll in[N],out[N];
bool vis[N];
vector<int> g[N];
ll fastpow(ll a,ll b,ll p){
    if(b==0)
        return 1;
    if(b==1)
        return a%p;
    ll ans=fastpow(a,b/2,p);
    if(b%2==1)
        return (ans%p*ans%p)*a%p;
    else
        return ans%p*ans%p;
}
int main(){
    ios::sync_with_stdio(0);
    // freopen("forest.in","r",stdin);
    // freopen("forest.out","w",stdout);
    cin>>T;
    while(T--){
        ll ans=LLONG_MIN;
        cin>>n>>m>>k>>x;
        for(auto &i:g)
            i.clear();
        fill(vis+1,vis+n+1,0);
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            in[u]++,in[v]++;
            out[u]++,out[v]++;
        }
        
    }
    return 0;
}