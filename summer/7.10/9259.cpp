#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,k,Max;
int len[N];
ll sum;
bool check(int x){
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=(len[i]-len[i]%x)/x;
    if(cnt>=k)
        return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>len[i];
        sum+=len[i];
        Max=max(Max,len[i]);
    }
    if(sum<k){
        cout<<0;
        return 0;
    }
    int l=1,r=Max,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}