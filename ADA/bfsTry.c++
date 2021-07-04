#include<iostream>
#include<map>
#include<list>
#include<math.h>
using namespace std;
int count=0;
list<int> l;
class graph
{
    public :
    int n=0,m=0;
    static int components;
    map<int,list<pair<int,int>>> adj;
    static map<int,int> vertex;
    void addEdge(int,int,int,int);
    void addVertex(int);
    void BFS(graph,int);
    void adjacencyList();
    void showVertices();
};
int graph::components=1;
map<int,int> graph::vertex;
void graph::addEdge(int s,int d,int w,int dir)
{
    if(dir)
    {
        adj[s].push_back(make_pair(d,w));
    }
    else
    {
        adj[s].push_back(make_pair(d,w));
        adj[d].push_back(make_pair(s,w));
    }
}
void graph::addVertex(int v)
{
    vertex[v]=0;
}
void graph::adjacencyList()
{
    cout<<"adjacency list of graph is :"<<endl;
    for(auto a:adj)
    {
        cout<<a.first<<" -> ";
        for(auto i:a.second)
        {
            cout<<"("<<i.first<<") ";
        }
        cout<<endl;
    }
}
void graph::showVertices()
{
    cout<<"vertices of the graph :"<<endl;
    for(auto i:vertex)
        {
            cout<<"("<<i.first<<","<<i.second<<") "<<endl;
        }
}
void graph::BFS(graph g,int v)
{
    count++;
   if(g.vertex[v]==0)
   {
       g.vertex[v]=g.components;
       cout<<v<<endl;
       l.push_back(v);
   }
   int flag1=0;
   for(auto i:adj[v])
   {
       count++;
       if(g.vertex[i.first]==0)
       {
        l.push_back(i.first);
           cout<<i.first<<endl;
           g.vertex[i.first]=g.components;
           flag1=1;
       }
   }
   if(flag1==0)
   {
    l.pop_front();
       if(l.empty())
       {
           for(auto i:g.vertex)
           {
               count++;
               if(i.second==0)
               {
                   g.components++;
                   g.BFS(g,i.first);
                   return;
               }
           }
       }
       else
       {
           g.BFS(g,l.front());
           return;
       }
   }
   if(!l.empty())
   {
        l.pop_front();
        g.BFS(g,l.front());
   }
}
int main()
{
    graph g;
    int start;
    int reach;
    cout<<"enter number of vertices in graph : "<<endl;
    cin>>g.n;
    g.m=g.n*(g.n-1);
    for(int i=0;i<g.n;i++)
    {
        g.addVertex(i);
    }
    for(int i=0;i<g.n;i++)
    {
        for(int j=0;j<g.n-1;j++)
        {
            string name1;
            g.addEdge(i,j,1,0);
        }
    } 
    start=0;
    g.BFS(g,start);
     cout<<"count--"<<count<<endl;
    cout<<"\nm^2--"<<(float)count/(g.m*g.m)<<"\nmlogm--"<<(float)count*log(2)/(g.m*log(g.m))<<"\nm--"<<(float)count/(g.m)<<endl;

    return 0;
}