#include <iostream>
using namespace std;

const int n = 8;
double x[n] = {1,2,3,4,5,6,7,8};
double y[n] = {1.5577,1.2131,0.9447,0.7358,0.5730,0.4462,0.3476,0.2706};
double sx = 0, sy = 0, sxy = 0, sx2 = 0;
void fungsi(double &a1,double &a0){
    for(int i = 0; i < n; i++){
    sx  += x[i];
    sy  += y[i];
    sxy += x[i] * y[i];
    sx2 += x[i] * x[i];
    }
    double D  = n * sx2 - sx * sx;
        a1 = (n * sxy - sx * sy) / D;
        a0 = (sx2 * sy - sx * sxy) / D;
}
int main() {
    double b0,b1;
    fungsi(b1,b0);
    cout << "Model Linear (y = a0 + a1x)\n";
    cout << "a0 = " << b0 << endl;
    cout << "a1 = " << b1 << endl;
}
