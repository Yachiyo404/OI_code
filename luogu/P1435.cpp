#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char str1[1010],str2[1010];
ll dp[1010][1010];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
int main(){
    ios::sync_with_stdio(0);
    scanf("%s",str1+1);
    ll len=strlen(str1+1);
    for(ll i=1;i<=len;i++)
        str2[len-i+1]=str1[i];
    for(ll i=1;i<=len;i++){
        for(ll j=1;j<=len;j++){
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<len-dp[len][len];
    return 0;
}