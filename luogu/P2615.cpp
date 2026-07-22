#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6;
ll n;
ll square[1000][1000],h[N],l[N];
int main(){
    scanf("%lld",&n);
    square[1][(n+1)/2]=1;
    h[1]=1;
    l[1]=(n+1)/2;
    for(ll i=2;i<=n*n;i++){
        if(h[i-1]==1&&l[i-1]!=n){
            h[i]=n;
            l[i]=l[i-1]+1;
            square[h[i]][l[i]]=i;
        }
        else if(l[i-1]==n&&h[i-1]!=1){
            l[i]=1;
            h[i]=h[i-1]-1;
            square[h[i]][l[i]]=i;
        }
        else if(h[i-1]==1&&l[i-1]==n){
            l[i]=l[i-1];
            h[i]=h[i-1]+1;
            square[h[i]][l[i]]=i;
        }
        else if(h[i-1]!=1&&l[i-1]!=n){
            if(!square[h[i-1]-1][l[i-1]+1]){
                h[i]=h[i-1]-1;
                l[i]=l[i-1]+1;
                square[h[i]][l[i]]=i;
            }
            else{
                h[i]=h[i-1]+1;
                l[i]=l[i-1];
                square[h[i]][l[i]]=i;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)
            printf("%lld ",square[i][j]);
        printf("\n");
    }
    return 0;
}