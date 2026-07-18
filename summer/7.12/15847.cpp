#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,m;
int a[N];
ll ans=-1e10;
struct node{
    int id;
    ll data;
}sum[N];
deque<node> dq;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    m++;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i].data=sum[i-1].data+a[i];
        sum[i].id=i;
    }
    sum[0].data=0,sum[0].id=0;
    dq.push_back(sum[0]);
    for(int i=2;i<=n;i++){
        if(!dq.empty()&&sum[i].data>dq.back().data)
            dq.push_back(sum[i]);
        else{
            while(!dq.empty()&&sum[i].data<=dq.back().data)
                dq.pop_back();
            dq.push_back(sum[i]);
        }
        while(!dq.empty()&&dq.front().id<=i-m)
            dq.pop_front();
        ans=max(ans,sum[i].data-sum[dq.front().id].data);
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,(ll)a[i]);
    cout<<ans;
    return 0;
}