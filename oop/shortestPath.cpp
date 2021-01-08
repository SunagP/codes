#include<iostream>
using namespace std;
string places[5];
int value[5]={INT16_MAX};
struct edge
{
    string v1,v2;
    int dist;
}E[7];
string shortestPath[5];
int min(int x,int y)
{
    if(x<y)
    {
        return x;
    }
    return y;
}
int edgeLen(string m,string n)
{
    for(int i=0;i<7;i++)
    {
        if((E[i].v1==m||E[i].v2==m)&&(E[i].v1==n||E[i].v2==n))
        {
            return E[i].dist;
        }
    }
    return INT16_MAX;
}
int In(string y)
{
    for(int i=0;i<5;i++)
    {
        if(shortestPath[i]==y)
        {
            return 1;
        }
    }
    return 0;
}
void findShortPath(string a,string b)
{
    string current=a;
    int j=1;
    shortestPath[0]=a;
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
                value[i]=min(value[i],edgeLen(current,places[i]));
            }
            if(!In(places[i]))
            {
                mini=min(value[i],mini);
            }
        }
        for(int i=0;i<5;i++)
        {
            if(!In(places[i])&&(value[i]==mini))
            {
                shortestPath[j]=places[i];
                current=places[i];
            }
        }
        j++;
    }
    }
int main()
{
    for(int i=0;i<5;i++)
    {
        value[i]=INT16_MAX;
    }
    places[0]="A";
    places[1]="B";
    places[2]="C";
    places[3]="D";
    places[4]="E";
    E[0].v1="A";
    E[0].v2="B";
    E[0].dist=6;
    E[1].v1="A";
    E[1].v2="D";
    E[1].dist=1;
    E[2].v1="B";
    E[2].v2="E";
    E[2].dist=2;
    E[3].v1="B";
    E[3].v2="D";
    E[3].dist=2;
    E[4].v1="B";
    E[4].v2="C";
    E[4].dist=5;
    E[5].v1="C";
    E[5].v2="E";
    E[5].dist=5;
    E[6].v1="D";
    E[6].v2="E";
    E[6].dist=1;
    findShortPath("A","C");
    for(int i=0;i<5;i++)
    {
        cout<<shortestPath[i]<<"-->";
    }
    return 0;
}