#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e8;
char ch;
ll n,f,r=1,x_1,x_2,y_1,y_2;
short map_xy[1005][1005],sign[1005][1005],cnt[N],l_x[N],l_y[N];
bool flag;
/*vector <short> cnt(10000);
vector <short> l_x(10000);  
vector <short> l_y(10000);*/
int main(){
    scanf("%lld",&n);
    /*cnt.reserve(10000000);
    l_x.reserve(10000000);
    l_y.reserve(10000000);*/
    for(ll i=1;i<=n;i++){
        for(ll o=1;o<=n;o++){
            cin>>ch;
            if(ch=='1')
                map_xy[i][o]=0;
            if(ch=='0')
                map_xy[i][o]=1;
            
        }
    }
    scanf("%lld%lld%lld%lld",&x_1,&y_1,&x_2,&y_2);
    /*for(ll i=1;i<=n;i++){
        for(ll o=1;o<=n;o++){
            cout<<map_xy[i][o];
        }
        cout<<endl;
    }*/
    sign[x_1][x_1]=1;
    l_x[1]=x_1;
    l_y[1]=y_1;
    while(f<r){
        f++;
        for(ll p=1;p<=4;p++){
            switch(p){
                case 1:
                	r++;
                    l_x[r]=l_x[f]+1;
                    l_y[r]=l_y[f];
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==x_2&&l_y[r]==y_2){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=n)&&(1<=l_y[r]&&l_y[r]<=n)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
                        	//printf("x=%lld y=%lld r=%lld\n",l_x[r],l_y[r],r);
						}
                        else
                            r--;
                    }
                    else
                        r--;
                    break;
                case 2:
                	r++;
                    l_x[r]=l_x[f]-1;
                    l_y[r]=l_y[f];
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==x_2&&l_y[r]==y_2){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=n)&&(1<=l_y[r]&&l_y[r]<=n)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
                        	//printf("x=%lld y=%lld r=%lld\n",l_x[r],l_y[r],r);
						}
                        else
                            r--;
                    }
                    else
                        r--;
                    break;
                case 3:
                	r++;
                    l_x[r]=l_x[f];
                    l_y[r]=l_y[f]+1;
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==x_2&&l_y[r]==y_2){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=n)&&(1<=l_y[r]&&l_y[r]<=n)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
                        	//printf("x=%lld y=%lld r=%lld\n",l_x[r],l_y[r],r);
						}
                        else
                            r--;
                    }
                    else
                        r--;
                    break;
                case 4:
                	r++;
                    l_x[r]=l_x[f];
                    l_y[r]=l_y[f]-1;
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==x_2&&l_y[r]==y_2){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=n)&&(1<=l_y[r]&&l_y[r]<=n)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
                        	//printf("x=%lld y=%lld r=%lld\n",l_x[r],l_y[r],r);
						}
                        else
                            r--;
                    }
                    else
                        r--;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            break;
    }
    printf("%lld",cnt[r]);
    return 0;
}