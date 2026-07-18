#include<bits/stdc++.h>
#define int long long
using namespace std;
int nxt[1000005];
signed main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.size();
	int len2=s2.size();
	nxt[0]=0;
	nxt[1]=0;
	for(int i=1;i<len2;i++)
	{
		int j=nxt[i];
		while(j&&s2[i]!=s2[j])
			j=nxt[j];
		if(s2[i]==s2[j])
			nxt[i+1]=j+1;
		else
			nxt[i+1]=0;
	}
	int j=0;
	for(int i=0;i<len1;i++)
	{
		while(j&&s1[i]!=s2[j])
			j=nxt[j];
		if(s1[i]==s2[j])
			j++;
		if(j==len2)
			cout<<i+2-len2<<'\n';
	}
	for(int i=1;i<=len2;i++)
		cout<<nxt[i]<<" ";
    return 0;
}
