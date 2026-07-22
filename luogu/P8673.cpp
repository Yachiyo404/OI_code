#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e7;
char ch;
ll n,m,f,r=1,x,y,k;
ll map_xy[1005][1005],l_x[N],l_y[N],cnt[N],wd[N];
bool sign[1005][1005],flag;
int main(){
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++){
        for(ll o=1;o<=n;o++){
            cin>>ch;
            if(ch=='.')
                map_xy[i][o]=1;
            else if(ch=='#')
                map_xy[i][o]=0;
            else if(ch=='X')
                map_xy[i][o]=-1;
            else
                map_xy[i][o]=250;
        }
    }
    /*for(ll i=1;i<=n;i++){
        for(ll o=1;o<=n;o++){
            printf("%lld ",map_xy[i][o]);
        }
        printf("\n");
    }*/
    sign[1][1]=1;
    l_x[1]=1;
    l_y[1]=1;
    cnt[1]=0;
    while(f<r){
        f++;
        for(ll p=1;p<=4;p++) {
            ll new_x=l_x[f],new_y=l_y[f];
            switch(p){
                case 1:
                    new_x++;
                    break;
                case 2:
                    new_x--;
                    break;
                case 3:
                    new_y++;
                    break;
                case 4:
                    new_y--;
            }
            if(new_x>=1&&new_x<=m&&new_y>=1&&new_y<=n){
                if(new_x==n&&new_y==n){
                    r++;
                    cnt[r]=cnt[f]+1;
                    flag=1;
                    break;
                }
                if(sign[new_y][new_x]==0){
                    if(map_xy[new_y][new_x]==1){
                        sign[new_y][new_x]=1;
                        r++;
                        l_x[r]=new_x;
                        l_y[r]=new_y;
                        cnt[r]=cnt[f]+1;
                        if(wd[f]!=0)
                            wd[r]=wd[f]-1;
                    }
                    else if(map_xy[new_y][new_x]==250){
                        sign[new_y][new_x]=1;
                        r++;
                        l_x[r]=new_x;
                        l_y[r]=new_y;
                        cnt[r]=cnt[f]+1;
                        wd[r]=k;
                        cnt[r]=cnt[f]+1;
                    }
                    else if(map_xy[new_y][new_x]==-1){
                        sign[new_y][new_x]=1;
                        if(wd[f]>0){
                            wd[r]=wd[f]-1;
                            r++;
                            l_x[r]=new_x;
                            l_y[r]=new_y;
                            cnt[r]=cnt[f]+1;
                        } 
                    }
                }
            }
        }
        if(flag)
            break;
    }
    if(flag)
        printf("%lld",cnt[r]);
    else
        printf("-1");
    return 0;
}