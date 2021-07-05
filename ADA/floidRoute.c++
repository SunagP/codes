#include<iostream>
#include<cmath>
using namespace std;

void print(int n, int matrix[][10])
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i][j] == 999){
                cout << " INF ";
            }
            else
               cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void floyds(int n, int matrix[][10])
{
    int route[10][10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                route[i][j]=0;
            else
            {
                route[i][j]=j;
            }
        }
    }
    cout << "Route Matrix :\n";
    print(n, route);

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i][j] > (matrix[i][k] + matrix[k][j]) && (matrix[i][k]!=999 && matrix[k][j] !=999)){
                    matrix[i][j]=matrix[i][k] + matrix[k][j];
                    route[i][j]=k;
                }
            }
        }
    cout << "\nD(" << k <<") : \n";
    print(n, matrix);
    }
    cout << "All pairs shortest path matrix :\n";
    print(n, matrix);

    cout << "Route Matrix :\n";
    print(n, route);
}

int main()
{
    int n, matrix[10][10];
    cout << "Enter no of vertices : "; cin >> n;
    cout << "Enter matrix elements (999 for INFINITY) \n";
    for(int i=1;i<=n;i++){
        cout << "Row " << i << " elements : ";
        for(int j=1;j<=n;j++){
            cin >> matrix[i][j];
        }
    }
    cout << "D(0) :\n";
    print(n, matrix);

    floyds(n,matrix);

    return 0;
}