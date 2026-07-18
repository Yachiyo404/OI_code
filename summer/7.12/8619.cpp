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