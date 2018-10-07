// g++ --std=c++11 first.cpp -o a

#include <iostream>
using namespace std;
typedef long long lli;
int parent[100005], ranks[100005], n;
lli valid[100005], a[100005], ind[100005], maxVal = -1, maxValues[100005];


//void make_set(int v){
//	for(int i=0;i<v;i++){
//		parent[i]=i; rankss[i]=0; 
//	}
//}


void display(lli a[], int n){
	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;
}

int find_set(int v){
	if(parent[v] == v)return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int x,int y){
	//display(a,n);
	x = find_set(x);
	y = find_set(y);
	//cout<<x<<" "<<y<<endl;
	if(x!=y){
		if(ranks[x]<ranks[y]) swap(x,y);
		parent[y] = x;
		if(ranks[x]==ranks[y])ranks[x]++;
	}
	//cout<<"is this even running"<<endl;
	//cout<<"a[x] = "<<a[x]<<"  "<<"a[y] = "<<a[y]<<endl;
	a[x] = a[x] + a[y];
	//cout<<"a[x] + a[y] = "<<a[x]<<endl;
	if(a[x]>maxVal) maxVal = a[x];
}

int main()
{
	cin>>n;
	memset(valid, -1, sizeof(valid));
	//memset(parentSum,0,sizeof(parentSum));
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		ranks[i] = 0;
		parent[i] = i;
	}
	for(int i=1;i<=n;i++) cin>>ind[i];

	int curInd;           
	for(int i=n;i>=1;i--){
		curInd = ind[i];
		valid[curInd] = 0;
		if(valid[curInd-1]==0)union_set(curInd, curInd-1);
		if(valid[curInd+1]==0)union_set(curInd, curInd+1);
		if(a[curInd]>maxVal)maxVal=a[curInd];
		maxValues[i] = maxVal;
		//display(a,n);
	}
	display(maxValues,n);
}