#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=410;
ll n,m,k;
ll g[N][N],num[(ll)2e5+10];
struct edge{
    ll u,v,w;
};
vector<edge> e_all,e_k;
vector<ll> ans;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        e_all.push_back({u,v,w});
    }
    sort(e_all.begin(),e_all.end(),[](edge a,edge b){return a.w<b.w;});
    for(ll i=0;i<=min(k-1,(ll)e_all.size()-1);i++)
        e_k.push_back(e_all[i]);
    // cout<<endl;
    // for(auto i:e_k)
    //     cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
    sort(e_k.begin(),e_k.end(),[](edge a,edge b){return a.u<b.u;});
    ll tmp=0;
    for(ll i=0;i<=min(k-1,(ll)e_k.size()-1);i++){
        if(!num[e_k[i].u]){
            num[e_k[i].u]=i+1-tmp;
            e_k[i].u=i+1-tmp;
        }
        else{
            e_k[i].u=num[e_k[i].u];
            tmp++;
        }
    }
    sort(e_k.begin(),e_k.end(),[](edge a,edge b){return a.v<b.v;});
    tmp=0;
    for(ll i=1;i<=2e5;i++)
        num[i]=0;
    for(ll i=0;i<=min(k-1,(ll)e_k.size()-1);i++){
        if(!num[e_k[i].v]){
            num[e_k[i].v]=i+1-tmp;
            e_k[i].v=i+1-tmp;
        }
        else{
            e_k[i].v=num[e_k[i].v];
            tmp++;
        }
    }
    sort(e_k.begin(),e_k.end(),[](edge a,edge b){return a.w<b.w;});
    // cout<<endl;
    // for(auto i:e_k)
    //     cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=k;j++){
            if(i!=j)
                g[i][j]=4e11+1;
        }
    }
    for(auto i:e_k){
        g[i.u][i.v]=i.w;
        g[i.v][i.u]=i.w;
    }
    for(ll l=1;l<=k;l++){
        for(ll i=1;i<=k;i++){
            for(ll j=1;j<=k;j++)
                g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
        }
    }
    for(ll i=1;i<=k;i++){
        for(ll j=i+1;j<=k;j++){
            ans.push_back(g[i][j]);
            // cout<<g[i][j]<<' ';
        }
        // cout<<endl;
    }
    sort(ans.begin(),ans.end());
    // for(ll i:ans)
    //     cout<<i<<' ';
    cout<<ans[k-1];
    return 0;
}