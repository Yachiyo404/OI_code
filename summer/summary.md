# 7.10-7.21总结

## 1.知识点总结

### 二分查找及二分答案

#### 二分查找

二分法：用来在一个有序数组（升序或降序）中查找某一元素的算法。

时间复杂度：每次将序列长度减半，共需 $logn$ 次，整体复杂度为 $O(logn)$ 。

<img title="" src="https://i-blog.csdnimg.cn/blog_migrate/1ac9ecdb4815743c206c304f84126d7e.png" alt="二分查找算法详解：循环与递归实现及其优化-CSDN博客" width="337" data-align="inline">

二分查找模板

```cpp
// 在有序数组 a 中查找 target，返回下标
int l = 0, r = n - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;   // 防溢出
    if (a[mid] == target) return mid;
    else if (a[mid] < target) l = mid + 1;
    else r = mid - 1;
}
```

#### 二分答案

朴素暴力枚举答案的复杂度一般很高，往往是 $O(n^2)$ 甚至更高，而二分答案让我们可以从答案入手，就像先“猜”答案，再来验证答案的正确性。这时枚举的时间复杂度可以降到 $O(logn)$ ，从而使总体时间复杂度降到 $O(nlogn)$ ，就能通过。

##### 例题

##### [1246开会](https://www.xinyoudui.com/ac/contest/747010E3B000BCD090296C/problem/8260)

题目描述

在 $x$ 轴上有 $n$ 个人，每个人有一个移动速度 $v_1, v_2, \dots, v_n$ 。现在需要找一个地方让大家聚到一起开会，问你**最少需要多少时间**才可以让所有人都到达同一个点。

输入格式

- 第一行 $1$ 个整数 $n$ 。

- 第二行 $n$ 个整数：$ x_1, x_2, \dots, x_n$ ，表示每个人初始的位置。

- 第三行 $n$ 个整数：$v_1, v_2, \dots, v_n$ ，表示每个人的移动速度。

输出格式

- 一个浮点数，四舍五入保留 **5 位小数**。  

例如答案为 `2.333336`，应输出 `2.33334`。

解答：

考虑到时间具有单调性，时间越长，可以到达某点的人就越多，所以可以二分人们行动的时间， 检查函数 $check(t)$ 通过将每个人所能到达的区间取交集，若交集最后不为空集则该时间合法。

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e5+5;
const double eps=1e-7;
ll n;
ll x[N],v[N];
double ans;
bool check(double t){
    double ansl=x[1]-v[1]*t,ansr=x[1]+v[1]*t;
    for(ll i=1;i<=n;i++){
        double l=x[i]-v[i]*t,r=x[i]+v[i]*t;
        if(l>ansr||r<ansl)
                return 0;
        ansl=max(ansl,l);
        ansr=min(ansr,r);
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>x[i];
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    double l=0,r=1e10;
    while((r-l)>eps){
        double mid=l+(r-l)/2.0;
        if(check(mid)){
            ans=mid;
            r=mid-eps;
        }
        else
            l=mid+eps;
    }
    cout<<fixed<<setprecision(5)<<ans<<endl;
    return 0;
}
```

注意：实数二分需要定义 $eps$ ，即可接受误差，当 $l$ 与 $r$ 差值小于该值时停止。

### 双指针

顾名思义，双指针法就是同时移动两个数组上的指针 $i$ 和 $j$ 来实现目的，使用这种算法可以快速的处理区间问题。因为两个指针只会单向移动，所以双指针的时间复杂度为 $O(n)$ 。

#### 例题1

[9738魔法水晶](https://www.xinyoudui.com/ac/contest/747010E39000BCD0902B04/problem/7002)

题目描述

蒂凡妮城中布置了 $n$ 块魔法水晶，第 $i$ 块魔法水晶的魔力值为 $a_i$。蒂凡妮城主、大魔导师温拿经过研究，发现任意两块魔法水晶都可以产生魔法共振，并且其共振强度为两块水晶的魔力值之和（即 $a_i + a_j$）。

$n$ 块水晶能产生 $\frac{n(n-1)}{2}$ 种不同的魔法共振，值得注意的是，部分共振的共振强度可能相同。

温拿想知道第 $k$ 小的共振强度是多少。

输入格式

第一行两个整数 $n$ 和 $k$ 。
第二行 $n$ 个整数 $a_1 \sim a_n$ 。

输出格式

输出一行，代表答案。

解答：

题目求解第 $k$ 小的共振强度，即求解第 $k$ 小的 $(a_i+a_j)$ 。发现暴力枚举的复杂度为 $O(n^2)$ ，明显无法通过。这时我们可以从另一个方向来思考，我们可以二分答案第 $k$ 小的数，再通过双指针来判断是否有 $k$ 对 $a_i$ 及 $a_j$ 的和小于枚举的答案，整体时间复杂度为 $O(nlogn)$ 。

代码

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,k;
ll a[N];
bool check(ll x){
    ll cnt=0;
    int l=1,r=n;
    while(l<r){
        if(a[l]+a[r]<=x){
            cnt+=(r-l);
            l++;
        }
        else
            r--;
    }
    return cnt>=k;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=0,r=2e9,ans=r;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}
```

注意：第 $k$ 大与第 $k$ 小区别。

### 单调栈、单调队列、优先队列

#### 单调栈

何为单调栈？顾名思义，单调栈即满足单调性的栈结构。它具有的单调性让它可以维护一些最大值或最小值问题，还能用来优化dp，因为所有元素都只会进栈或岀栈一次，所以时间复杂度为 $O(n)$ 。

##### 例题

[8619单调栈](https://www.xinyoudui.com/ac/contest/747010E47000BCD0902EE8/problem/7631) 

题目描述

给出项数为 $n$ 的整数数列 $a_1, \dots, a_n$，定义函数 $f(i)$ 代表数列中第 $i$ 个元素之后第一个大于 $a_i$ 的元素的下标，即 $f(i) = \min_{i < j \leq n, a_i < a_j} \{j\}$ ，若不存在，则 $f(i) = 0。

试求出 $f(1 \dots n)$ 。

输入格式

第一行一个正整数 $n$ 。 
第二行 $n$ 个正整数 $a_1 \dots a_n$。

输出格式

一行 $n$ 个整数 $f(1 \dots n)$ 的值。

解答：

题目求数列中第一个大于第 $i$ 个元素之后第一个大于 $a_i$ 的元素的下标，考虑维护一个单调单调递减的单调栈，每次进栈元素大于栈顶元素时便弹出并输出进栈元素的编号。

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
int n;
int ans[N];
struct node{
    int id,data;
}a[N];
stack<node> sta;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].data;
        a[i].id=i;
    }
    sta.push(a[1]);
    for(int i=2;i<=n;i++){
        if(!sta.empty()&&a[i].data<=sta.top().data)
            sta.push(a[i]);
        else{
            while(!sta.empty()&&a[i].data>sta.top().data){
                if(sta.top().id<i)
                    ans[sta.top().id]=i;
                sta.pop();
            }
            sta.push(a[i]);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
```

#### 单调队列

单调队列与单调栈唯一不同之处是单调队列是双向出入队，而单调栈只是单向的，这使得单调队列更加灵活，也可以用来优化dp，时间复杂度同样为 $O(n)$ 。

单调队列的一大用处便是“滑动窗口”——求定长区间的最大值或最小值。

##### 例题

[1872雨点](https://www.xinyoudui.com/ac/contest/747010E47000BCD0902EE8/problem/7637)

题目描述

给定水平轴 $N$ 个雨点，每个点距离地面高度为 $h_i$，则该雨点坐标为 $(x_i, h_i)$。雨同时落下，速度一样为单位时间。给定时间间隔 $D$，问至少放一个多短的接水器，使其适当摆放后，摆放后不能再移动，第一滴雨与最后一滴雨滴落到该器皿的时间间隔 $\ge D$。

输入格式

第一行给出 $N$（$1 \le N \le 100{,}000$）和 $D$（$1 \le D \le 1{,}000{,}000$），表示雨点个数及时间间隔； 
接下来 $N$ 行，代表每个雨点的坐标，其值在 $[0, 1{,}000{,}000]$ 。

输出格式

一个数字，代表这个器皿至少应该为多少，如果无解，请输出 `-1`。

解答：

通过观察可以发现容器的宽度越大，落入容器的雨点时间间隔越长，从而更容易达到题目的要求 $D$ 。所以容器的宽度是具有单调性的，考虑二分宽度，再通过维护两个单调队列来求区间最大值与最小值，若差值大于 $D$ ，则答案合法。

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,d,ans=-1;
struct node{
    int x,h;
}drop[N];
bool check(int k){
    deque<node> dq;
    vector<node> mi,ma;
    dq.push_back(drop[1]);
    for(int i=2;i<=n;i++){
        if(!dq.empty()&&drop[i].h>dq.back().h)
            dq.push_back(drop[i]);
        else{
            while(!dq.empty()&&drop[i].h<=dq.back().h)
                dq.pop_back();
            dq.push_back(drop[i]);
        }
        while(!dq.empty()&&dq.front().x<drop[i].x-k)
            dq.pop_front();
        mi.push_back(dq.front());
    }
    dq.clear();
    dq.push_back(drop[1]);
    for(int i=2;i<=n;i++){
        if(!dq.empty()&&drop[i].h<dq.back().h)
            dq.push_back(drop[i]);
        else{
            while(!dq.empty()&&drop[i].h>=dq.back().h)
                dq.pop_back();
            dq.push_back(drop[i]);
        }
        while(!dq.empty()&&dq.front().x<drop[i].x-k)
            dq.pop_front();
        ma.push_back(dq.front());
    }
    for(int i=0;i<mi.size();i++){
        if(ma[i].h-mi[i].h>=d)
            return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>drop[i].x>>drop[i].h;
    sort(drop+1,drop+n+1,[](node a,node b){return a.x<b.x;});
    int l=0,r=1e6;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}
```

#### 优先队列

优先队列（Priority Queue），是c++STL容器中的一种，本质是堆。

堆是一棵树，其每个节点都有一个键值，且每个节点的键值都大于等于/小于等于其父亲的键值。每个节点的键值都大于等于其父亲键值的堆叫做小根堆，否则叫做大根堆。

我们常用的是二叉堆，具有较优的时间复杂度，插入为 $O(logn)$ ，查询堆顶为 $O(1)$ 。

##### 例题

[7454合并果子](https://www.xinyoudui.com/ac/contest/747010E44000BCD0902EFA/problem/6478)

题目描述

在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了 $n$ 堆。多多决定把所有的果子合成一堆。

每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过 $n-1$ 次合并之后，就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。

因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为 1，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。

例如有 3 种果子，数目依次为 1，2，9。可以先将 1，2 堆合并，新堆数目为 3，耗费体力为 3。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 12，耗费体力为 12。所以多多总共耗费体力 $3+12=15$。可以证明 15 为最小的体力耗费值。

输入格式

第一行是一个整数 $n(1 \leq n \leq 10^5)$，表示果子的种类数。

第二行包含 $n$ 个整数，用空格分隔，第 $i$ 个整数 $a_i(1 \leq a_i \leq 10^9)$ 是第 $i$ 种果子的数目。

输出格式

一个整数，也就是最小的体力耗费值。

解答：

考虑如何最小化体力耗费值，猜结论：每次将两个最小的果子堆合并，~~好吧我并不知道怎么证明这个结论~~。所以可以使用小根堆来维护果子的重量值，每次取出堆顶的两堆果子合并。

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int weigh[N];
ll ans;
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weigh[i];
        pq.push(weigh[i]);
    }
    while(pq.size()>1){
        int fir=pq.top();
        pq.pop();
        int sec=pq.top();
        pq.pop();
        ans+=(fir+sec);
        pq.push(fir+sec);
    }
    cout<<ans;
    return 0;
}
```

### dp基础

能用动态规划解决的问题，需要满足三个条件：最优子结构，无后效性和子问题重叠。

对于一个能用动态规划解决的问题，一般采用如下思路解决：

1. 将原问题划分为若干 **阶段**，每个阶段对应若干个子问题，提取这些子问题的特征（称之为 **状态**）；
2. 寻找每一个状态的可能 **决策**，或者说是各状态间的相互转移方式（用数学的语言描述就是 **状态转移方程**）．
3. 按顺序求解每一个阶段的问题。

#### 背包dp

##### 01背包

[P1048 [NOIP 2005 普及组] 采药](https://www.luogu.com.cn/problem/P1048)

题目描述

辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

如果你是辰辰，你能完成这个任务吗？

输入格式

第一行有 2 个整数 $T$（$1 \le T \le 1000$）和 $M$（$1 \le M \le 100$），用一个空格隔开，$T$ 代表总共能够用来采药的时间，$M$ 代表山洞里的草药的数目。

接下来的 $M$ 行每行包括两个在 $1$ 到 $100$ 之间（包括 $1$ 和 $100$）的整数，分别表示采摘某株草药的时间和这株草药的价值。

输出格式

输出在规定的时间内可以采到的草药的最大总价值。

解答：
