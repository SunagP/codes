#include<list>
#include<map>
#include<queue>
#include<iostream>
#include<fstream>
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
             map<t,t> shortPath;
            t shortPath2[5];
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
             void adjList();
             int edgeLen(t a,t b);
             int In(t y);
            void findShortPath(t a,t b);
            void calculatePrice(t a,t b);
            friend class driver;
            friend class passenger;
};
template<typename t>
void graph<t>::findShortPath(t a,t b)
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
template<typename t>
void graph<t>::calculatePrice(t a,t b)
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
                 int price=0;
                for(int i=0;shortPath2[i]!=a;i++)
                {
                    price+=10*edgeLen(shortPath2[i],shortPath2[i+1]);
                }
                cout<<endl<<price<<endl;
            }
template<typename t>
int graph<t>:: In(t y)
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
template<typename t>
 int graph<t>::edgeLen(t a,t b)
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
template<typename t>
 void graph<t>::adjList()
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


