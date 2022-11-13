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

int TabelaUjemnych[10];
int WskaznikUjemnych = 0;
int TabelaNieujemnych[10];
int WskaznikNieujemnych = 0;

for (int j=0; j<10; j++){
    if(ListaLiczb[j]<0){
        TabelaUjemnych[WskaznikUjemnych]=ListaLiczb[j];
        WskaznikUjemnych++;
    }else{
        TabelaNieujemnych[WskaznikNieujemnych]=ListaLiczb[j];
        WskaznikNieujemnych++;
    }
}

int PrzesunietaTabela[10];
int WskaznikPrzesunietejTabeli = 0;

    for (int j=0; j<WskaznikNieujemnych; j++){
        PrzesunietaTabela[WskaznikPrzesunietejTabeli]=TabelaNieujemnych[j];
        WskaznikPrzesunietejTabeli++;
    }
    for (int j=0; j<WskaznikUjemnych; j++){
        PrzesunietaTabela[WskaznikPrzesunietejTabeli]=TabelaUjemnych[j];
        WskaznikPrzesunietejTabeli++;
    }



cout<<"Tabica po przesunieciu = [ ";
for (int j=0; j<10; j++){
    cout <<PrzesunietaTabela[j]<<" ";
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
