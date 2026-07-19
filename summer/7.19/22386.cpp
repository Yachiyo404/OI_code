#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int arr[N],g[125][125];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    if(n>=121){
        cout<<3;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i]&arr[j]!=0)
                g[i][j]=1;
        }
    }
    return 0;
}