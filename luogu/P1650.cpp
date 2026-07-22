#include<bits/stdc++.h>
#define ll long long
#define up(a,b) for(ll i=a;i<=b;i++)
#define down(a,b) for(ll i=a;i>=b;i--)
using namespace std;
ll n,tian_money;
ll king_horse[2005],tian_horse[2005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    up(1,n)
        cin>>tian_horse[i];
    up(1,n)
        cin>>king_horse[i];
    sort(king_horse+1,king_horse+n+1,greater<ll>());
    sort(tian_horse+1,tian_horse+n+1,greater<ll>());
    for(ll i=1,j=1,ii=n,jj=n;i<=ii&&j<=jj;){
        if(tian_horse[i]>king_horse[j]){
            tian_money+=200;
            i++;
            j++;
        }
        else if(tian_horse[i]<king_horse[j]){
            tian_money-=200;
            j++;
            ii--;
        }
        else{
            if(tian_horse[ii]>king_horse[jj]){
                tian_money+=200;
                ii--;
                jj--;
            }
            else{
                if(tian_horse[ii]<king_horse[j]) 
                    tian_money-=200;
                ii--;
                j++;
            }
        }
    }
    cout<<tian_money;
    return 0;
}