#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const int n = 4;
    double x[n] = {3, 4, 5, 6};
    double y[n] = {0.9447, 0.7358, 0.5730, 0.4462};

    double dd[n][n];

    for (int i = 0; i < n; ++i) {
        dd[i][0] = y[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    double x_eval = 4.5;
    double result = dd[0][0];

    double term = 1.0;
    for (int i = 1; i < n; ++i) {
        term *= (x_eval - x[i-1]);
        result += dd[0][i] * term;
    }

    cout << fixed << setprecision(6);
    cout << "Interpolasi Newton (Beda Terbagi) di x = " << x_eval << endl;
    cout << "Menggunakan titik: ";
    for (int i = 0; i < n; ++i) {
        cout << "(" << x[i] << ", " << y[i] << ") ";
    }
    cout << "\nHasil: y(" << x_eval << ") = " << result << endl;

    return 0;
}