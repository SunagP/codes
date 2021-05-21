/*There are 8 teams participating in IPL. 
Currently there are certain set of matches played.
 Match Number and participating teams are given as input. 
 Make the list of teams which have not yet played any match.*/

#include<iostream>
#include<sstream>
#include<map>
using namespace std;
long int count=0;

class edge
{
    public : string team1,team2;
             int Mno;
};
class graph
{
    public :
    edge *e;
    map<string,int> vertex;
    edge addEdge(string,string,int);
    void addVertex(string);
    void minSpanTree();
};
edge graph::addEdge(string s,string d,int w)
{
    edge e;
    e.team1=s;
    e.team2=d;
    e.Mno=w;
    this->vertex[s]=1;
    this->vertex[d]=1;
    return e;
}
void graph::addVertex(string v)
{
    this->vertex[v]=0;
}
int main()
{
    int n,m,flag=0;
    graph g;
    cout<<"enter number of teams: "<<endl;
    cin>>n;
    cout<<"enter number of matches played: "<<endl;
    cin>>m;
    // m=n*(n-1);
    g.e=new edge[m];
    // for(int i=0;i<n;i++)
    // {
    //     string name;
    //     stringstream ss;
    //     ss<<i;
    //     ss>>name;
    //     g.addVertex(name);
    // }
    // for(int i=0;i<n;i++)
    // {
    //     string name;
    //     stringstream ss;
    //     ss<<i;
    //     ss>>name;
    //     for(int j=0;j<n-1;j++)
    //     {
    //         string name1;
    //         stringstream ss1;
    //         ss1<<i+j;
    //         ss1>>name1;
    //         g.e[i]=g.addEdge(name,name1,i+j);
    //     }
    // }
    for(int i=0;i<n;i++)
    {
        string name;
        cout<<"enter name of team "<<i+1<<" : "<<endl;
        cin>>name;
        g.addVertex(name);
    }
    cout<<"\nenter list of matches played"<<endl;
    for(int i=0;i<m;i++)
    {
        string s,d;
        int w;
        cout<<"enter match number"<<" : "<<endl;
        cin>>w;
        cout<<"enter team1"<<" : "<<endl;
        cin>>s;
        cout<<"enter team2"<<" : "<<endl;
        cin>>d;
        g.e[i]=g.addEdge(s,d,w);
    }
    cout<<"teams:"<<endl;
    for(auto i=g.vertex.begin();i!=g.vertex.end();i++)
    {
        cout<<i->first<<endl;
    }
    cout<<"matches played(team1,team2,match number):"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"("<<g.e[i].team1<<","<<g.e[i].team2<<","<<g.e[i].Mno<<")"<<endl;
    }
    cout<<"teams that have not played:"<<endl;
    for(auto i=g.vertex.begin();i!=g.vertex.end();i++)
    {
       if(i->second==0)
       {
           cout<<i->first<<endl;
           flag=1;
       }
    } 
    if(flag==0)
    {
        cout<<"all teams have played atleast one match"<<endl;
    }
    // g.minSpanTree(g,0,m-1,n);
    // cout<<"\nno of edges--"<<m<<endl;
    // cout<<"\ncount--"<<count<<endl;
    // cout<<"\nm^2--"<<(float)count/(m*m)<<"\nmlogm--"<<(float)count*log(2)/(m*log(m))<<"\nm--"<<(float)count/(m)<<endl;

    return 0;
}