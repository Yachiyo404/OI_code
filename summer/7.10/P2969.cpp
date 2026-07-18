#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
int arr[50005],sum[50005],ans[50005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        int a=lower_bound(sum+1,sum+n+1,t)-sum;
        ans[i]=a;
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}