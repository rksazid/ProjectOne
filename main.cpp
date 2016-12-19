#include <bits/stdc++.h>
using namespace std;

double w[20][20],cost[20][20],root[20][20];
double key,probability[100],p,cumilitiveProbabilty[100],posJ,posK,posP;

void initializeAll(){
    for(int i = 1; i<=key ; i++){
        cost[i-1][i] = probability[i-1];
    }

    for(int i = 0; i<key ; i++){
        root[i][i] = i+1;
    }

    cumilitiveProbabilty[0] = probability[0];
    for(int i = 1; i<key ; i++){
        cumilitiveProbabilty[i] += probability[i] + cumilitiveProbabilty[i-1];
    }

    for(int i = 0; i<key ; i++){
        for(int j = i; j<key ;j++){
            w[i][j] = cumilitiveProbabilty[j];
        }
    }
}


int main(){
    freopen("input.txt","r",stdin);
    cout<<"Enter The number of key : ";
    cin>>key;
    cout<<"Enter Probabilities : "<<endl;
    for(int i = 0; i<key ; i++){
        cin>>probability[i];
    }

    initializeAll();

/// print section

    for(int i = 0; i<key ; i++){
        for(int j = 0; j<key ;j++){
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i = 0; i<key ; i++){
        for(int j = 0; j<key ;j++){
            cout<<root[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i = 0; i<=key ; i++){
        for(int j = 0; j<=key ;j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }


/// N^3 loop

    for(int i = 1; i<= key-1 ; i++){
        double mn = 100000;
        for(int j = 0 ; j< key-1 ; j++){
            int k = j+i;
            for(int p = j ; p<=k ; p++){
                cost[j][k] = ( cost[j][p-1]+ cost[p+1][k]) + w[j][k] ;
                if(cost[j][k]<mn){
                    mn = cost[j][k];
                    posP = p;
                }
            }
            root[j][k] = posP;
        }
    }

///Print section
    cout<<endl;
    for(int i = 0; i<=key ; i++){
            for(int j = 0; j<=key ;j++){
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
    }

    cout<<endl;
    for(int i = 0; i<key ; i++){
        for(int j = 0; j<key ;j++){
            cout<<root[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
