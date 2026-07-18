#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;
typedef long long ll;
int n,ans=inf;
int g[25][25],f[1050000][25];
void devide(int s,bool *res){
    int cnt=0;
    do{
        res[++cnt]=s%2;
        s>>=1;
    }while(s);
}
void init(){
    for(int s=0;s<=(1<<n)-1;s++){
        for(int i=1;i<=n;i++)
            f[s][i]=inf;
    }
    f[1][1]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    }
    init();
    for(int s=0;s<=(1<<n)-1;s++){
        bool u[25]={};
        devide(s,u);
        for(int i=1;i<=n;i++){
            if(u[i]&&f[s][i]!=inf){
                for(int j=1;j<=n;j++){
                    if(!u[j]&&i!=j)
                        f[s|(1<<(j-1))][j]=min(f[s|(1<<(j-1))][j],f[s][i]+g[i][j]);
                }
            }
        }
    }
    for(int i=2;i<=n;i++)
        ans=min(ans,f[(1<<n)-1][i]+g[i][1]);
    cout<<ans;
    return 0;
}