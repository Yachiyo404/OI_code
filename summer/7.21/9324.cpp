#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
int n,m,p;
int fa[N];
int find(int x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    if(find(x)==find(y))
        return;
    fa[find(x)]=find(y);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    for(int i=1;i<=p;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b))
            cout<<"Yes"<<'\n';
        else
            cout<<"No"<<'\n';
    }
    return 0;
}