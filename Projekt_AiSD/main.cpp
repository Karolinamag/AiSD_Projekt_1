#include <iostream>
#include <ctime>
using namespace std;

void GenerowanieTablic (int ListaLiczb[]) {

srand((unsigned) time(0));

for (int j=0; j<10; j++){
    ListaLiczb[j]=((rand() % 20)-10 );
}
}

void GlownaFunkcjaPrzesuwania (int ListaLiczb[]){

for (int j=0; j<10; j++){
    if(ListaLiczb[j]<0){cout<<ListaLiczb[j]<<endl;}
}


}

int main()
{
    int Tablica[10];
    GenerowanieTablic(Tablica);

cout<<"Wygenerowana Tabica = [ ";
for (int j=0; j<10; j++){
    cout <<Tablica[j]<<" ";
}
cout<<"]"<<endl;


GlownaFunkcjaPrzesuwania(Tablica);


    return 0;
}
