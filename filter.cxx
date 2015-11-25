#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

   
         
using namespace std;

void reading(double*, const int, const string);
void filter(double*,const int);
void print(double*,const int);
void print_f(const double*, const int,const string);



int main(void){
    const int N = 236; // Ich weiss noch nicht wie ich die Anz. der Daten zählen kann
    const string filename = "noisy.txt"; //aus dieser Datei ablesen
    const string file_out = "filtered1.txt";
    
    double* f = new double[N];
    reading(f,N,filename);
    filter(f,N);
    print(f,N);

    print_f(f,N,file_out);
    delete[] f;
}

void reading(double* f,const int N, const string fname){
    ifstream in(fname.c_str()); // eine Reihe von Files erschaffen
    for(int i=0; i<N; i++){
        in >> f[i];//den inhalt von in's in das Array packen
        
    }
    in.close(); // den Spass wieder schließen
}

void filter(double* f,const int N){
   int a=f[0];
   int b=f[N];
   int c=f[N-1];
   int d=f[1];
   int temp = f[0];
   
   for(int i=1; i<N-1; i++){
        f[i]=(temp+f[i]+f[i+1])/3.0;
        temp=f[i];
    }
    
    f[0]=(a+b+d)/3;
    f[N]=(a+b+c)/3;
}

void print(double* f, const int N){
    for(int i=0; i<N; i++){
        cout << f[i] << endl;
    }
}
    
void print_f(const double* f, const int N,const string file_out){
    ofstream out(file_out.c_str());
    for(int i=0;i<N;i++){
        out << f[i] << endl;
    }
    out.close();
}