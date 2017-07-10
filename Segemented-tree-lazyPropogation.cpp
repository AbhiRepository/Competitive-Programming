#include<iostream>
using namespace std;
const int MAX = 1e6;

// here 0 means all tails up
int sgtree[3*MAX] = {0},LazyTree[3*MAX] = {0};

//lazy query function
int LazyQuery(int stIndex,int b,int e,int qb,int qe){

    // NO OVERLAP
    if(qb>e || qe<b)return 0;

    if(LazyTree[stIndex]==1){  //here one means Tree has pending Update
        sgtree[stIndex] = (e-b+1) - sgtree[stIndex]; //new head = total length in interval - old head
        if(b!=e){ //not a leaf node
            LazyTree[2*stIndex+1] = 1 - LazyTree[2*stIndex+1];
            LazyTree[2*stIndex+2] = 1 - LazyTree[2*stIndex+2];
        }
        LazyTree[stIndex] = 0;// putting it it previous form
    }

    //TOTAL OVERLAP
    if(qb<=b && qe>=e)return sgtree[stIndex];

    //PARTIAL OVERLAP
    int x = LazyQuery(2*stIndex+1,b,(b+e)/2,qb,qe);
    int y = LazyQuery(2*stIndex+2,(b+e)/2+1,e,qb,qe);
    return x+y;
}

void LazyUpdate(int stIndex,int b,int e,int qb,int qe){

    if(LazyTree[stIndex] == 1){ // taking care of old update
        sgtree[stIndex] = (e-b+1) - sgtree[stIndex];

        if(b!=e){
            LazyTree[2*stIndex+1] = 1 - LazyTree[2*stIndex+1];
            LazyTree[2*stIndex+2] = 1 - LazyTree[2*stIndex+2];
        }
        LazyTree[stIndex] = 0;
    }
    // NO OVERLAP
    if(qb>e || qe <b)return ;

    //TOTAL OVERLAP
    if(b >= qb && e <= qe){
        sgtree[stIndex] = (e-b+1)-sgtree[stIndex];
        if(b!=e){
            LazyTree[2*stIndex+1] = 1 - LazyTree[2*stIndex+1];
            LazyTree[2*stIndex+2] = 1 - LazyTree[2*stIndex+2];
        }
        return;
    }

    //PARTIAL OVERLAP
    LazyUpdate(2*stIndex+1,b,(b+e)/2,qb,qe);
    LazyUpdate(2*stIndex+2,((b+e)/2)+1,e,qb,qe);
    sgtree[stIndex] = sgtree[2*stIndex+1] + sgtree[2*stIndex+2];
}



int main(){
    int n,q,x,y,i;
    cin>>n>>q;
    while(q--){
        cin>>i;
        if(i){
            cin>>x>>y;
            cout<<LazyQuery(0,0,n-1,x,y)<<endl;
        }else{
            cin>>x>>y;
            LazyUpdate(0,0,n-1,x,y);
        }

    }

}
