#include<bits/stdc++.h>
#define inf 10000
#define db cout<<"HELOO0"<<endl
using namespace std;

struct N{
    int u,v;
    N(int u,int v):u(u),v(v){}
};

void print();
int adj1[100][100],adj2[100][100];
vector<N>vi;
bool visited[100];
int edge,node,u,v,c,mn = inf,n,maxFlow = 0;
bool flag = false;

bool pathSelect(int src ){
    visited[src] = true;
    for(int i = 0;i<node;i++){
        if(flag){
            return true;
        }
        if(!visited[i] && adj2[src][i] != inf && adj2[src][i] != 0){
            vi.push_back(N(src,i));
            mn = min(mn,adj2[src][i]);
            if(i == node-1){
                flag = true;
                return true;
            }
            pathSelect(i);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    for(int i = 0;i<100;i++)
        for(int j = 0; j<100;j++){
            adj1[i][j] = inf;
            adj2[i][j] = inf;
        }
    cin>>node>>edge;
    for(int i = 0; i<edge ;i++){
        cin>>u>>v>>c;
        adj1[u][v] = c;
        adj2[u][v] = c;
    }
    print();
    int x,y;
    while(1){
        mn = inf;
        // memset(visited,false,sizeof visited);
        for(int i = 0;i<node+1;i++)
            visited[i] = false;
        flag = false;
        pathSelect(0);
        if(flag == false)break;
        for(int i = 0;i<vi.size();i++){
            x = vi[i].u;
            y = vi[i].v;
         //   cout<<x<<"-->"<<y<<" ";
            adj2[x][y] = adj2[x][y]-mn;
            if(adj2[y][x] != inf)adj2[y][x]+=mn;
            else adj2[y][x] = mn;
        }
        maxFlow += mn;
        cout<<endl;
       // print();
        cout<<endl;
        vi.clear();
    }
    cout<<"MaxFlow is : "<<maxFlow<<endl<<endl;

    for(int i = 0;i<node;i++){
        for(int j = 0; j<node;j++){
            if(adj2[i][j] == inf || adj1[i][j] == inf){
                cout<<"0/0 ";
            }
            else{
                cout<<(adj1[i][j]-adj2[i][j])<<"/"<<adj1[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

///End of main

void print(){
    for(int i = 0;i<node;i++){
        for(int j = 0; j<node;j++){
            cout<<adj2[i][j]<<" ";
        }
        cout<<endl;
    }
}
