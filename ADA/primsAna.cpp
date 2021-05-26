#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const int V=5;
// int V;
int c1 =0;
 
int minKey(int key[], bool known[])  
{ 
    int min = 999, min_index;  

    for (int v = 0; v < V; v++) { 
        if (known[v] == false && key[v] < min) { 
        	
            min = key[v];
			min_index = v;  
        }
       
    }    
    return min_index; 
    
}  

void printMST(int path[], int cost[V][V])  
{  
    int minCost=0;
	cout<<"Edge \tWeight\n";  
    for (int i = 1; i< V; i++) {
		cout<<path[i]<<" - "<<i<<" \t"<<cost[i][path[i]]<<" \n";  
		minCost+=cost[i][path[i]];
    }
	cout<<"Total cost is"<<minCost;
}  

void findMST(int cost[V][V])  
{  
    int path[V], key[V];
    bool known[V];

    
    for (int i = 0; i< V; i++) { 
        key[i] = 999;    
        known[i] = false;
        path[i]=-1;
    }    

    key[0] = 0;  
    path[0] = -1;  

    
    for (int x = 0; x < V - 1; x++) 
    {  
        int u = minKey(key, known);  
        known[u] = true;  

        
        for (int v = 0; v < V; v++)  
        {   c1++;
            if (cost[u][v]!=0 && known[v] == false && cost[u][v] < key[v])
            {  
                path[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    } 
	printMST(path, cost);  
}  
int main()  
{   
    int c[V][V];
	// cout<<"Enter cost matrix for 6 vetices";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {   
			if(i==j){
                c[i][j] = c[j][i] =0;
            }
            else{
                 c[i][j] = c[j][i] =rand()%100;
            }
        }
    }
	findMST(c);

    cout<<"count :"<<c1;
      cout<<"\nV^2 =>"<<(float)c1/(V*V)<<"\nVlogV =>"<<(float)c1/(V*(log(V)))<<"\ne =>"<<(float)c1/(V)<<endl;  
    

    return 0;  
}