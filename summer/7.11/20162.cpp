#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
int n,k;
int size[N];
ll ans;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>size[i];
    sort(size+1,size+n+1);
    for(int i=1;i<=n;i++){
        ll cnt1=0,cnt2=0;
        for(int j=i-1;j>=1;j--){
            if(size[i]-size[j]<=k)
                cnt1++;
            else
                break;
        }
        for(int j=i+1;j<=n;j++){
            if(size[j]-size[i+1]<=k)
                cnt2++;
            else
                break;
        }
        ans=max(ans,cnt1+cnt2+1);
    }
    cout<<ans;
    return 0;
}