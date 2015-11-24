#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

   
        //es fehlt: 1 Array statt 2; die Grenzen der Arrays sind geschummelt; die Daten in einen neue Datei füttern; plotten
using namespace std;

void reading(double*, const int, const string);
void filter(double*,const int, double*);
void print(double*,const int,double*);



int main(void){
    const int N = 236; // Ich weiss noch nicht wie ich die Anz. der Daten zählen kann
    const string filename = "noisy.txt"; //aus dieser Datei ablesen
    double* f = new double[N];
    double* g = new double[N];
    reading(f,N,filename);
    filter(f,N,g);
    print(f,N,g);
    
    delete[] f;
}

void reading(double* f,const int N, const string fname){
    ifstream in(fname.c_str()); // eine Reihe von Files erschaffen
    for(int i=0; i<N; i++){
        in >> f[i];//den inhalt von in's in das Array packen
        
    }
    in.close(); // den Spass wieder schließen
}

void filter(double* f,const int N,double* g){
   for(int i=1; i<N-1; i++){
        g[i]=(f[i-1]+f[i]+f[i+1])/3.0;//jaaa, hätte ich die Aufgabestellung vollständig gelesen, hätte ich nur 1 Array erschaffen...
    }
    g[0]=f[0];
    g[N]=f[N];
}

void print(double* f, const int N, double* g){
    for(int i=0; i<N; i++){
        cout << f[i] << "\t" << g[i]<< endl;
    }
}
    
 