#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,m,Max;
bool flag;
bool vis[N];
struct node{
    ll st,ed;
};
vector<ll> e[N];
vector<node> g;
inline ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
inline void write(int x) {
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
inline void dfs(ll x){
    vis[x]=1;
    ll size=e[x].size();
    for(ll i=0;i<size;i++){
        ll point=g[e[x][i]].ed;
        if(!vis[point]){
            Max=max(Max,point);
            if(Max==n){
                flag=1;
                break;
            }
            dfs(point);
        }
        else{
            if(i==size-1)
                flag=1;
            else
                continue;
        }
    }
    if(flag)
        return;
    else if(size==0){
    	flag=1;
    	return;
	}
}
int main(){
    n=read(),m=read();
    for(ll i=1;i<=m;i++){
        ll a=read(),b=read();
        g.emplace_back((node){a,b});
    }
    for(ll i=0;i<m;i++)
        e[g[i].st].emplace_back(i);
    for(ll i=1;i<=n;i++){
        Max=i;
        dfs(i);
        write(Max);
        cout<<" ";
        memset(vis,0,sizeof(vis));
    }
    return 0;
}