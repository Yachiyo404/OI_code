#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll num[50],dp[50][10];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        char ch;
        cin>>ch;
        num[i]=int(ch-'0');
    }
    
    return 0;
}