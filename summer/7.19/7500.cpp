#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,inf=INT_MAX;
int n;
int g[N][N],f[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>f[i][j];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i][i]<0){
            cout<<"No Solution";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<f[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}