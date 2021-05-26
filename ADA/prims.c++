#include<iostream>
using namespace std;
const int V=6;
// int V;
 
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

int printMST(int path[], int cost[V][V])  
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
        {
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
	cout<<"Enter cost matrix for 6 vetices";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {   
			cin>>c[i][j];
        }
    }
	findMST(c);  
    

    return 0;  
}