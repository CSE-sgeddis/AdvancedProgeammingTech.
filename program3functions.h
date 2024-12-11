#ifndef PROGRAM3FUNCTIONS_H
#define PROGRAM3FUNCTIONS_H

int CountAboveAv(const double (*arr)[10], int rows);
void SortByCol(double (*arr)[10], int rows, int col, bool ascending);
void SortByRow(double (*arr)[10], int rows, int row, bool ascending);
double MedianInCol(double (*arr)[10], int rows, int col);
int ModeInCol(double (*arr)[10], int rows, int col, double modeArr[2]);

#endif // PROGRAM3FUNCTIONS_H

