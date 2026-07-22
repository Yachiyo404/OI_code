#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,et,temp,res;
struct _cow{
    int a,t,old; //a表示到达时间，t表示吃草时间，old表示资历
    friend bool operator < (_cow x,_cow y) //自定义比较运算符
    {
        return x.old>y.old;
    }
}cow[100010];
bool cmp(_cow x,_cow y){
    return x.a<y.a; //按到达时间从先到后排列（先来后到）
}
priority_queue <_cow> wait;
signed main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&cow[i].a,&cow[i].t);
        cow[i].old=i; //按输入的先后记录资历
    }
    sort(cow,cow+n,cmp); //排序
    et=cow[0].a+cow[0].t; //记录第一头奶牛的吃草结束时间
    for(int i=1;i<n;++i)
    {
        if(cow[i].a>=et) //如果这头奶牛可以进去吃了
        {
            if(wait.empty()) et=cow[i].a+cow[i].t; //注意点1
            else
            {
                temp=et-wait.top().a; //用它的结束时间（即这头奶牛的开始吃草时间）减去它的到达时间来计算等待时间
                if(temp>res) res=temp; //找出最大值
                et+=wait.top().t; //更新结束时间
                wait.pop();
                if(et<cow[i].a) --i; //注意点2
                else wait.push(cow[i]); //否则再等
            }
        }
        else wait.push(cow[i]);
    }
    while(!wait.empty()) //注意点3
    {
        temp=et-wait.top().a;
        if(temp>res) res=temp;
        et+=wait.top().t;
        wait.pop();
    }
    printf("%d\n",res);
    return 0;
}