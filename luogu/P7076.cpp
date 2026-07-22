#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=1e6+10;
const int INF=1e8+1;
ll n,m,c,k;
ll byte[70],ani[N];
int mem[70]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool food[INF];
struct node{
    ll num,fo;
}rul[N];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
inline void write(ll x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
inline ll bit(ll x,ll b){
	if(b>=1){
		for(ll i=0;i<=(b-1)&&x;i++){
	        ll r=x%2;
	        x-=r;
	        x/=2;
	    }
	}
    return x%2;
}
inline bool cmp(node a,node b){
    return a.num<b.num;
}
inline ll cf(ll x){
    if(mem[x]==0){
        __int128_t ac=mem[30];
        for(ll i=1;i<=x-30;i++)
            ac*=2;
        return ac;
    }
    else
        return mem[x];
}
int main(){
    read(n),read(m),read(c),read(k);
    for(ll i=1;i<=n;i++)
        read(ani[i]);
    for(ll i=1;i<=m;i++)
        read(rul[i].num),read(rul[i].fo);
    stable_sort(ani+1,ani+n+1,greater<ll>());
    stable_sort(rul+1,rul+m+1,cmp);
    ll j=0,sum=0;
    for(ll i=1;i<=n;i++){
    	j=0;
        for(;;j++){
            if(cf(j)<=ani[i]){
            	if(byte[j])
            		continue;
            	ll v=bit(ani[i],j);
                if(v)
                    byte[j]=v;
            }
            else
                break;
        }
    }
    for(ll i=1;i<=m;i++){
        if(food[rul[i].fo])
            rul[i].num=-1;
        else
            food[rul[i].fo]=1;
    }
    for(ll i=1;i<=m;i++){
        if(rul[i].num!=-1){
            if(!byte[rul[i].num]){
                byte[rul[i].num]=3;
                sum++;
            }
        }
    }
    if(k-sum==64&&n==0){
        printf("18446744073709551616");
        return 0;
    }
    ll ans=(cf(k-sum))-n;
    write(ans);
    return 0;
}