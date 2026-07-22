#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
deque<ll> dq1,dq2;
inline ll solve(deque<ll> &dq){
    ll ans=0;
    while(dq.size()){
        if(dq.front()==1){
            ans++;
            dq.pop_front();
            dq.push_front(0);
        }
        else{
            while(dq.size()&&dq.back()==0)
                dq.pop_back();
            if(dq.empty())
                break;
            ans+=dq.size();
            dq.pop_back();
            if(dq.size())
                dq.pop_front();
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    ll T;
    cin>>T;    
    while(T--){
        ll n;
        cin>>n;
        up(i,1,n){
            char ch;
            cin>>ch;
            dq1.push_back(ch-'0');
            dq2.push_back(1^(ch-'0'));
        }
        cout<<min(solve(dq1),solve(dq2))<<endl;
    }
    return 0;
}