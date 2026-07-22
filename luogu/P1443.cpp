#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e7;
char ch;
ll n,m,f,r=1,x,y;
ll m_xy[405][405],l_x[N],l_y[N],cnt[N];
bool sign[405][405];
int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&y,&x);
    sign[y][x]=1;
    m_xy[y][x]=-1;
    l_x[1]=x;
    l_y[1]=y;
    cnt[1]=0;
    while(f<r){
        f++;
        for(ll p=1;p<=8;p++) {
            ll new_x=l_x[f],new_y=l_y[f];
            switch(p){
                case 1:
                    new_x++; 
                    new_y+=2;
                    break;
                case 2:
                    new_x++;
                    new_y-=2; 
                    break;
                case 3:
                    new_x--;
                    new_y+=2;
                    break;
                case 4:
                    new_x--;
                    new_y-=2;
                    break;
                case 5:
                    new_x+=2;
                    new_y++;
                    break;
                case 6:
                    new_x+=2;
                    new_y--;
                    break;
                case 7:
                    new_x-=2;
                    new_y++;
                    break;
                case 8:
                    new_x-=2;
                    new_y--;
            }
            if(new_x>=1&&new_x<=m&&new_y>=1&&new_y<=n){
                if(sign[new_y][new_x]==0){
                    sign[new_y][new_x]=1;
                    r++;
                    l_x[r]=new_x;
                    l_y[r]=new_y;
                    cnt[r]=cnt[f]+1;
                    m_xy[l_y[r]][l_x[r]]=cnt[r];
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll o=1;o<=m;o++){
            if(m_xy[i][o]==-1)
                printf("0 ");
            else if(m_xy[i][o]==0)
                printf("-1 ");
            else
        	    printf("%lld ",m_xy[i][o]);
		}
        printf("\n");
    }
    return 0;
}