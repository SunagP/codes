#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int count = 0;
class Edge{
public:
    int src;
    int dest;
    int wt;
};

bool compare(Edge e1,Edge e2){
   
    return e1.wt<e2.wt;
}

int getParent(int v,int parent[]){
    //  count++;
    if(parent[v]==v){

        return v;

    }

    return getParent(parent[v],parent);

}

 int main(){

    int n,E,w=0;
    cout<<"Enter number vertices and edges\n";
    cin>>n>>E;

    Edge edges[E];
    cout<<"Enter source destination and weight for each edge\n";
    for(int i=0;i<E;i++){

        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;

    }
    //Kruskal algo

    //sorted the edges array in increasing order

    sort(edges,edges+E,compare);

    Edge output[n-1];

    //Union find algorithm to detect cycle

    int parent[n];

    for(int i=0;i<n;i++){

        parent[i]=i;

    }

    int count=0;

    int i=0;

    while(count<n-1){

        Edge currentEdge=edges[i];

        int p1=getParent(currentEdge.src,parent);

        int p2=getParent(currentEdge.dest,parent);

        if(p1!=p2){
            output[count]=currentEdge;
            count++;
            parent[p1]=p2;
        }
        i++;
    }
    //Printing the MST
    cout<<"\n"<<endl;
    for(int i=0;i<n-1;i++){

        if(output[i].src<output[i].dest){

            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].wt<<endl;
            w = w + output[i].wt;
        }
        else
        { cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].wt<<endl;
        w = w + output[i].wt;
        }

    }
  cout << "cost of minimal spanning tree " << w << endl;
    return 0;

}