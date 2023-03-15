#include <iostream>

int n;
int **matrix = new int*[n];

using namespace std;

void enterMatrix() {
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void deleteMatrix() {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void printMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void changeStrokeInMatrix() {
    int len = n;

    for (int i = 1; i < len; i++) {
        int* tmp = matrix[i];
        matrix[i] = matrix[i - 1];
        matrix[i - 1] = tmp;

        if (i == len - 1) {
            i = 0;
            len--;
        }
    }
}


int main() {
    cout << "Enter n:";
    cin >> n;

    enterMatrix();
    cout << "Old Matrix:\n";
    printMatrix();
    changeStrokeInMatrix();
    cout << "New Matrix:\n";
    printMatrix();
    deleteMatrix();

    return 0;
}
