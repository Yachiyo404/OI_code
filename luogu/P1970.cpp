#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t=0,ans=1,cnt=-1;
signed main(){
	scanf("%lld%lld",&n,&m);
	t=m;
	for(int i=2;i<=n;i++){
		scanf("%lld",&m);
		if(m>t&&cnt!=1){
			cnt=1;
			ans++;
		}
        else if(m<t&&cnt){
			cnt=0;
			ans++;
		}
		t=m;
	}
	printf("%lld\n",ans);
	return 0;
}