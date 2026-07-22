#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
ll T,M;
bool is_prime[(int)1e7];
vector<ll> prime;
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
inline void pri(ll n){
    up(i,2,n)
        is_prime[i]=1;
    up(i,2,n){
        if(is_prime[i]){
            prime.push_back(i);
            if(i*i>n)
                continue;
            for(ll j=i*i;j<=n;j+=i)
                is_prime[j]=0;
        }
    }
}
inline ll gcd(ll a,ll b){
    a=abs(a);
    b=abs(b);
    ll r;
    while(a%b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}
int main(){
    read(T),read(M);
    pri(M+10);
    while(T--){
        ll a,b,c,q2=1;
        read(a),read(b),read(c);
        ll d=b*b-4*a*c;
        if(d<0){
            puts("NO");
            continue;
        }
        a*=2;
        ll tmpa=a;
        if(floor(sqrt(d))==ceil(sqrt(d))){
            if(a>0){
                ll ma=-b+sqrt(d);
                if(ma!=0){
                    if(ma*a<0)
                        putchar('-');
                    ma=abs(ma);
                    a=abs(a);
                    ll tmp=gcd(ma,a);
                    if(tmp!=1){
                        ma/=tmp;
                        a/=tmp;
                    }
                    if(a!=1)
                        printf("%lld/%lld\n",ma,a);
                    else
                        printf("%lld\n",ma);
                }
                else
                    puts("0");
            }
            else{
                ll ma=-b-sqrt(d);
                if(ma!=0){
                    if(ma*a<0)
                        putchar('-');
                    ma=abs(ma);
                    a=abs(a);
                    ll tmp=gcd(ma,a);
                    if(tmp!=1){
                        ma/=tmp;
                        a/=tmp;
                    }
                    if(a!=1)
                        printf("%lld/%lld\n",ma,a);
                    else
                        printf("%lld\n",ma);
                }
                else
                    puts("0");
            }
            continue;
        }
        else{
            ll g;
            if(b!=0){
                g=gcd(a,b);
                if(-b*a<0)
                    putchar('-');
                b=abs(b);
                a=abs(a);
                if(g!=1){
                    a/=g;
                    b/=g;
                }
                if(a!=1)
                    printf("%lld/%lld+",b,a);
                else
                    printf("%lld+",b);
            }
            for(auto k:prime){
                while(d%(k*k)==0){
                    q2*=k;
                    d/=(k*k);
                }
                if(d<k*k)
                    break;
            }
            tmpa=abs(tmpa);
            if(q2==1){
                if(tmpa!=1)
                    printf("sqrt(%lld)/%lld\n",d,tmpa);
                else
                    printf("sqrt(%lld)\n",d);
            }
            else{
                g=gcd(q2,tmpa);
                if(g!=1){
                    q2/=g;
                    tmpa/=g;
                }
                if(q2==1&&tmpa!=1)
                    printf("sqrt(%lld)/%lld\n",d,tmpa);
                else if(q2!=1&&tmpa==1)
                    printf("%lld*sqrt(%lld)\n",q2,d);
                else if(q2!=1&&tmpa!=1)
                    printf("%lld*sqrt(%lld)/%lld\n",q2,d,tmpa);
                else
                    printf("sqrt(%lld)\n",d);
            }
        }
    }
    return 0;
}