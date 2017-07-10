#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
typedef pair <int,int> pii;
vector <pii> g[100];
int d[100];

void dijkstra(int start){
    int u,v,w,c,i;
    for(i=0;i<10;i++)d[i] = 100000;
    d[0] = 0;
    priority_queue < pii , vector <pii>, greater <pii> >Q;
    Q.push(pii(0,start));
    while(!Q.empty()){
        u = Q.top().second ;//node
        c = Q.top().first;
        Q.pop();

        if(d[u]<c)continue;

        for(i=0;i<(int)g[u].size();i++){
            v = g[u][i].first;
            w = g[u][i].second;

            if(d[v]>d[u]+w){
                d[v] = d[u]+w;
                Q.push(pii(d[v],v));
            }

        }
    }
}

int main()
{
    int n,e,a,b,c,i;
    cin>>n>>e;

    for(i=0;i<100;i++)g[i].clear();

    while(e--){
        cin>>a>>b>>c;
        g[a].push_back(pii(b,c));
        g[b].push_back(pii(a,c));
    }

    dijkstra(0);

    for(i=0;i<n;i++)
        cout<<d[i]<<endl;
}
