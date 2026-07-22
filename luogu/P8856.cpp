#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e4+10;
ll c,s,r;
ll pas[N];
bool flag;
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
int main(){
    read(c),read(s),read(r);
    for(ll i=1;i<c;i++)
        pas[i]=s;
    for(ll i=1;i<=r;i++){
        ll u,v,sum;
        flag=0;
        read(u),read(v),read(sum);
        for(ll j=u;j<v;j++){
            if(pas[j]>=sum)
                pas[j]-=sum;
            else{
                flag=1;
                for(ll k=j-1;k>=u;k--)
                    pas[k]+=sum;
                break;
            }
        }
        if(!flag)
            puts("T");
        else
            puts("N");
    }
    return 0;
}