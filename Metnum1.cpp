#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double fx(double x)
{return  pow(x,2) - (2 * x) - pow(x,3) + (x + 2) * (exp(-2 * x));}

void pagar(char a,int jumlah){for(int i=0;i<jumlah;i++){cout << a;}}
void spasi(const string &text, int lebar) { 
    int padding = (lebar - text.length()) / 2;  
    cout << setw(padding + text.length()) << text; 
}

void header(){
    cout << string(92, '-') << endl; 
    spasi("Iterasi", 10); cout << " |";  
    spasi("a", 17); cout << " |";  
    spasi("b", 17); cout << " |";  
    spasi("fa", 17); cout << " |";  
    spasi("fb", 17); cout << " |";  
    spasi("x", 17); cout << " |";  
    spasi("fx", 17); cout << " |";  
    spasi("Error Relatif", 15); cout << " |" << endl; 
    cout << string(92, '-') << endl;
}

int main(){
    double a,b,relatiferror,xt = 0.0, fxt = 0.0, error = 0.0,toleransiError;
    int iterasiMax, i=0; 

    cout << "***********PENYELESAIAN PERSAMAAN NON-LINEAR METODE REGULA   FALSI************" <<  endl; 
    cout << "Input nilai a = "; cin >> a; 
    cout << "Input nilai b = "; cin >> b; 
cout << "Input toleransi error = "; cin >> toleransiError; 
    cout << "Input iterasi maksimal N = "; cin >> iterasiMax; 
    cout << "Tabel penyelesaian dengan metode regula falsinya sebagai berikut.\n";
    double fa = fx(a); 
    double fb = fx(b); 
    double x0 = a;  
    if (i == 0) {header();} 
    if((fa*fb) > 0){ 
        cout << "Maaf, tidak ada penyelesaian dengan input tersebut" << endl;  
    }else{ 
        while (i < iterasiMax){ 
            xt = (fb*a - fa*b) / (fb - fa); 
            fxt = fx(xt); 
            error = abs(fxt); 
            cout << fixed << setprecision(10); 
    spasi(to_string(i), 15); cout << " |";  
    spasi(to_string(a), 10); cout << " |";  
    spasi(to_string(b), 10); cout << " |";  
    spasi(to_string(fa), 10); cout << " |";  
    spasi(to_string(fb), 10); cout << " |";  
    spasi(to_string(xt), 10); cout << " |";  
    spasi(to_string(fxt), 10); cout << " |";  
    spasi(to_string(error), 20); cout << " |" << endl;
            if ((fxt * fa) < 0){ 
                b = xt; 
                fb = fxt; 
            }else{ 
                a = xt; 
                fa = fxt; 
            }if (error <= toleransiError) {break;} 
            x0 = xt; 
            i++;          
        } 
        cout << string(92, '-') << endl << endl; 
        cout << "***********KESIMPULANANNYA************" << endl << endl; 
        cout << "Titik Potongnya ada pada interval awal [" << a << " " << xt << "]" << endl;
        cout << "Salah satu akarnya adalah " << xt << endl; 
        cout << "Error Relatif-nya adalah " << error << endl; 
        cout << "Berada pada iterasi ke-" << i << endl << endl; 
    } 
    return 0;
}
    