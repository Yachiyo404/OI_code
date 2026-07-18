#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int weigh[N];
ll ans;
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weigh[i];
        pq.push(weigh[i]);
    }
    while(pq.size()>1){
        int fir=pq.top();
        pq.pop();
        int sec=pq.top();
        pq.pop();
        ans+=(fir+sec);
        pq.push(fir+sec);
    }
    cout<<ans;
    return 0;
}