#include <iostream>
#include <ctime>
using namespace std;

void GenerowanieTablic (int ListaLiczb[]) {

srand((unsigned) time(0));

for (int j=0; j<10; j++){
    ListaLiczb[j]=((rand() % 20)-10 );
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



    return 0;
}
