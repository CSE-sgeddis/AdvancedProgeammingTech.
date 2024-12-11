#include <iostream>
#include <cmath>
#include <iomanip>
#include "program3functions.h"
#include "checkArraysMatch.h" 

int CountAboveAv(const double (*arr)[10], int rows) {
   

 double sum = 0;
    int total_elements = rows * 10;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 10; ++j) {
            sum += arr[i][j];
        }
    }
    double average = sum / total_elements;
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (arr[i][j] > average) {
                count++;
            }
        }
    }
    return count;
}

void SortByCol(double (*arr)[10], int rows, int col, bool ascending) {
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = i + 1; j < rows; ++j) {
            if (ascending ? arr[i][col] > arr[j][col] : arr[i][col] < arr[j][col]) {
                for (int k = 0; k < 10; ++k) {
                    std::swap(arr[i][k], arr[j][k]);
                }
            }
        }
    }
}

void SortByRow(double (*arr)[10], int rows, int row, bool ascending) {
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (ascending ? arr[row][i] > arr[row][j] : arr[row][i] < arr[row][j]) {
                for (int k = 0; k < rows; ++k) {
                    std::swap(arr[k][i], arr[k][j]);
                }
            }
        }
    }
}

double MedianInCol(double (*arr)[10], int rows, int col) {
    double temp[rows];
    for (int i = 0; i < rows; ++i) {
        temp[i] = arr[i][col];
    }
    // Simple bubble sort for the column elements
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = i + 1; j < rows; ++j) {
            if (temp[i] > temp[j]) {
                std::swap(temp[i], temp[j]);
            }
        }
    }
    if (rows % 2 == 0) {
        return (temp[rows / 2 - 1] + temp[rows / 2]) / 2.0;
    } else {
        return temp[rows / 2];
    }
}

int ModeInCol(double (*arr)[10], int rows, int col, double modeArr[2]) {
    int frequency[rows] = {0};
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < rows; ++j) {
            if (arr[i][col] == arr[j][col]) {
                frequency[i]++;
            }
        }
    }
    
    int maxFreq = 0;
    int modeCount = 0;
    for (int i = 0; i < rows; ++i) {
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
            modeCount = 1;
            modeArr[0] = arr[i][col];
        } else if (frequency[i] == maxFreq && modeCount == 1) {
            modeArr[1] = arr[i][col];
            modeCount = 2;
        }
    }
    
    return modeCount;
}

