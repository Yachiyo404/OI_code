#include<bits/stdc++.h>
#define ll long long
#define up(a,b) for(ll i=a;i<=b;i++)
#define down(a,b) for(ll i=a;i>=b;i--)
using namespace std;
const ll N=1e5+10;
ll n,m,step,j=1;
bool a;
struct toy{
    ll sign;
    bool face;
    string c;
}peo[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    up(1,n){
        cin>>peo[i].face;
        cin>>peo[i].c;
        peo[i].sign=i;
    }
    up(1,m){
        cin>>a>>step;
        ll st=j;
        if(peo[st].face){
            if(a){
                if(j-step<1){
                    step-=j;
                    j=n-step;
                }
                else
                    j-=step;
            }
            else{
                if(j+step>n){
                    step-=(n-j);
                    j=step;
                }
                else
                    j+=step;
            }
        }
        else{
            if(a){
                if(j+step>n){
                    step-=(n-j);
                    j=step;
                }
                else
                    j+=step;
            }
            else{
                if(j-step<1){
                    step-=j;
                    j=n-step;
                }
                else
                    j-=step;
            }
        }
    }
    cout<<peo[j].c;
    return 0;
}