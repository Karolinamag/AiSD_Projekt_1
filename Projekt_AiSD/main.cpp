#include <iostream>
using namespace std;

int* GenerowanieTablic (int ListaLiczb[]) {

srand((unsigned) time(0));

for (int j=0; j<10; j++){
    cout<<(1+rand() % 100 )<<endl;
    ListaLiczb[j]=(1+rand() % 100 );
    cout<<ListaLiczb[j]<<endl;
}

    cout<<ListaLiczb<<endl;
  return ListaLiczb;
}


