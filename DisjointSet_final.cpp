#include <bits/stdc++.h>
using namespace std;

//////  number of disjoint se
// only thing that is not her is size of that disjoint set by
// given value of node

int N,Rank[1000],parent[1000],noOfset;

void creatSet(int N){
    for(int i=0 ;i<=N; i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findParent(int x){
    if(parent[x] != x){
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

bool isSame(int x,int y){
    if(findParent(x) == findParent(y))
        return true;
    return false;
}

void makeSet(int x, int y){

    noOfset--;
    if(isSame(x,y))return;

    int px = findParent(x);
    int py = findParent(y);
    if(Rank[px] > Rank[py])
        parent[py] = px;
    else{
        parent[px] = py;
        if(Rank[px] == Rank[py])
            Rank[py]++;
    }
}

void display(int N){
    for(int i=1;i<=N;i++)cout<<parent[i]<<" ";
    cout<<endl;
    for(int i=1;i<=N;i++)cout<<Rank[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>N;
    noOfset = N;
    creatSet(N);
    makeSet(1,2);
    display(N);
    cout<<noOfset<<endl;
    makeSet(2,3);
    makeSet(6,7);
    makeSet(3,7);
    makeSet(3,10);
    display(N);
    cout<<noOfset<<endl;
}
