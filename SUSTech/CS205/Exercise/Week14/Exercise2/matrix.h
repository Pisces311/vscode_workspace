#pragma once

#include <iostream>
using namespace std;

#define MAXROWS 5
#define MAXCOLS 5

template <class T>
class Matrix {
    T matrix[MAXROWS][MAXCOLS];
    int rows;
    int cols;

   public:
    Matrix(int r, int c) : rows(r), cols(c) {}

    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void setMatrix(T array[][MAXCOLS]) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = array[i][j];
            }
        }
    }

    void addMatrix(T array[][MAXCOLS]) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += array[i][j];
            }
        }
    }
};