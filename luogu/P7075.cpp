#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=gc();
    }
    return x*f;
}
void write(ll x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    pc(x%10+'0');
}
int Q;
int main(){
    Q=read();
    while(Q--){
        ll ask=read();
        int y=-4713,m=1,d=1;
        while(ask>366){
            if(y==1582){
                ask-=355;
                y++;
            }
            else if(y>1582){
                if(y%400==0||(y%4==0&&y%100!=0))
                    ask-=366;
                else
                    ask-=365;
                y++;
            }
            else{
                if(y>0){
                    if(y%4==0)
                        ask-=366;
                    else
                        ask-=365;
                }
                else{
                    if(abs(y)%4==1)
                        ask-=366;
                    else
                        ask-=365;
                }
                y++;
                if(y==0)
                    y++;
            }
        }
        while(1){
            int days;
            if(y==1582)
                days=355;
            else if(y>1582){
                if(y%400==0||(y%4==0&&y%100!=0))
                    days=366;
                else 
                    days=365;
            } 
            else{
                if(y>0){
                    if(y%4==0)
                        days=366;
                    else 
                        days=365;
                } 
                else{
                    if(abs(y)%4==1) 
                        days=366;
                    else
                        days=365;
                }
            }
            if(ask>=days){
                ask-=days;
                y++;
                if(y==0) 
                    y=1;
            } 
            else
                break;
        }
        if(y==1582){
            while(ask--){
                d++;
                if(m==1&&d==32){
                    m=2;
                    d=1;
                }
                else if(m==2&&d==29){
                    m=3;
                    d=1;
                }
                else if(m==3&&d==32){
                    m=4;
                    d=1;
                }
                else if(m==4&&d==31){
                    m=5;
                    d=1;
                }
                else if(m==5&&d==32){
                    m=6;
                    d=1;
                }
                else if(m==6&&d==31){
                    m=7;
                    d=1;
                }
                else if(m==7&&d==32){
                    m=8;
                    d=1;
                }
                else if(m==8&&d==32){
                    m=9;
                    d=1;
                }
                else if(m==9&&d==31){
                    m=10;
                    d=1;
                }
                else if(m==10&&d==5)
                    d=15;
                else if(m==10&&d==32){
                    m=11;
                    d=1;
                }
                else if(m==11&&d==31){
                    m=12;
                    d=1;
                }
                else if(m==12&&d==32){
                    m=1;
                    d=1;
                    y++;
                }
            }
        }
        else{
            int add=0;
            if(y>0){
                if(y>1582){
                    if(y%400==0||(y%4==0&&y%100!=0))
                        add=1;
                }
                else{
                    if(y%4==0)
                        add=1;
                }
            }
            else{
                if(abs(y)%4==1)
                    add=1;
            }
            if(ask>=334+add){
                ask-=(334+add);
                d+=ask;
                m=12;
            }
            else if(ask>=304+add){
                ask-=(304+add);
                d+=ask;
                m=11;
            }
            else if(ask>=273+add){
                ask-=(273+add);
                d+=ask;
                m=10;
            }
            else if(ask>=243+add){
                ask-=(243+add);
                d+=ask;
                m=9;
            }
            else if(ask>=212+add){
                ask-=(212+add);
                d+=ask;
                m=8;
            }
            else if(ask>=181+add){
                ask-=(181+add);
                d+=ask;
                m=7;
            }
            else if(ask>=151+add){
                ask-=(151+add);
                d+=ask;
                m=6;
            }
            else if(ask>=120+add){
                ask-=(120+add);
                d+=ask;
                m=5;
            }
            else if(ask>=90+add){
                ask-=(90+add);
                d+=ask;
                m=4;
            }
            else if(ask>=59+add){
                ask-=(59+add);
                d+=ask;
                m=3;
            }
            else if(ask>=31){
                ask-=31;
                d+=ask;
                m=2;
            }
            else
                d+=ask;
        }
        if(y<0)
            write(d),pc(' '),write(m),pc(' '),write(abs(y)),pc(' '),pc('B'),pc('C'),pc('\n');
        else
            write(d),pc(' '),write(m),pc(' '),write(abs(y)),pc('\n');
    }
    return 0;
}