#include<iostream>
#include<cmath>
#include<iomanip>
#include<string> // Tambahkan untuk to_string

using namespace std;

// Fungsi f(x) = f1(x) - f2(x) = x^2 - 2x - x^3 + (x+2)e^(-2x)
double fx(double x)
{
    return pow(x, 2) - (2 * x) - pow(x, 3) + (x + 2) * exp(-2 * x);
}

// Fungsi bantu untuk menampilkan string di tengah kolom
void print_centered(const string &text, int width) {
    // Gunakan std::left untuk perataan kiri jika input adalah numerik yang ingin terlihat rapi
    // Tapi untuk format ini, kita pakai setw saja
    cout << setw(width) << text; 
}

// Header Tabel yang diperbaiki lebarnya
void header(){
    cout << string(130, '-') << endl; 
    cout << "|" << setw(8) << "Iterasi" << " |"
         << setw(16) << "a" << " |"
         << setw(16) << "b" << " |"
         << setw(16) << "f(a)" << " |"
         << setw(16) << "f(b)" << " |"
         << setw(16) << "x_baru" << " |"
         << setw(16) << "f(x_baru)" << " |"
         << setw(16) << "Galat Relatif" << " |" << endl;
    cout << string(130, '-') << endl;
}

int main(){
    double a, b, fa, fb, xt, fxt;
    double toleransiError;
    double galatRelatif = 1.0; // Inisialisasi galat relatif yang besar
    double xt_sebelumnya = 0.0;
    int iterasiMax, i = 0; 
    
    // Perbaikan format output agar rapi
    cout << fixed << setprecision(10); 

    cout << "*********** PENYELESAIAN PERSAMAAN NON-LINEAR METODE REGULA FALSI ************" << endl; 
    cout << "Fungsi yang dicari akarnya: f(x) = x^2 - 2x - x^3 + (x+2)e^(-2x)\n";
    
    cout << "Input nilai a = "; cin >> a; 
    cout << "Input nilai b = "; cin >> b; 
    cout << "Input toleransi error (mis. 1e-4) = "; cin >> toleransiError; 
    cout << "Input iterasi maksimal N = "; cin >> iterasiMax; 
    
    fa = fx(a); 
    fb = fx(b); 
    
    cout << "Tabel penyelesaian dengan metode regula falsinya sebagai berikut.\n";
    header();

    if ((fa * fb) > 0) { 
        cout << "Maaf, f(a) dan f(b) bertanda sama. Tidak ada akar di interval tersebut." << endl; 
    } else { 
        while (i < iterasiMax) { 
            // 1. Hitung x baru
            xt = (fb * a - fa * b) / (fb - fa); 
            fxt = fx(xt); 
            
            // 2. Hitung Galat Relatif (yang lebih sesuai untuk metode tertutup)
            if (i > 0) {
                galatRelatif = abs((xt - xt_sebelumnya) / xt);
            }
            
            // 3. Tampilkan hasil iterasi
            cout << "| " << setw(6) << i + 1 << " |" // i+1 untuk nomor iterasi yang dimulai dari 1
                 << setw(16) << a << " |" 
                 << setw(16) << b << " |" 
                 << setw(16) << fa << " |" 
                 << setw(16) << fb << " |" 
                 << setw(16) << xt << " |" 
                 << setw(16) << fxt << " |" 
                 << setw(16) << (i == 0 ? "---" : to_string(galatRelatif)) << " |" << endl;
            
            // 4. Periksa kriteria penghentian
            if (i > 0 && galatRelatif <= toleransiError) {
                break;
            }
            
            // 5. Perbarui interval
            if ((fxt * fa) < 0) { 
                b = xt; 
                fb = fxt; 
            } else { 
                a = xt; 
                fa = fxt; 
            }
            
            xt_sebelumnya = xt; // Simpan nilai x sebelum iterasi berikutnya
            i++; 
        } 
        
        cout << string(130, '-') << endl << endl; 
        
        // Output Kesimpulan
        cout << "*********** KESIMPULAN ************" << endl; 
        cout << "Metode Regula Falsi telah selesai dalam " << i << " iterasi (Max: " << iterasiMax << ")." << endl;
        cout << "Dengan toleransi " << scientific << toleransiError << fixed << setprecision(10) << ", diperoleh:" << endl;
        cout << "1. Titik potong (Akar) ditemukan pada x = " << xt << endl; 
        cout << "2. Nilai f(x) pada akar (Galat Fungsional) adalah " << fxt << endl; 
        cout << "3. Galat Relatif Aproksimasi terakhir adalah " << galatRelatif << endl; 
        
        // Tambahan Kesimpulan mengenai Keberadaan Titik Potong
        cout << "\n****** KEBERADAAN TITIK POTONG ******" << endl;
        cout << "Titik potong (akar) berada di dalam interval awal [" << a << ", " << b << "]" << endl;
        cout << "dan telah dipersempit hingga berada sangat dekat dengan nilai " << xt << "." << endl;
        cout << "Nilai x ini merupakan solusi dari persamaan f1(x) = f2(x), yang berarti" << endl;
        cout << "kedua fungsi tersebut berpotongan pada absis (koordinat x) tersebut." << endl;
    } 
    return 0;
}