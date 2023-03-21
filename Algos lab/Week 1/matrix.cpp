#include <iostream>

using namespace std;

int N = 0, size;
  
void createMatrix(int Adj[][100], int arr[][2])
{
    for (int i = 0; i < N + 1; i++){
        for (int j = 0; j < N + 1; j++){
            Adj[i][j] = 0;
        }
    }
    
    for (int i = 0; i < size; i++){
        int x = arr[i][0];
        int y = arr[i][1];
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printMatrix(int Adj[][100])
{
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cout << Adj[i][j];
        }
        cout << endl;
    }
}
  
int main()
{
  	cout << "number of vertices: "<<endl;
  	cin >> N;
  	cout << "number of relations: "<<endl;
  	cin >> size;
  	int arr[size][2];
  	for (int i = 0; i < size; i++)
  		cin >> arr[i][0] >> arr[i][1];
    int mat[N + 1][100];
  
    createMatrix(mat, arr);
    cout<<"Matrix: "<<endl;
    printMatrix(mat);
}
