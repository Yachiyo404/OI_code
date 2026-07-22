#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,a;
priority_queue<ll> big;
priority_queue<ll> small;
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        ll b;
        scanf("%lld",&a);
        if(i==1){
            small.push(-1*a);
            printf("%lld\n",a);
            continue;
        }
        if(i>1&&i%2==0){
            b=-1*small.top();
            if(a<=b)
                big.push(a);
            else{
                small.pop();
                small.push(-1*a);
                big.push(b);
            }
        }
        if(i>1&&i%2==1){
            b=big.top();
            if(a>=b)
                small.push(-1*a);
            else{
                big.pop();
                big.push(a);
                small.push(-1*b);
            }
            printf("%lld\n",-1*small.top());
        }
    }
       
    
    return 0;
}