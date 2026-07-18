#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e5+5;
const double eps=1e-7;
ll n;
ll x[N],v[N];
double ans;
bool check(double t){
    double ansl=x[1]-v[1]*t,ansr=x[1]+v[1]*t;
    for(ll i=1;i<=n;i++){
        double l=x[i]-v[i]*t,r=x[i]+v[i]*t;
        if(l>ansr||r<ansl)
                return 0;
        ansl=max(ansl,l);
        ansr=min(ansr,r);
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>x[i];
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    double l=0,r=1e10;
    while((r-l)>eps){
        double mid=l+(r-l)/2.0;
        if(check(mid)){
            ans=mid;
            r=mid-eps;
        }
        else
            l=mid+eps;
    }
    cout<<fixed<<setprecision(5)<<ans<<endl;
    return 0;
}