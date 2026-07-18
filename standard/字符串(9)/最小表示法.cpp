#include<bits/stdc++.h>
#define int long long
using namespace std;
int zxbsf(string s)
{
	int n=s.size();
	int i=0,j=1,k=0;
	while(k<n&&i<n&&j<n)
	{
		if(s[(i+k)%n]==s[(j+k)%n])
			k++;
		else
		{
			s[(i+k)%n]>s[(j+k)%n]?i=i+k+1:j=j+k+1;
			if(i==j)
				i++;
			k=0;
		}
	}
	return min(i,j);
}
signed main()
{
	string c,s;
	cin>>c>>s;
	int n=s.size(),j=zxbsf(c),k=zxbsf(s);
	for(int i=1;i<=n;i++)
	{
		if(c[j%n]!=s[k%n])
		{
			cout<<"No";
			return 0;
		}
		j++;
		k++;
	}
	j%=n;
	cout<<"Yes\n";
	for(int i=j;i<n;i++)
		cout<<c[i];
	for(int i=0;i<j;i++)
		cout<<c[i];
    return 0;
}
