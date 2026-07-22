#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll kmp[N];
ll len_a,len_b,j;
char a[N],b[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>a+1>>b+1;
    len_a=strlen(a+1);
    len_b=strlen(b+1);
    up(i,2,len_b){
        while(j&&b[i]!=b[j+1])
            j=kmp[j];
        if(b[j+1]==b[i])
            j++;
        kmp[i]=j;
    }
    j=0;
    up(i,1,len_a){
        while(j>0&&b[j+1]!=a[i])
            j=kmp[j];
        if(b[j+1]==a[i])
            j++;
        if(j==len_b){
            printf("%lld\n",i-len_b+1);
            j=kmp[j];
        }
    }
    up(i,1,len_b)
        printf("%lld ",kmp[i]);
    return 0;
}