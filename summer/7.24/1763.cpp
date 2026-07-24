#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e2+10;
int n,ans,cnt;
int fa[N],p_w[N];
struct edge{
    int u,v,w;
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
    for(int i=1;i<=n;i++){
        cin>>p_w[i];
        e.push_back({0,i,p_w[i]});
        e.push_back({i,0,p_w[i]});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            if(i!=j){
                e.push_back({i,j,w});
                e.push_back({j,i,w});
            }
        }
    }
    sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
    for(auto i:e){
        int u=i.u,v=i.v,w=i.w;
        u=find(u),v=find(v);
        if(u==v)
            continue;
        merge(u,v);
        ans+=w;
        cnt++;
        if(cnt==n)
            break;
    }
    cout<<ans;
    return 0;
}