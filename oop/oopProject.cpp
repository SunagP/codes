#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;
template <typename t>
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
template<typename t>
class graph
{
    int v;
    public : string places[5];
             string visited[5];
             string temp[5];
             int value[5];
             graph(int v)
             {
                 this->v=v;
             }
             map<t,list<pair<t,int>>> adj;
             void addEdge(t a,t b,int c,bool d)
             {
                 adj[a].push_back(make_pair(b,c));
                 if(!d)
                 {
                     adj[b].push_back(make_pair(a,c));
                 }
             }
             void addEdge(t a,t b,int c)
             {
                adj[a].push_back(make_pair(b,c));
                adj[b].push_back(make_pair(a,c));
                 
             }
             void adjList()
             {
                 for(auto a:adj)
                 {
                     cout<<a.first<<"->"<<endl;
                     for(auto i:a.second)
                     {
                         cout<<i.first<<" "<<i.second<<" ";
                     }
                     cout<<endl;
                 }
             }
             int edgeLen(t a,t b)
             {
                 for(auto x:adj[a])
                 {
                     if(x.first==b)
                     {
                         return x.second;
                     }
                 }
                 return INT16_MAX;
             }
             int In(t y)
            {
                for(int i=0;i<5;i++)
                {
                    if(visited[i]==y)
                    {
                        return 1;
                    }
                }
                return 0;
            }
            void findShortPath(t a,t b)
            {
                t current=a;
                int j=1,miniPrev=0;
                visited[0]=a;
                temp[0]=a;
                while(current!=b)
                {
                    int mini=INT16_MAX;
                    for(int i=0;i<5;i++)
                    {
                        if(places[i]==a)
                        {
                            value[i]=0;
                        }
                        else
                        {
                            if((miniPrev+edgeLen(current,places[i]))<value[i])
                            {
                                value[i]=miniPrev+edgeLen(current,places[i]);
                                temp[i]=current;
                            }
                            
                        }
                        if(!In(places[i]))
                        {
                            mini=min(value[i],mini);
                        }
                    }
                    miniPrev=mini;
                    for(int i=0;i<5;i++)
                    {
                        if(!In(places[i])&&(value[i]==mini))
                        {
                            visited[j]=places[i];
                            current=places[i];

                        }
                    }
                    j++;
                }
                map<t,t> shortPath;
                string shortPath2[5];
                for(int i=0;i<5;i++)
                {
                    shortPath[places[i]]=temp[i];
                }
                current=b;
                int i=0;
                while(current!=a)
                {
                    shortPath2[i]=current;
                    current=shortPath[current];
                    i++;
                }
                shortPath2[i]=current;
                for(;i>=0;i--)
                {
                    cout<<shortPath2[i]<<"-->";
                }
                cout<<endl;
            }
};
int main()
{
    graph<string> g(3);
    g.addEdge("A","B",6);
    g.addEdge("C","B",5);
    g.addEdge("A","D",1);
    g.addEdge("D","E",1);
    g.addEdge("B","D",2);
    g.addEdge("E","C",5);
    // g.adjList();
    g.places[0]="A";
    g.places[1]="B";
    g.places[2]="C";
    g.places[3]="D";
    g.places[4]="E";
    for(int i=0;i<5;i++)
    {
        g.value[i]=INT16_MAX;
        g.temp[i]="A";
    }
    int x;
    string a,b;
    do
    {
        cout<<"enter 1 to travel\nenter 0 to exit"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"places--"<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<g.places[i]<<endl;
            }
            cout<<"enter starting point--";
            cin>>a;
            cout<<"enter destination--";
            cin>>b;
            cout<<"shortest path is--"<<endl;
            g.findShortPath(a,b);
        }
    } while (x);
    

    // for(int i=0;i<3;i++)
    // {
    //     cout<<g.temp[i]<<"-->";
    // }
    // cout<<endl;
    // for(int i=0;i<3;i++)
    // {
    //     cout<<g.value[i]<<"-->";
    // }
    // cout<<endl;
    // for(int i=0;i<3;i++)
    // {
    //     cout<<g.visited[i]<<"-->";
    // }
    return 0;
}
    
