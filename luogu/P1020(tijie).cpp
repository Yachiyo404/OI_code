/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll a,b,len;
ll num[N],f[N];
int main(){
    ios::sync_with_stdio(0);
    while(cin>>a)
        num[++b]=a;
    len=0;
    reverse(num+1,num+b+1);
    //memset(f,-1,sizeof(f));
    f[0]=-1;
    for(ll i=1;i<=b;i++){
        int l=0,r=len,mid;
        if(f[len]<=num[i])
            f[++len]=num[i];
        else{
            while(l<r){
                mid=(l+r)/2;
                if(f[mid]<=num[i])
                    r=mid;
                else 
                    l=mid+1;
            }
            f[l]=min(f[l],num[i]);
        }
    }
    cout<<len<<endl<<2;
    return 0;
}*/
#include<bits/stdc++.h>
#define int long long 
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
const int INF =2147483647;
const int MAXN=1e5+3;
int n,t,H[MAXN],F[MAXN];
signed main(){
    while(~scanf("%d",&H[++n])); 
        --n;
    t=0;
    memset(F,0,sizeof(F));
    F[0]=INF;
    up(1,n,i){
        int l=0,r=t+1; 
        while(r-l>1){
            int m=l+(r-l)/2;
            if(F[m]>=H[i]) 
                l=m; 
            else 
                r=m;
        }
        int x=l+1;
        if(x>t) 
            t=x; 
        F[x]=H[i];
    }
    printf("%d\n",t);
    t=0;
    memset(F,0,sizeof(F));
    F[0]=0;
    up(1,n,i){
        int l=0,r=t+1; 
        while(r-l>1){
            int m=l+(r-l)/2;
            if(F[m]<H[i]) 
                l=m; 
            else 
                r=m;
        }
        int x=l+1;
        if(x>t) 
            t=x; 
        F[x]=H[i];
    }
    printf("%d\n",t);
    return 0;
}