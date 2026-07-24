#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,ans,n_cnt;
ll fa[110];
struct edge{
    ll u,v,w;
};
vector<edge> e;
void init(){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
ll find(ll x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
    x=find(x),y=find(y);
    fa[x]=y;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    init();
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll w;
            cin>>w;
            if(i!=j){
                if(!w){
                    if(find(i)!=find(j)){
                        merge(i,j);
                        cnt++;
                    }
                }
                else{
                    e.push_back({i,j,w});
                    e.push_back({j,i,w});
                }
            }
        }
    }
    sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
    for(auto i:e){
        ll u=i.u,v=i.v,w=i.w;
        u=find(u),v=find(v);
        if(u==v)
            continue;
        merge(u,v);
        ans+=w;
        cnt++;
        n_cnt++;
        if(cnt==n-1)
            break;
    }
    cout<<n_cnt<<'\n'<<ans;
    return 0;
}