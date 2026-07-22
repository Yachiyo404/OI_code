#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,s,t,fla,run;
signed main(){
	scanf("%lld%lld%lld",&m,&s,&t);
	for(int i=1;i<=t;i++){
		if(m>=10){
            m-=10;
            fla+=60;
            run+=17;
        }
		else{
            if(fla>run)
                run=fla;
			m+=4,run+=17;
        }
		if(max(fla,run)>=s){
			printf("Yes\n%lld",i);
            return 0;
        }
	}
	printf("No\n%lld",max(fla,run));
	return 0;
}