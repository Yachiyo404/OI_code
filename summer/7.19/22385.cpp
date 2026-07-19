#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
int n;
int g[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            g[i][j]=1e6;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    }
    for(int k=n;k>=1;k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
    }
    
    return 0;
}