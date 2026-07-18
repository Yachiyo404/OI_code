#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,W;
int w[110],v[110],m[110];   //价值v，重量w，数量m
vector<int> new_w,new_v;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>W;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i]>>m[i];
    for(int i=1;i<=n;i++){
        int tmp=m[i];
        for(int x=1;x<=tmp;x*=2){
            new_w.push_back(w[i]*x);
            new_v.push_back(v[i]*x);
            tmp-=x;
        }
        if(tmp>0){
            new_w.push_back(w[i]*tmp);
            new_v.push_back(v[i]*tmp);
        }
    }
    vector<int> dp(W+10,0);
    for(int i=0;i<new_w.size();i++){
        for(int j=W;j>=new_w[i];j--)
            dp[j]=max(dp[j],dp[j-new_w[i]]+new_v[i]);
    }
    cout<<dp[W];
    return 0;
}