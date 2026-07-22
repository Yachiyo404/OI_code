#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=1e7+1010;
ll T,num,N,ls;
ll ans[INF],nex[INF];
deque<ll> ask;
inline void read(ll &a){
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
    a=x*f;
}
inline void write(ll x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main(){
    read(T);
    while(T--){
        read(num);
        if(N<num)
            N=num;
        ask.push_back(num);
    }
    N=min((int)(N+1e4),INF-1);
    for(ll i=1;i<=N;i++){
        ll num=i,j=1;
        bool flag=0;
        if(ans[num])
            continue;
        while(num){
            ll c=num%10;
            num/=10;
            if(c==7){
                flag=1;
                break;
            }
        }
        if(flag){
            while(i*j<=N){
                ans[i*j]=1;
                j++;
            }
            continue;
        }
        nex[ls]=i;
        ls=i;
    }
    while(ask.size()){
        ll c=ask.front();
        ask.pop_front();
        if(ans[c]==1){
            putchar('-');
            putchar('1');
            putchar('\n');
        }
        else{
            write(nex[c]);
            putchar('\n');
        }
    }
    return 0;
}