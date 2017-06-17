// code is from codechef SnackDown 2017
//SNSOCIAL

// Flood fill approch is taken in this question

#include <bits/stdc++.h>
using namespace std;

int i,j;

int dx[] = {0,0,1,1,1,-1,-1,-1};
int dy[] = {1,-1,1,-1,0,1,-1,0};

int visited[505][505], a[505][505];
queue<pair<pair<int,int >,int > >qu; // x,y coordinate, d = time taken

int R,C

bool isValid(int x, int y){
	if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}

void solve(){
	int maxn = 0;
	cin>>R>>C;

	for(i = 0;i < R;i++){
		for(j = 0;j< C; j++){
			cin>>a[i][j];
			if(a[i][j]>maxn)maxn=a[i][j];
			visited[i][j] = 0;
		}
	}

	for(i = 0;i < R;i++){
		for(j = 0;j< C; j++){
			if(a[i][j] == maxn){
				qu.push(make_pair(make_pair(i,j),0));
				visited[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while(!qu.empty()){

		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int d = qu.front().second;

		if(d>ans)ans=d;

		qu.pop();
		for(i = 0; i < 8 ; i++){
			if(isValid(x+dx[i],y+dy[i]) == true && visited[x+dx[i]][y+dy[i]]==0){
				qu.push( make_pair( make_pair(x+dx[i],y+dy[i]),d+1));
				visited[x+dx[i]][y+dy[i]] = 1;
			}
		}
	}

	cout << ans << endl;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}
