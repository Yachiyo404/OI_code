#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int dp[210];
struct node{
    int w,v,p;//重量，价值，数量
};
vector<node> zero_one,full,multi,lst;
int main(){
    ios::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        int w,c,p;
        cin>>w>>c>>p;
        if(p==1)
            zero_one.push_back({w,c,p});
        else if(p==0)
            full.push_back({w,c,p});
        else
            multi.push_back({w,c,p});
    }
    for(auto i:multi){
        int cnt=i.p;
        for(int x=1;x<=cnt;x*=2){
            zero_one.push_back({x*i.w,x*i.v,1});
            cnt-=x;
        }
        if(cnt>0)
            zero_one.push_back({cnt*i.w,cnt*i.v,1});
    }
    for(auto i:zero_one)
        lst.push_back(i);
    for(auto i:full)
        lst.push_back(i);
    for(int i=0;i<lst.size();i++){
        if(lst[i].p==1){
            for(int j=m;j>=lst[i].w;j--)
                dp[j]=max(dp[j],dp[j-lst[i].w]+lst[i].v);
        }
        else{
            for(int j=lst[i].w;j<=m;j++)
                dp[j]=max(dp[j],dp[j-lst[i].w]+lst[i].v);
        }
    }
    cout<<dp[m];
    return 0;
}