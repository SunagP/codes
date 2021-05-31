#include <iostream>
#include <list>

using namespace std;
int c = 1;
class Graph {
  int n;
  list<int>* adj;
  

  public:
  int* visited;
  Graph(int v) {
  n = v;
  adj = new list<int>[v];
}
  void addEdge(int src, int dest);
  void DFS(int start,int * visited);
  

 
};

void Graph::addEdge(int src, int dest) {
  adj[src].push_back(dest);
  adj[dest].push_back(src);
}
list<int> s;
void Graph::DFS(int start,int* visited){
    if(visited[start]==0){
  visited[start] = 1;
  cout<<" "<<start<<" ";
  s.push_front(start);
}
   int flag=0;
  for(auto i:adj[start]){
    if(visited[i]==0){
    //   cout<<" "<<i<<" ";
      s.push_front(i);
    //   visited[i]=1;
      DFS(i,visited);
      flag=1;
      return;

    }
    // if(flag==0)
    // {
    //     s.pop_back();
    //     if(s.empty()){

    //     }
    // }
  }
}



int main() {
    int n;
    cout<<"number of vertices and edges ";
    int v,e;
    cin>>v;
    cin>>e;
    
  Graph g(v);
  g.visited = new int[n];
  for (int i = 0; i < n; i++)
    g.visited[i] = 0;
  
for(int i=0;i<e;i++){
    cout<<"Enter src and dest of edge "<<i+1<<" : ";
    int src,dest;
    cin>>src;
    cin>>dest;
    g.addEdge(src,dest);
}

  
  cout<<"Enter starting vertex : ";
  int s ;
  cin>>s;
  
    g.DFS(s,g.visited);
 
    return 0;
}