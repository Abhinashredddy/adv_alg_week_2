#include<iostream>
using namespace std;

class SparseNode {
public:
    int row;
    int col;
    int data;
    SparseNode* next;

    SparseNode(int r, int c, int val) : row(r), col(c), data(val), next(nullptr) {}
};

void createNode(SparseNode*& head, int rowIdx, int colIdx, int value) {
    SparseNode* newNode = new SparseNode(rowIdx, colIdx, value);

    if (head == nullptr) {
        head = newNode;
    } else {
        SparseNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printSparseMatrix(SparseNode* head) {
    SparseNode* current = head;

    cout << "Row indices: ";
    while (current != nullptr) {
        cout << current->row << " ";
        current = current->next;
    }
    cout << endl;

    current = head;
    cout << "Column indices: ";
    while (current != nullptr) {
        cout << current->col << " ";
        current = current->next;
    }
    cout << endl;

    current = head;
    cout << "Data values: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    int numRows, numCols;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    int** sparseMatrix = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        sparseMatrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            cout << "Enter value for position (" << i << ", " << j << "): ";
            cin >> sparseMatrix[i][j];
        }
    }

    SparseNode* sparseList = nullptr;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (sparseMatrix[i][j] != 0) {
                createNode(sparseList, i, j, sparseMatrix[i][j]);
            }
        }
    }

    printSparseMatrix(sparseList);

    for (int i = 0; i < numRows; i++) {
        delete[] sparseMatrix[i];
    }
    delete[] sparseMatrix;

    SparseNode* current = sparseList;
    while (current != nullptr) {
        SparseNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
