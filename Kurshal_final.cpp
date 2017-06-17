//Kurshal algorithm to find the minimum spanning tree
//1's index

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pip pair<int,pii>
const int N = 10002;

class Union_Find
{
    public:
        int p[N],r[N],sz[N];
        Union_Find(int n)
        {
            for(int i=0;i<n;i++)
            {
                r[i] = 0;
                sz[i] = 1;
                p[i] = i;
            }
        }

        int par(int u){
            if(p[u] == u)return u;
            return p[u] = par(p[u]);
        }

        bool isSame(int u,int v){
            if(par(u) == par(v))return true;
            return false;
        }

        void join(int u,int v){
            int pu = par(u);
            int pv = par(v);
            if(pu == pv)return;
            if(r[pu]>r[pv]){
                p[pv] = pu;
                sz[pu] = sz[pu] + sz[pv];
            }else{
                p[pu] = pv;
                sz[pv] = sz[pv] + sz[pu];
                if(r[pu]==r[pv])r[pv]++;
            }
        }

};

vector< pip > graph;
int n, e;
long long int T;

void Kruskal_MST()
{
	Union_Find UF(n);
	int u, v;

	for (int i = 0; i < e; ++i)
	{
		u = graph[i].second.first;
		v = graph[i].second.second;
		if( !UF.isSame(u, v) )
		{
		    //cout<<"yeas"<<endl;
//			printf("uniting %d and %d\n",u,v );
			UF.join(u, v);
			T += graph[i].first;
		}
	}
}

int main()
{
	int u, v, c;
	cin>>n>>e;	//enter the no of nodes//enter the no of edges

	graph.resize(e);

	for (int i = 0; i < e; ++i)
	{
		cin>>u>>v>>c;	//enter vertex u//enter vertex v//enter cost of edge (u,v)
		graph[i] = pip( c, pii(u,v));
	}
	sort(graph.begin(), graph.end());	//sort the edges in increasing order of cost

	T = 0;
	Kruskal_MST();
	cout<<T<<endl;
	return 0;
}
