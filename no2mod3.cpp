#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
    const int n = 8;
    double x[n] = {1,2,3,4,5,6,7,8};
    double y[n] = {1.5577,1.2131,0.9447,0.7358,0.5730,0.4462,0.3476,0.2706};
    double sum_x = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0;
    double sum_y = 0.0, xy = 0.0, x2y = 0.0;
int main() {
    for (int i = 0; i < n; ++i) {
        double xi = x[i];
        double yi = y[i];
        sum_x += xi;
        x2 += pow(xi,2);
        x3 += pow(xi,3);
        x4 += pow(xi,4);
        sum_y += yi;
        xy += xi * yi;
        x2y += xi * xi * yi;
    }
    double A[3][3] = {
        {x4, x3, x2},
        {x3, x2, sum_x },
        {x2, sum_x,  n    }
    };
    double B[3] = {x2y, xy, sum_y};
    double aug[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            aug[i][j] = A[i][j];
        }
        aug[i][3] = B[i];
    }
    for (int k = 0; k < 2; ++k) {
        int max_row = k;
        for (int i = k + 1; i < 3; ++i) {
            if (abs(aug[i][k]) > abs(aug[max_row][k])) {
                max_row = i;
            }
        }
        if (max_row != k) {
            for (int j = 0; j < 4; ++j) {
                double temp = aug[k][j];
                aug[k][j] = aug[max_row][j];
                aug[max_row][j] = temp;
            }
        }
        for (int i = k + 1; i < 3; ++i) {
            double factor = aug[i][k] / aug[k][k];
            for (int j = k; j < 4; ++j) {
                aug[i][j] -= factor * aug[k][j];
            }
        }
    }
    double a[3]; // a0, a1, a2
    for (int i = 2; i >= 0; --i) {
        a[i] = aug[i][3];
        for (int j = i + 1; j < 3; ++j) {
            a[i] -= aug[i][j] * a[j];
        }
        a[i] /= aug[i][i];
    }
    cout << fixed << setprecision(6);
    cout << "Hasil Regresi Kuadratik: y = a0*x^2 + a1*x + a2 adalah: \n" << endl;
    cout << "y = " << a[0] << "x^2 + " << a[1] << "x + " << a[2] << endl;

    return 0;
}