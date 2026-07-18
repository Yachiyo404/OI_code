#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e4+10;
int n,s,q;
int fa[N][20],dep[N],lg2[N];
bool flag[N];
vector<int> g[N],p;
vector<pair<int,int>> tmp;
map<int,int> mp;
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for(int i=1;i<=lg2[dep[u]];i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto i:g[u]){
        if(i!=f)
            dfs(i,u);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x,y);
    for(int k=19;k>=0;k--){
        if(dep[fa[x][k]]>=dep[y])
            x=fa[x][k];
    }
    if(x==y)
        return x;
    for(int k=19;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(b==-1)
            s=a;
        else{
            p.push_back(a);
            p.push_back(b);
            tmp.push_back({a,b});
        }
    }
    sort(p.begin(),p.end());
    auto it=unique(p.begin(),p.end());
    p.erase(it,p.end());
    for(int i=0;i<p.size();i++)
        mp[p[i]]=i+1;
    for(auto i:tmp){
        g[mp[i.first]].push_back(mp[i.second]);
        g[mp[i.second]].push_back(mp[i.first]);
    }
    lg2[1]=0;
    for(int i=2;i<=N;i++)
        lg2[i]=lg2[i>>1]+1;
    dfs(mp[s],0);
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        x=mp[x];
        y=mp[y];
        int ans=lca(x,y);
        if(x==ans)
            cout<<1<<'\n';
        else if(y==ans)
            cout<<2<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}