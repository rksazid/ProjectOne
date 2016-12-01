#include<bits/stdc++.h>
using namespace std;

struct node{
    double x,y,dydx;
    node(double x,double y,double dydx):x(x),y(y),dydx(dydx){}
};

double x0,y0,h = 0.05,xMax,xMin,dydxPre,dydxPost,yPre,yPost,yy;
vector<node>v;

double fx(double x,double y){
    return x+y;
}

double calcY(double y,double h,double fx){
    return y+h*fx;
}

double calcAproxY(double fx0,double fx1){
    return y0+((fx0+fx1)/2.0)*h;
}

bool err(double y0,double y1){
    if(abs(y0-y1)<0.0001)
        return true;
    return false;
}

int main(){
    cout<<setprecision(12);
    freopen("input1.txt","r",stdin);
    cout<<"Enter x0 & y0 value : ";
    cin>>x0>>y0;
    yy = y0;
    cout<<"Enter range of X : "<<endl;
    cin>>xMin>>xMax;
    dydxPre = fx(x0,y0);
    yPre = calcY(y0,h,dydxPre);
    v.push_back(node(x0,y0,dydxPre));
    while(1){
        x0 += h;
        while(1){
            dydxPost = fx(x0,yPre);
            yPost = calcAproxY(dydxPre,dydxPost);
           // cout<<yPost<<"   pre " <<dydxPost<<endl;
            if(err(yPre,yPost))
                break;
            yPre = yPost;
        }
        y0 = yPost;
        dydxPre = dydxPost;
        yPre = yy + 2*h*dydxPost;
        v.push_back(node(x0,yPost,dydxPost));
        if(x0 >= xMax)break;
    }
    for(int i = 0 ;i< v.size();i++){
        cout<<"x"<<i<<" = "<<v[i].x<<" y"<<i<<" = "<<v[i].y<<"   dydx = "<<v[i].dydx<<endl;
    }
}

/***

0 1
0.05 0.1

**/
