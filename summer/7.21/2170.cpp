#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4+10;
int t;
int fa[N],fro[N],sum[N];
int find(int x){
    if(fa[x]==x)
        return x;
    else{
        int f=find(fa[x]);
        fro[x]+=fro[fa[x]];
        return fa[x]=f;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    for(int i=1;i<=N-1;i++){
        fa[i]=i;
        fro[i]=0;
        sum[i]=1;
    }
    for(int i=1;i<=t;i++){
        char op;
        int x,y;
        cin>>op>>x>>y;
        int fx=find(x),fy=find(y);
        if(op=='M'){
            if(fx==fy)
                continue;
            fro[fx]+=sum[fy];
            fa[fx]=fy;
            sum[fy]+=sum[fx];
            sum[fx]=0;
        }
        else{
            if(fx!=fy)
                cout<<"-1"<<endl;
            else
                cout<<abs(fro[x]-fro[y])-1<<endl;
        }
    }
    return 0;
}