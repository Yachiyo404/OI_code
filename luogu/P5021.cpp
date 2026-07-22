#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=50005;
int n,m,a[N],l[N];
int val,cnt;
vector<int> G[N];
int k,q[N],dp[N];
inline int calc(int p){
    int l=1,r=k-1,ans=0;
    while(l<r){
        if(l==p) 
            l++;
        if(r==p) 
            r--;
        if(l>=r) 
            break;
        if(q[l]+q[r]>=val){
            l++,r--;
            ans++;
        }
        else 
            l++;
    }
    return ans;
}
inline void DFS(int x,int fa)
{
    for(int i:G[x])
    {
        int y=a[i]^x;
        if(y==fa)
            continue;
        DFS(y,x);
    }
    k=1;
    for(int i:G[x])
    {
        int y=a[i]^x;
        if(y==fa)
            continue;
        q[k]=dp[y]+l[i];
        if(q[k]>=val)
            cnt++;
        else 
            k++;
    }
    
    sort(q+1,q+k);
    int tmp=calc(0);
    if(2*tmp==k-1){
        cnt+=tmp,dp[x]=0;
        return;
    }
    int l=1,r=k-1;
    while(l<r){
        int p=(l+r+1)/2;
        if(calc(p)>=tmp)
            l=p;
        else 
            r=p-1;
    }
    cnt+=tmp,dp[x]=q[l];
}
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y>>l[i];
        a[i]=x^y;
        G[x].push_back(i);
        G[y].push_back(i);
    }
    int l=0,r=5e8;
    while(l<r){
        val=(l+r+1)/2;
        cnt=0;DFS(1,0);
        if(cnt>=m) 
            l=val;
        else 
            r=val-1;
    }
    cout<<l;
}