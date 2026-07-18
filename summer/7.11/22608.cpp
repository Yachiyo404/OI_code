#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int n,m;
int a[N],cnt[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=1,r=1,d=0,len=n+1;
    int x=1,y=n;
    while(r<=n){
        if(!cnt[a[r]])
            d++;
        cnt[a[r]]++;
        while(d==m){
            if(r-l+1<len){
                x=l;
                y=r;
                len=r-l+1;
            }
            cnt[a[l]]--;
            if(!cnt[a[l]])
                d--;
            l++;
        }
        r++;
    }
    cout<<x<<' '<<y;
    return 0;
}