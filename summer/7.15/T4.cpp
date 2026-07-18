#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int mp[5010][25];
struct node{
    int x,y,c;
};
vector<node> v;
bool cmp(node a,node b){
    if(a.c==b.c){
        if(a.x==b.x)
            return a.y<b.y;
        else
            return a.x<b.x;
    }
    else
        return a.c>b.c;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='T')
                mp[i][j+1]=1;
            else
                mp[i][j+1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool flag=1;
            int cnt=0;
            for(int k=1;k<=m;k++){
                if(mp[i][k]==0&&mp[j][k]==0){
                    flag=0;
                    break;
                }
                if(mp[i][k]==1)
                    cnt++;
                if(mp[j][k]==1)
                    cnt++;
            }
            if(flag)
                v.push_back({i,j,cnt});
        }
    }
    
    if(v.empty())
        cout<<"No";
    else{
        sort(v.begin(),v.end(),cmp);
        cout<<v[0].x<<' '<<v[0].y;
    }
    return 0;
}