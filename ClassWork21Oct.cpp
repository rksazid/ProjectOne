#include<bits/stdc++.h>
#define inf 1000000
using namespace std;

int adj1[100][100],adj2[100][100];
bool flag = true;
int n,u,v,c,e,mn = inf;

struct node{
    int x,y;
    node(int x,int y):x(x),y(y){}
};

vector<node>vi;

void pathFinder(int d){
    if(d == n-1){
        flag = true;
        return;
    }
    for(int i = 0 ; i<n ;i++){
        if(adj2[d][i] != inf){
            vi.push_back(node(d,i));
            if(adj2[d][i]<mn)mn = adj2[d][i];
            pathFinder(i);
            return;
        }
    }
}

int main(){
    for(int i = 0 ;i<100;i++)
        for(int j = 0;j<100;j++){
            adj1[i][j] = inf;
            adj2[i][j] = inf;
        }
    freopen("input.txt","r",stdin);
    cin>>n>>e;
    for(int i = 0;i<e;i++){
        cin>>u>>v>>c;
        adj1[u][v] = c;
        adj2[u][v] = c;
    }

    for(int i = 0 ;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<adj2[i][j]<<" ";
        }
        cout<<endl;
    }

    int x,y,mx = 0;
    while(flag){
        mn = inf;
        flag = false;
        pathFinder(0);
        if(flag == false)continue;
        mx += mn;
        for(int i = 0;i<vi.size();i++){
            x = vi[i].x;
            y = vi[i].y;
            adj2[x][y] -= mn;
            if(adj2[x][y] == 0)adj2[x][y] = inf;
        }
        cout<<endl<<endl;
        vi.clear();
    }
    cout<<endl;
    for(int i = 0 ;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<adj2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Maximum is = " <<mx<<endl<<endl;
    for(int i = 0 ;i<n;i++){
        for(int j = 0;j<n;j++){
            if(adj1[i][j] != inf){
                    if(adj2[i][j] == inf)cout<<adj1[i][j]<<"/";
                    else cout<<adj1[i][j]-adj2[i][j]<<"/";
                    cout<<adj1[i][j]<<" ";
            }
            else cout<<inf<<" ";
        }
        cout<<endl;
    }
}

/**

4 5
0 1 3
0 2 2
2 3 4
1 3 2
1 2 3



6 10
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 5 4
4 3 7
3 5 20
**/
