#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+10;
int n;
ll a[N];
ll sum,x,y,cnt;
int main(){
    ios::sync_with_stdio(0);
    // freopen("202501D.in","r",stdin);
    // freopen("202501D.out","w",stdout);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ll pos1=lower_bound(a+1+i,a+n+1,sum-y-a[i])-a;
        ll pos2=upper_bound(a+1+i,a+n+1,sum-x-a[i])-a-1;
        if(sum-y-a[i]<=a[pos1]&&a[pos2]<=sum-x-a[i])
            cnt+=pos2-pos1+1;
    }
    cout<<cnt;
    return 0;
}