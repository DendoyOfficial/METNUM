#include <stdlib.h>
#include <iostream>
#include<iomanip>
using namespace std;

double kal, s, hasil;
int i, j, k;


int main() {
double matrix[10][10] = {{2, 7, 4, 9, 3, 6, 2, 8, 9, 4}, {7, 4, 1, 3, 2, 5, 2, 1, 2, 2}, {5, 3, 1, 5, 6, 2, 1, 3, 2, 2}, 
{3, 4, 1, 1, 2, 1, 2, 3, 7, 4},{3, 6, 1, 7, 2, 1, 2, 9, 2, 1}, {6, 2, 2, 1, 1, 3, 7, 3, 4, 4}, {5, 2, 1, 8,
3, 7, 1, 4, 3, 3}, {7, 2, 3, 1, 2, 4, 3, 9, 6, 2}, {9, 5, 1, 3, 1, 4, 7, 1,2, 6}, {4, 2, 2, 1, 7, 1, 2, 5, 1, 3}};

double identitas[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0,0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 1, 0, 0, 0, 0,0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0,0, 0, 0, 0, 0, 1, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0,0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

double v;
cout << "Berapa digit NIM terakhir anda: "; cin >> v;
v *= -1; 

double vektor[10] = {1, -1, 1, -1, 1, -1, 1, -1, 1, v};

cout << "======= TAMPILAN MATRIX =======" << endl << endl;
for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
        cout << "" << matrix[i][j] << " ";
    }
    cout << endl;
}
cout << endl;

for (k = 0; k < 10; k++) {
    s = matrix[k][k];
    for (j = 0; j < 10; j++) {
        matrix[k][j] = (matrix[k][j] / s);
        identitas[k][j] = (identitas[k][j] / s);
    }
vektor[k] = vektor[k] / s;
    for (i = 0; i < 10; i++) {
        if (i != k) {
            kal = matrix[i][k];
            for (j = 0; j < 10; j++) {
            matrix[i][j] = (matrix[i][j] - (kal * matrix[k][j]));
            identitas[i][j] = (identitas[i][j] - (kal *identitas[k][j]));
            }
            vektor[i] = (vektor[i] - (kal * vektor[k]));
        }
    }
}
cout << endl << endl << "======= TAMPILAN SETELAH DIUBAH MENGGUNAKAN OBE =======" << endl << endl;
    
    for (int i = 0; i < 10; i++) {
        cout << "| ";
        for (int j = 0; j < 10; j++) {
            cout << setw(12) << fixed << setprecision(6) << identitas[i][j];
        }
        cout << " |" << endl;
    }

cout << endl;

cout << "======= MATRIX IDENTITAS =======" << endl<< endl;

for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
    cout << setw(12) << fixed << setprecision(6) << matrix[i][j] << " ";
    }
    cout << endl;
}
cout << endl;


cout << "======= HASIL SOLUSI DENGAN METODE INVERS ======= "<<endl<<endl;

for(i=0;i<10;i++) cout << "x" << i+1 << " = " << vektor[i] << endl;
system("pause");
}