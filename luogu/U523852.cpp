#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e7;
char ch;
ll R, C, map_xy[45][45], sign[45][45], f, r = 1, l_x[N], l_y[N], cnt[N];
bool flag;

int main(){
    scanf("%lld%lld", &R, &C);
    for (ll i = 1; i <= R; i++) {
        for (ll o = 1; o <= C; o++) {
            cin >> ch;
            map_xy[i][o] = (ch == '.') ? 1 : 0; 
        }
    }
    sign[1][1] = 1;
    l_x[1] = 1;  // 列坐标 (x)
    l_y[1] = 1;  // 行坐标 (y)
    cnt[1] = 1;
    while (f < r) {
        f++;
        for (ll p = 1; p <= 4; p++) {
            ll nx = l_x[f], ny = l_y[f]; // 新坐标
            switch (p) {
                case 1: nx++; break; // 右
                case 2: ny++; break; // 下
                case 3: nx--; break; // 左
                case 4: ny--; break; // 上
            }
            // 关键修正：按正确顺序检查
            if (nx >= 1 && nx <= C && ny >= 1 && ny <= R) { // 列边界[1,C]，行边界[1,R]
                if (map_xy[ny][nx] == 1 && sign[ny][nx] == 0) { // 行ny, 列nx
                    // 先标记访问
                    sign[ny][nx] = 1;
                    
                    // 加入新节点
                    r++;
                    l_x[r] = nx;
                    l_y[r] = ny;
                    cnt[r] = cnt[f] + 1;
                    
                    // 检查终点（列C, 行R）
                    if (nx == C && ny == R) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) 
                break;
        }
        if(flag) 
            break;
    }
    printf("%lld", cnt[r]);
    return 0;
}
    /*自己写的第一版
    scanf("%lld%lld",&R,&C);
    for(ll i=1;i<=R;i++){
        for(ll o=1;o<=C;o++){
            cin>>ch;
            if(ch=='#')
                map_xy[i][o]=0;
            else
                map_xy[i][o]=1;
        }
    }
    sign[1][1]=1;
    l_x[1]=1;
    l_y[1]=1;
    cnt[1]=1;
    while(f<r){
        f++;
        for(ll p=1;p<=4;p++){
            switch(p){
                case 1:
                	r++;
                    l_x[r]=l_x[f]+1;
                    l_y[r]=l_y[f];
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==C&&l_y[r]==R){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=C)&&(1<=l_y[r]&&l_y[r]<=R)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
						}
                        else
                            r--;
                    }
                    else
                        r--;
                    break;
                case 2:
                	r++;
                    l_x[r]=l_x[f];
                    l_y[r]=l_y[f]+1;
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==C&&l_y[r]==R){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=C)&&(1<=l_y[r]&&l_y[r]<=R)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
						}
                        else
                            r--;
                    }
                    else
                        r--;
                    break;
                case 3:
                	r++;
                    l_x[r]=l_x[f]-1;
                    l_y[r]=l_y[f];
                    cnt[r]=cnt[f]+1;
                    if(l_x[r]==C&&l_y[r]==R){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=C)&&(1<=l_y[r]&&l_y[r]<=R)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
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
                    if(l_x[r]==C&&l_y[r]==R){
                        flag=1;
                        break;
                    }
                    if((1<=l_x[r]&&l_x[r]<=C)&&(1<=l_y[r]&&l_y[r]<=R)){
                        if(map_xy[l_x[r]][l_y[r]]==1&&sign[l_x[r]][l_y[r]]==0){
                        	sign[l_x[r]][l_y[r]]=1;
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
    printf("%lld",cnt[r]);*/