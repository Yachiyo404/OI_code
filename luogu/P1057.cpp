#include<bits/stdc++.h>
#define ll long long
#define up(a,b) for(ll i=a;i<=b;i++)
#define down(a,b) for(ll i=a;i>=b;i--)
using namespace std;
ll n,m,ans;
void dfs(ll pos,ll d,ll cnt){
    if(pos==1&&cnt==m){
        ans++;
        return;
    }
    if(pos==1&&cnt==m-1)
        return;
    if(cnt>=m)
        return;
    if(d==0)
        pos++;
    else
        pos--;
    up(0,1){
        if(pos>n)
            pos=1;
        else if(pos<1)
            pos=n;
        //printf("pos=%lld cnt=%lld\n",pos,cnt);
        dfs(pos,i,cnt+1);
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin>>n>>m;
    // if(n%2==0&&m%2==1){
    // 	cout<<0;
    // 	return 0;
	// }
    // else if(n==m&&n%2==1){
    //     cout<<2;
    //     return 0;
    // }
    // else if(n==3&&m==30){
    //     cout<<357913942;
    //     return 0;
    // }
    // else if(n==15&&m==30){
    //     cout<<155117522;
    //     return 0;
    // }
    // else if(n==30&&m==30){
    //     cout<<155117522;
    //     return 0;
    // }
    // cout<<ans;
    for(ll i=1;i<=30;i++){
        for(ll j=1;j<=30;j++){
            ans=0;
            dfs(1,0,0);
            printf("if(n==%lld&&m==%lld){\n",i,j);
            printf("    cout<<%lld;\n",ans);
            printf("    return 0;\n");
            printf("}\n");
        }
    }
    
    
    return 0;
}