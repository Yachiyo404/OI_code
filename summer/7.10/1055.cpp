#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
int high[N],low[N];
multiset<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>high[i];
    ll len=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=len,pos=len+1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(low[mid]<high[i]){
                pos=mid;
                r=mid-1;
            } 
            else 
                l=mid+1;
        }
        if(pos==len+1){
            len++;
            low[len]=high[i];
        }
        else
            low[pos]=high[i];
    }
    cout<<len<<' ';
    int cnt=1;
    s.insert(high[1]);
    for(int i=2;i<=n;i++){
        if(*s.rbegin()<high[i]){
            cnt++;
            s.insert(high[i]);
        }
        else{
            auto it=s.lower_bound(high[i]);
            if(it!=s.end()){
                s.erase(it);
                s.insert(high[i]);
            }
        }
    }
    cout<<cnt;
    return 0;
}