#include <iostream>
#include <ctime>
using namespace std;

void GenerowanieTablic (int ListaLiczb[]) {

srand((unsigned) time(0));

for (int j=0; j<10; j++){
    ListaLiczb[j]=((rand() % 20)-10 );
}

cout<<"Wygenerowana Tabica = [ ";
for (int j=0; j<10; j++){
    cout <<ListaLiczb[j]<<" ";
}
cout<<"]"<<endl;
}

void GlownaFunkcjaPrzesuwania (int ListaLiczb[]){

int Temp;

for (int j=0; j<10; j++){
    if(ListaLiczb[j]<0){
        for(int p=j; p<9; p++){
            cout<<"Zamieniam "<<ListaLiczb[p]<<" z "<<ListaLiczb[p+1]<<endl;
            Temp = ListaLiczb[p];
            ListaLiczb[p]=ListaLiczb[p+1];
            ListaLiczb[p+1]= Temp;
        }
    }
}

cout<<"Tabica po przesunieciu = [ ";
for (int j=0; j<10; j++){
    cout <<ListaLiczb[j]<<" ";
}
cout<<"]"<<endl;


}

int main()
{
    int Tablica[10];
    GenerowanieTablic(Tablica);


    GlownaFunkcjaPrzesuwania(Tablica);


    return 0;
}

