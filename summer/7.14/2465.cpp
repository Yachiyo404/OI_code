#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r;
ll a[20],top;
ll f[20][20];
ll dfs(ll x,ll cur,ll pre,bool lim,bool zero){    //x为位数，cur为要统计的数，pre为已统计的数目，lim为是否有限制（最高不是9），zero为是否有前导零
    if(!x)
        return f[x][pre]=pre;
    if(f[x][pre]>=0&&!lim&&!zero)
        return f[x][pre];
    ll up,res=0;
    if(lim)
        up=a[x];
    else
        up=9;
    for(int i=0;i<=up;i++){
        if(zero&&(i==0))
            res+=dfs(x-1,cur,pre,(lim&(i==a[x])),1);
        else
            res+=dfs(x-1,cur,pre+(i==cur),(lim&(i==a[x])),0);
    }
    if(lim|zero)
        return res;
    else
        return f[x][pre]=res;
}
ll work(ll num,ll k){
    memset(f,-1,sizeof(f));
    top=0;
    do{
        a[++top]=k%10;
        k/=10;
    }while(k);
    return dfs(top,num,0,1,1);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>l>>r;
    for(int i=0;i<=9;i++)
        cout<<work(i,r)-work(i,l-1)<<' ';
    return 0;
}