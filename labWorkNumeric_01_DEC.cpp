#include<bits/stdc++.h>
using namespace std;

int n;
double x[100],y[100],a,xx,yy,b,j,k,sumX,sumY,sqSumX,sumXY;

int main(){
    freopen("input.txt","r",stdin);
    cout<<"Enter number of data point : ";
    cin>>n;
    cout<<"Enter X & Y values :"<<endl;
    for(int i = 0; i<n ;i++){
        cin>>j>>k;
        x[i] = j;
        sumX += j;
        sqSumX += j*j;
        y[i] = k;
        sumY += k;
        sumXY += j*k;
    }
    b = (n*sumXY - sumX*sumY)/(n*sqSumX - sumX*sumX);
    cout<<"khfjdhf "<<sumY<<" "<<sumY<<endl;
    a = (sumY/n)- (b*(sumX/n));
    cout<<"Enter the X value : ";
    cin>>xx;
    yy = a + b*xx;
    cout<<a<<" "<<b<<endl;
    cout<<"Y = "<<yy<<endl;
}
/**

5
1 3
2 4
3 5
4 6
5 8
1

**/
