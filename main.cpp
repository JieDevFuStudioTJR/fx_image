#include<bits/stdc++.h>
#include<windows.h>
#include"JieDevFu_v1.0.h"

#define setcolor SetConsoleTextAttribute
#define hc hConsole

using namespace std;

struct character{
    char color;
    char putt;
    bool live;
};

map<pair<long long,long long>,character> mp;

const long double OP=100;
const long double moves=1;

long long moving=10;

typedef long double LD;
typedef long long LL;

LL get_close(LL k){
    // LL tmp=(k*pow(10,moving));
    return k;
    
    // return tmp;
    // LD t2=(tmp*1.0)/pow(10,moving);
    // return t2;
    // return k;
}

#define gc get_close


void print(char color,char putt){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(color>='0' && color<='9'){
        setcolor(hc,color-'0');
    }
    else{
        setcolor(hc,color-'a'+10);
    }

    printf("%c ",putt);

    setcolor(hc,0x0);
}

void print_all(){
    printf("\n\n");
    LL ops=moving;
    for(LL i=ops;i>=-ops;i-=moves){
        for(LL j=-ops;j<=ops;j+=moves){
            if(mp[make_pair(i,j)].live){
                character now=mp[make_pair(i,j)];
            
                print(now.color,now.putt);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return ;
}

void build_const_y_known(LD k,char color,char putt){
    for(LD i=-OP;i<=OP;i+=moves){
        mp[make_pair(gc(i),gc(k))].color=color;
        mp[make_pair(gc(i),gc(k))].putt=putt;
        mp[make_pair(gc(i),gc(k))].live=true;
    }
}

void build_const_x_known(LD k,char color,char putt){
    for(LL i=-OP;i<=OP;i+=moves){
        mp[make_pair(gc(k),gc(i))].color=color;
        mp[make_pair(gc(k),gc(i))].putt=putt;
        mp[make_pair(gc(k),gc(i))].live=true;
    }
}

void build_f1(LD k,LD b,char color,char putt){
    for(LL i=-OP;i<=OP;i+=moves){
        mp[make_pair(i,gc(i*k+b))].color=color;
        mp[make_pair(i,gc(i*k+b))].putt=putt;
        mp[make_pair(i,gc(i*k+b))].live=true;
    }
}

void build_f2(LD k,char color,char putt){
    for(LL i=-OP;i<=OP;i+=moves){
        if(i!=0){
            mp[make_pair(i,gc(k*1.0/i*1.0))].color=color;
            mp[make_pair(i,gc(k*1.0/i*1.0))].putt=putt;
            mp[make_pair(i,gc(k*1.0/i*1.0))].live=true;
        }
    }
}

void build_f3_hk(LD a,LD h,LD k,char color,char putt){
    //y=a(x-h)^2+k
    for(LL i=-OP;i<=OP;i+=moves){
        LL y=gc(a*1.0*(i-h)*(i-h)+k*1.0);
        mp[make_pair(y,i)].color=color;
        mp[make_pair(y,i)].putt=putt;
        mp[make_pair(y,i)].live=true;
    }
}

void build_f3_abc(LD a,LD b,LD c,char color,char putt){
    //y=ax^2+bx+c
    for(LL i=-OP;i<=OP;i+=moves){
        LL y=gc(a*1.0*i*i+b*1.0*i+c*1.0);
        mp[make_pair(y,i)].color=color;
        mp[make_pair(y,i)].putt=putt;
        mp[make_pair(y,i)].live=true;
    }
}

string op;
char pt,cl,xy;
LD A,B,C,K,H;

int main(){
    START("º¯ÊýÍ¼Ïñ fx_image v1.0");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while(cin>>op){
        if(op=="const"){
            cin>>xy>>K>>pt>>cl;

            if(xy=='x'){
                build_const_x_known(K,cl,pt);
            }
            else if(xy=='y'){
                build_const_y_known(K,cl,pt);
            }
            else{
                setcolor(hc,0x4);
                cout<<"´íÎóµÄ²ÎÊý:"<<xy<<'\n';
                setcolor(hc,0x0);
            }

        }
        else if(op=="f1"){
            cin>>K>>B>>pt>>cl;

            build_f1(K,B,cl,pt);
        }
        else if(op=="f2"){
            cin>>K>>pt>>cl;

            build_f2(K,cl,pt);
        }
        else if(op=="f3_1"){
            cin>>A>>H>>K>>pt>>cl;

            build_f3_hk(A,H,K,cl,pt);
        }
        else if(op=="f3_2"){
            cin>>A>>B>>C>>pt>>cl;

            build_f3_abc(A,B,C,cl,pt);
        }
        else if(op=="print"){
            print_all();
        }
        else if(op=="range"){
            cin>>moving;
        }
        else{
            setcolor(hc,0x4);
            cout<<"´íÎóµÄÃüÁî:"<<op<<'\n';
            setcolor(hc,0x0);
        }
    }

    return 0;
}