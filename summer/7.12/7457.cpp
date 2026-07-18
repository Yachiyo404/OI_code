#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int a[N],b[N];
struct node{
    int aid,bid;
    ll data;
    bool operator <(const node &other) const{
        return data>other.data;
    }
};
priority_queue<node> pq;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        pq.push((node){i,1,a[i]+b[1]});
    for(int i=1;i<=n;i++){
        auto mi=pq.top();
        cout<<mi.data<<' ';
        pq.pop();
        pq.push((node){mi.aid,mi.bid+1,a[mi.aid]+b[mi.bid+1]});
    }
    return 0;
}