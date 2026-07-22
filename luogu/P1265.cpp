#include<bits/stdc++.h>
#define ll double
using namespace std;
const double inf=1e15+10;
const int N=5e3+10;
ll n;
ll dis[N],x[N],y[N],vis[N],ans;
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
inline ll len(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
inline void prim(){
    vis[1]=1;
    dis[1]=0.0;
    int pos;
    ll minn;
    for(int i=1;i<=n;i++){
        pos=1;
        minn=inf;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<minn)
                minn=dis[j],pos=j;
        }
        vis[pos]=1;
        ans+=dis[pos];
        for(int p=1;p<=n;p++)
            dis[p]=min(dis[p],len(x[pos],y[pos],x[p],y[p]));
    }
    printf("%.2lf",ans);
    return;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
        y[i]=read();
        dis[i]=inf;
    }
    prim();
    return 0;
}