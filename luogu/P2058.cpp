#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+10;
ll n,ans;
ll sign[N];
struct s{
    ll tim,peo;
};
queue<s> q;
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
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main(){
    read(n);
    for(ll i=1;i<=n;i++){
        ll t,k;
        read(t),read(k);
        for(ll j=1;j<=k;j++){
            ll a;
            read(a);
            q.push((s){t,a});
            if(!sign[a])
                ans++;
            sign[a]++;
        }
        while(q.size()&&t-q.front().tim>=86400){
            sign[q.front().peo]--;
            if(!sign[q.front().peo])
                ans--;
            q.pop();
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}