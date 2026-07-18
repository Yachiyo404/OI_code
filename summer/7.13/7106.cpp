#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,vmax=INT_MIN,ans=INT_MAX;
int v[105],c[105];
vector<int> new_v,new_c;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        vmax=max(vmax,v[i]);
    }
    for(int i=1;i<=n;i++)   
        cin>>c[i];
    for(int i=1;i<=n;i++){
        int cnt=c[i];
        for(int x=1;x<=cnt;x*=2){
            new_v.push_back(x*v[i]);
            new_c.push_back(x*c[i]);
            cnt-=x;
        }
        if(cnt>0){
            new_v.push_back(cnt*v[i]);
            new_c.push_back(cnt*c[i]);
        }
    }
    int maxpaid=t+vmax*vmax;
    int maxret=vmax*vmax;
    vector<int> dp1(maxpaid,INT_MAX),dp2(maxret,INT_MAX);
    for(int i=0;i<new_v.size();i++){
        for(int j=maxpaid;j>=new_v[i];j--)
            dp1[j]=min(dp1[j],dp1[j-new_v[i]]+new_c[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=maxret;j++)
            dp2[j]=min(dp2[j],dp2[j-v[i]]+1);
    }
    for(int ret=0;ret<=vmax*vmax;ret++){
        int paid=ret+t;
        
    }
    if(ans==INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}