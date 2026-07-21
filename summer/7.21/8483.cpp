#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m;
int fa[N];
bool vis[N];
pair<int,int> pos[N];
struct node{
    int x1,y1,x2,y2;
}fp[N];
int find(int x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    fa[x]=y;
    fp[y].x1=min(fp[y].x1,fp[x].x1);
    fp[y].y1=min(fp[y].y1,fp[x].y1);
    fp[y].x2=max(fp[y].x2,fp[x].x2);
    fp[y].y2=max(fp[y].y2,fp[x].y2);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>pos[i].first>>pos[i].second;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        fp[i].x1=fp[i].x2=pos[i].first;
        fp[i].y1=fp[i].y2=pos[i].second;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    ll ans=LLONG_MAX;
    for(int i=1;i<=n;i++){
        if(!vis[find(i)]){
            ans=min(ans,(fp[find(i)].x2-fp[find(i)].x1+fp[find(i)].y2-fp[find(i)].y1)*2ll);
            vis[find(i)]=1;
        }
    }
    cout<<ans;
    return 0;
}