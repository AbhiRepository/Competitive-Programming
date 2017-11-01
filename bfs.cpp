#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 9;
const long long INF = 1e6 + 9;
typedef long long lli;
typedef unsigned long long uli;
vector<int>g[MAX];
queue<int>que;
int visited[MAX];
int dis[MAX];

void bfs(int s){
    que.push(s);
    visited[s] = 1;
    dis[s] = 0;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        cout<<x<<endl;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int y = g[x][i];
            if(visited[y] == 0){
                visited[y] = 1;
                dis[y] = dis[x] + 1;
                que.push(y);
            }
        }
    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        visited[i] = 0;
        dis[i] = INF;
    }

    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }       
    bfs(1);

    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    
    cout<<endl; 
    return 0;
}