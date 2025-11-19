#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

   const int n = 8;
   double x[n] = {1,2,3,4,5,6,7,8};
   double y[n] = {1.5577,1.2131,0.9447,0.7358,0.5730,0.4462,0.3476,0.2706};

   double sum_ln_x = 0.0, sum_ln_y = 0.0;
   double sum_ln_x2 = 0.0, sum_ln_x_ln_y = 0.0;

int main() {
   for (int i = 0; i < n; ++i) {
      double ln_x = log(x[i]);
      double ln_y = log(y[i]);

      sum_ln_x += ln_x;
      sum_ln_y += ln_y;
      sum_ln_x2 += ln_x * ln_x;
      sum_ln_x_ln_y += ln_x * ln_y;
   }

   double denom = n * sum_ln_x2 - sum_ln_x * sum_ln_x;
   if (abs(denom) < 1e-12) {
      cout << "Error: data tidak cukup bervariasi untuk regresi." << endl;
      return 1;
   }

   double b = (n * sum_ln_x_ln_y - sum_ln_x * sum_ln_y) / denom;
   double A = (sum_ln_y - b * sum_ln_x) / n;

   double a = exp(A);

   cout << fixed << setprecision(6);
   cout << "Model regresi: y = a * x^b" << endl;
   cout << "y = " << a << "* x^" << b <<endl;

   return 0;
}