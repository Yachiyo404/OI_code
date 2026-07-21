#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,m;
ll ans;
int fa[N*2];
int find(int x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    if(x<y)
        swap(x,y);
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    fa[x]=y;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
        fa[i]=i;
    while(m--){
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='F')
            merge(x,y);
        else{
            merge(x,y+n);
            merge(x+n,y);
        }
    }
    for(int i=1;i<=n;i++){
        if(fa[i]==i)
            ans++;
    }
    cout<<ans;
    return 0;
}