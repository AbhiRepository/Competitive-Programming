#include <iostream>
#include <string>
using namespace std;
const int MAX = 1e7;
int a[MAX];
int tree[3*MAX];

void build(int pos,int b,int e){
    if(b>e)return;
    else if(b==e){
        tree[pos] = a[b];
        return;
    }

    build(pos*2+1,b,(b+e)/2);
    build(pos*2+2,(b+e)/2+1,e);
    tree[pos] = min(tree[pos*2+1],tree[pos*2+2]);
}

int rangeMinArray(int tree[],int qlow, int qhigh,int low,int high,int pos){
    if(qlow<=low && qhigh>=high){
        return tree[pos];
    }
    if(qlow>high || qhigh<low){
        return 100000;
    }
    int mid = (low+high)/2;
    return min(rangeMinArray(tree,qlow,qhigh,low,mid,2*pos+1),
               rangeMinArray(tree,qlow,qhigh,mid+1,high,2*pos+2));
}

void update(int streeindex,int low,int high,int index,int x){
    if(low==high){
        tree[streeindex]  = x;
        return;
    }
    if(index<=(low+high)/2)
        update(2*streeindex + 1,low,(low+high)/2,index,x);
    else
        update(2*streeindex + 2,(low+high)/2+1,high,index,x);
    tree[streeindex] = min(tree[2*streeindex +1],tree[2*streeindex +2]);
}

int main()
{
    int i,n,pos,b,e;
    cin>>n;
    pos = 0;
    b=0;
    e=n-1;
    for(i=0;i<n;i++)cin>>a[i];
    build(pos,b,e);
    for(i=0;i<7;i++)cout<<tree[i]<<" ";
    cout<<endl;
    cout<<rangeMinArray(tree,2,3,0,3,0);
    update(0,0,3,3,-1);
    cout<<rangeMinArray(tree,2,3,0,3,0);
}
