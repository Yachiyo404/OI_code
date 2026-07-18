#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	int n,ans;
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        if(i==1)
			cin>>ans;
        else
		{
            int x;
			cin>>x;
			x=abs(x);
            ans=gcd(ans,x);
        }
    }
    cout<<ans;
    return 0;
}
//对于任意整数a、b,存在x、y,使得a*x+b*y=gcd(a,b)
