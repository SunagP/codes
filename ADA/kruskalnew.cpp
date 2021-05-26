#include<iostream>
#include<math.h>
#include<sstream>
#include<map>
#include<list>
using namespace std;
long int count=0;
class edge
{
    public:
    string source;
    string destination;
    int weight;
};
class graph
{
    public:
    map<string,int> vertex;
    list<string>* group;
    edge* e;
    edge addEdge(string,string,int);
    void addVertex(string);
    void minSpanTree(graph,int,int,int);
    void merge_sort(edge *a,int low,int high);
    void merge(edge *a,int low,int mid,int high);
};
void graph:: merge(edge *a,int low,int mid,int high)
{
    edge *temp=new edge[high-low+1];
    int i,j,k,x=0;
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid&&j<=high)
    {
        count++;
        if(a[i].weight<=a[j].weight)
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while (j<=high)
    {
        count++;
        temp[k]=a[j];
        k++;
        j++;
    }
    while (i<=mid)
    {
        count++;
        temp[k]=a[i];
        k++;
        i++;
    }
    for (int i = low; i < high+1; i++)
    {
        a[i]=temp[x];
        x++;
    }
}
void graph:: merge_sort(edge *a,int low,int high)
{
    if(low<high)
    {
        int mid=(high+low)/2;
        this->merge_sort(a,low,mid);
        this->merge_sort(a,mid+1,high);
        this->merge(a,low,mid,high);
    }
}
edge graph::addEdge(string s,string d,int w)
{
    edge e;
    e.source=s;
    e.destination=d;
    e.weight=w;
    return e;
}
void graph::addVertex(string nm)
{
    this->vertex[nm]=-1;
}
void graph::minSpanTree(graph g,int l,int h,int n)
{
    int gr=0,i=0,j=0,cost=0;
    g.merge_sort(g.e,l,h);
    // cout<<"edges after sorting:"<<endl;
    // for(int i=0;i<h+1;i++)
    // {
    //     cout<<"("<<g.e[i].source<<","<<g.e[i].destination<<","<<g.e[i].weight<<")"<<endl;
    // }
    cout<<"edges in minimum spanning tree :"<<endl;
    while(i<n-1)
    {
        count++;
       if(g.vertex[g.e[j].source]==-1&&g.vertex[g.e[j].destination]==-1)
       {
            cout<<"("<<g.e[j].source<<","<<g.e[j].destination<<","<<g.e[j].weight<<")"<<endl;
            g.group[gr].push_back(g.e[j].source);
            g.group[gr].push_back(g.e[j].destination);
            g.vertex[g.e[j].source]=gr;
            g.vertex[g.e[j].destination]=gr;
            gr++;
            cost=cost+g.e[j].weight;
            i++;
            j++;
       }
       else if(g.vertex[g.e[j].source]==-1)
       {
            cout<<"("<<g.e[j].source<<","<<g.e[j].destination<<","<<g.e[j].weight<<")"<<endl;
            g.group[g.vertex[g.e[j].destination]].push_back(g.e[j].source);
            g.vertex[g.e[j].source]=g.vertex[g.e[j].destination];
            cost=cost+g.e[j].weight;
            i++;
            j++;
       }
       else if(g.vertex[g.e[j].destination]==-1)
       {
            cout<<"("<<g.e[j].source<<","<<g.e[j].destination<<","<<g.e[j].weight<<")"<<endl;
            g.group[g.vertex[g.e[j].source]].push_back(g.e[j].destination);
            g.vertex[g.e[j].destination]=g.vertex[g.e[j].source];
            cost=cost+g.e[j].weight;
            i++;
            j++;
       }
       else
       {
           if(g.vertex[g.e[j].source]!=g.vertex[g.e[j].destination])
           {
                cout<<"("<<g.e[j].source<<","<<g.e[j].destination<<","<<g.e[j].weight<<")"<<endl;
                for(auto i:g.group[g.vertex[g.e[j].source]])
                {
                    g.vertex[i]=g.vertex[g.e[j].destination];
                    count++;
                }
                cost=cost+g.e[j].weight;
                i++;
                j++;
           }
           else
           {
               j++;
           }
       }
    }
    cout<<"cost of minimum spanning tree is : "<<cost;

}
int main()
{
    int n,m;
    graph g;
    cout<<"enter number of vertices: "<<endl;
    cin>>n;
    // cout<<"enter number of edges: "<<endl;
    // cin>>m;
    m=n*(n-1);
    g.e=new edge[m];
    g.group=new list<string>[n];
    for(int i=0;i<n;i++)
    {
        string name;
        stringstream ss;
        ss<<i;
        ss>>name;
        g.addVertex(name);
    }
    for(int i=0;i<n;i++)
    {
        string name;
        stringstream ss;
        ss<<i;
        ss>>name;
        for(int j=0;j<n-1;j++)
        {
            string name1;
            stringstream ss1;
            ss1<<i+j;
            ss1>>name1;
            g.e[i]=g.addEdge(name,name1,i+j);
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     string name;
    //     cout<<"enter name of vertex "<<i+1<<" : "<<endl;
    //     cin>>name;
    //     g.addVertex(name);
    // }
    // for(int i=0;i<m;i++)
    // {
    //     string s,d;
    //     int w;
    //     cout<<"edge"<<i+1<<" : "<<endl;
    //     cout<<"enter source"<<" : "<<endl;
    //     cin>>s;
    //     cout<<"enter destination"<<" : "<<endl;
    //     cin>>d;
    //     cout<<"enter weight"<<" : "<<endl;
    //     cin>>w;
    //     g.e[i]=g.addEdge(s,d,w);
    // }
    // cout<<"vertices:"<<endl;
    // for(auto i=g.vertex.begin();i!=g.vertex.end();i++)
    // {
    //     cout<<i->first<<endl;
    // }
    // cout<<"edges:"<<endl;
    // for(int i=0;i<m;i++)
    // {
    //     cout<<"("<<g.e[i].source<<","<<g.e[i].destination<<","<<g.e[i].weight<<")"<<endl;
    // }
    g.minSpanTree(g,0,m-1,n);
    cout<<"\nm^2--"<<(float)count/(m*m)<<"\nmlogm--"<<(float)count/(m*log(m))<<"\nm--"<<(float)count/(m)<<endl;

    return 0;
}