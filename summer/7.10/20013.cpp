#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,w[N],v[N],l[N],r[N];
ll s,pre_cnt[N],pre_val[N];
ll calc(int W){
    for(int i=1;i<=n;i++){
        pre_cnt[i]=pre_cnt[i-1]+(w[i]>=W);
        pre_val[i]=pre_val[i-1]+(w[i]>=W?v[i]:0);
    }
    ll y=0;
    for(int i=1;i<=m;i++){
        int L=l[i],R=r[i];
        ll cnt=pre_cnt[R]-pre_cnt[L-1];
        ll val=pre_val[R]-pre_val[L-1];
        y+=cnt*val;
    }
    return y;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>s;
    int max_w=0;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i]; 
        max_w=max(max_w,w[i]);
    }
    for(int i=1;i<=m;i++) 
        cin>>l[i]>>r[i];
    int L=0,R=max_w+1;
    while(L<R){
        int mid=(L+R)>>1;
        ll y=calc(mid);
        if(y>s) 
            L=mid+1;
        else
            R=mid;
    }
    ll ans=abs(s-calc(L));
    if(L>0) 
        ans=min(ans,abs(s-calc(L-1)));
    cout<<ans<<"\n";
    return 0;
}