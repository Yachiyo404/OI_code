#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int a[N],low[N],p[N],ans[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    ll len=0;
    for(int i=1;i<=n;i++){
        ll l=1,r=len,pos=len+1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(low[mid]>=a[i]){
                pos=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(pos==len+1){
            len++;
            low[len]=a[i];
            p[i]=len;
        }
        else
            low[pos]=a[i];
    }
    for(int i=n-1;i>=1;i--){
        
    }
    return 0;
}