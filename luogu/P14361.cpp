#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=gc();
    }
    return x*f;
}
inline void write(ll a){
    if(a<0){
        pc('-');
        a=-a;
    }
    if(a>9)
        write(a/10);
    pc(a%10+'0');
}
const int N=1e5+10;
ll T;
struct node{
    ll a,b,c;
};
ll b[N];
vector<node> peo;
vector<ll> ans;
int main(){
    T=read();
    while(T--){
        ll n=read(),sum=0,cnt1=0,cnt2=0,cnt3=0;
        memset(b,0,sizeof(b));
        peo.clear();
        ans.clear();
        up(i,1,n){
            ll a=read(),b=read(),c=read();
            peo.emplace_back((node){a,b,c});
        }
        up(i,0,n-1){
            if(peo[i].a>=max(peo[i].b,peo[i].c))
                b[i]=1,sum+=peo[i].a,cnt1++;
            else if(peo[i].b>=max(peo[i].a,peo[i].c))
                b[i]=2,sum+=peo[i].b,cnt2++;
            else if(peo[i].c>=max(peo[i].a,peo[i].b))
                b[i]=3,sum+=peo[i].c,cnt3++;
        }
        up(i,0,n-1){
            if(cnt1>n/2&&b[i]==1)
                ans.emplace_back(peo[i].a-max(peo[i].b,peo[i].c));
            else if(cnt2>n/2&&b[i]==2)
                ans.emplace_back(peo[i].b-max(peo[i].a,peo[i].c));
            else if(cnt3>n/2&&b[i]==3)
                ans.emplace_back(peo[i].c-max(peo[i].a,peo[i].b));
        }
        sort(ans.begin(),ans.end());
        ll j=0;
        while(cnt1>n/2){
            sum-=ans[j];
            cnt1--;
            j++;
        }
        while(cnt2>n/2){
            sum-=ans[j];
            cnt2--;
            j++;
        }
        while(cnt3>n/2){
            sum-=ans[j];
            cnt3--;
            j++;
        }
        write(sum);
        pc('\n');
    }
    return 0;
}