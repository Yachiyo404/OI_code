#include<bits/stdc++.h>
using namespace std;
typedef __int128_t int128;
typedef long long ll;
const int N=1e5+10;
ll n,m;
ll in[N],out[N];
int128 cntm[N],cnts[N];
vector<ll> g[N];
queue<ll> q;
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
inline void print(int128 a){
    if(a>9)
        print(a/10);
    putchar(a%10+'0');
}
inline int128 gcd(int128 a,int128 b){
    while(b){
        int128 t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main(){
    read(n),read(m);
    for(ll i=1;i<=n;i++){
        cnts[i]=0;
        cntm[i]=1;
        in[i]=0;
    }
    for(ll i=1;i<=n;i++){
        ll num,b;
        read(num);
        out[i]=num;
        for(ll j=1;j<=num;j++){
            read(b);
            in[b]++;
            g[i].push_back(b);
        }
    }
    for(ll i=1;i<=m;i++){
        q.push(i);
        cnts[i]=1;
        cntm[i]=1;
    }
    while(!q.empty()){
        ll now=q.front(); q.pop();
        ll d=g[now].size();
        if(d==0) 
            continue;
        int128 sn=cnts[now];
        int128 mn=cntm[now];
        int128 add_s=sn;
        int128 add_m=mn*d;
        int128 g1=gcd(add_s,add_m);
        add_s/=g1;
        add_m/=g1;
        for(ll next : g[now]){
            int128 ns=cnts[next];
            int128 nm=cntm[next];
            int128 new_ns = ns*add_m + add_s*nm;
            int128 new_nm = nm*add_m;
            int128 g2=gcd(new_ns,new_nm);
            cnts[next]=new_ns/g2;
            cntm[next]=new_nm/g2;
            if(--in[next]==0)
                q.push(next);
        }
    }
    for(ll i=1;i<=n;i++){
        if(g[i].empty()){
            print(cnts[i]);
            putchar(' ');
            print(cntm[i]);
            putchar('\n');
        }
    }
    return 0;
}