#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e7+10;
ll n,m,op;
struct s{
	ll high,happy;
}stu[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>stu[i].high;
	/*for(ll i=1;i<=n;i++)
		printf("%lld ",stu[i].high);*/
	while(m--){
		cin>>op;
		switch(op){
			case 1:
				ll l,r; 
				cin>>l>>r;
				ll ans;
				ans=0;
				for(ll i=l;i<=r;i++)
					ans=max(ans,stu[i].high);
				if(ans>stu[1].high)
					cout<<ans-stu[1].high<<endl;
				else
					cout<<0<<endl;
				break;
			case 2:
				ll a,b;
				cin>>a>>b;
				swap(stu[a].high,stu[b].high);
				break;
			case 3:
				ll t;
				cin>>l>>r>>t;
				if(t==0)
					break;
				ll j;
				j=1;
				for(ll i=l;i<=r;i++){
					stu[i].high+=j*t;
					j++;
				}
		}
		/*for(ll i=1;i<=n;i++)
			printf("i=%lld high=%lld happy=%lld ",i,stu[i].high,stu[i].happy);
		printf("\n");*/
	}
	return 0;
}