#include<iostream>
using namespace std;

int main() {
    int m, n, count = 0;
    cout << "Enter the dimensions of the matrix row and column (space seperated): ";
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 0) {
                count++;
            }
        }
    }

    int **sparse = new int*[3];
    for(int i = 0; i < 3; i++) {
        sparse[i] = new int[count];
    }

    int k = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] != 0) {
                sparse[0][k] = i;
                sparse[1][k] = j;
                sparse[2][k] = arr[i][j];
                k++;
            }
        }
    }

    cout << "Sparse Matrix: " << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<count; j++) {
            cout << sparse[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < m; i++) {
        delete [] arr[i];
    }
    delete [] arr;

    for(int i = 0; i < 3; i++) {
        delete [] sparse[i];
    }
    delete [] sparse;

    return 0;
}
