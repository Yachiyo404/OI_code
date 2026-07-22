#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,m;
bool vis1[N],vis2[N];
struct node{
    ll st,ed;
};
vector<ll> edge[N];
vector<node> g;
inline bool cmp(node x,node y){
	if(x.ed==y.ed)
	    return x.st<y.st;
	else 
        return x.ed<y.ed;
}
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void dfs(ll pos){
    vis1[pos]=1;
    cout<<pos<<" ";
    for(ll i=0;i<edge[pos].size();i++){
        ll point=g[edge[pos][i]].ed;
        if(!vis1[point])
            dfs(point);
    }
}
inline void bfs(ll pos){
    queue<ll> q;
    q.push(pos);
    cout<<pos<<" ";
    vis2[pos]=1;
    while(!q.empty()){
        ll f=q.front();
        for(ll i=0;i<edge[f].size();i++){
            ll point=g[edge[f][i]].ed;
            if(!vis2[point]){
                q.push(point);
                cout<<point<<" ";
                vis2[point]=1;
            }
        }
        q.pop();
    }
}
int main(){
    n=read(),m=read();
    for(ll i=0;i<m;i++){
        ll a=read(),b=read();
        g.push_back((node){a,b});
    }
    sort(g.begin(),g.end(),cmp);
    for(ll i=0;i<m;i++)
        edge[g[i].st].push_back(i);
    dfs(1);
    cout<<"\n";
    bfs(1);
    return 0;
}