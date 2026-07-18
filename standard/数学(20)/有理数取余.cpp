#include<bits/stdc++.h>
#define int long long
#define mod 19260817
using namespace std;
int read()
{
    int x=0;
	char ch=getchar();
    while(!isdigit(ch)&&ch!=EOF)
        ch=getchar();
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+(ch-'0');
        x%=mod;
        ch=getchar();
    }
    return x;
}
int x,y;
void exgcd(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return ;
    }
    exgcd(b,a%b);
    int xx=x;
    x=y;
    y=xx-a/b*y;
    return ;
}
signed main()
{
	int a=read(),b=read();
    if(b==0)
    {
        cout<<"Angry!";
        return 0;
    }
    exgcd(b,mod);
    x=(x%mod+mod)%mod;
    cout<<a*x%mod;
    return 0;
}
