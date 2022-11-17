#include <iostream>
#include <ctime> //biblioteka potrzebna to losowania
#include <fstream> //biblioteka do wczytywania i zapisywania do txt
#include <chrono> //biblioteka do mierzenia czasu
using namespace std::chrono; //potrzebne do mierzenia czasu
using namespace std;

//Pierwsza funkcja s³u¿y do wczytania tabeli z pliku txt
int * WczytanieTablicy (){ //Funkcja zdefiniowana tak ¿eby nie przyjmowa³a ¿adnych argumentów i tak ¿eby zwraca³a wczytan¹ tabelê

    fstream wczytywanie; //Tworzenie zmiennej, do której zapisany bêdzie plik, typu do tego przeznaczonego

    wczytywanie.open("Liczby.txt", ios::in); //otwieranie wczeœniej przygotowanego pliku tekstowego

    int wskaznik=0; //
    int * WczytanaTabela = new int[wskaznik];
    while(!wczytywanie.eof()){
       wczytywanie >> WczytanaTabela[wskaznik];
       wskaznik++;
    }
    wczytywanie.close();


cout<<"Wczytana Tablica = [ ";
for (int j=0; j<wskaznik; j++){
    cout <<WczytanaTabela[j]<<" ";
}
cout<<"]"<<endl;

return WczytanaTabela;

}


int * GenerowanieTablic (int N) {

srand((unsigned) time(0));
int * GenerowanaTablica = new int[N];

for (int j=0; j<N; j++){
    GenerowanaTablica[j]=((rand()%200)-100);
}

//cout<<"Wygenerowana Tabica = [ ";
//for (int j=0; j<N; j++){
//    cout <<GenerowanaTablica[j]<<" ";
//}
//cout<<"]"<<endl;

return GenerowanaTablica;
}

int * GlownaFunkcjaPrzesuwania (int ListaLiczb[],int N){

int TabelaUjemnych[N];
int WskaznikUjemnych = 0;
int TabelaNieujemnych[N];
int WskaznikNieujemnych = 0;
int * PrzesunietaTabela = new int[N];
int WskaznikPrzesunietejTabeli = 0;

auto start = high_resolution_clock::now();

for (int j=0; j<N; j++){
    if(ListaLiczb[j]<0){
        TabelaUjemnych[WskaznikUjemnych]=ListaLiczb[j];
        WskaznikUjemnych++;
    }else{
        TabelaNieujemnych[WskaznikNieujemnych]=ListaLiczb[j];
        WskaznikNieujemnych++;
    }
}

    for (int j=0; j<WskaznikNieujemnych; j++){
        PrzesunietaTabela[WskaznikPrzesunietejTabeli]=TabelaNieujemnych[j];
        WskaznikPrzesunietejTabeli++;
    }
    for (int j=0; j<WskaznikUjemnych; j++){
        PrzesunietaTabela[WskaznikPrzesunietejTabeli]=TabelaUjemnych[j];
        WskaznikPrzesunietejTabeli++;
    }



return PrzesunietaTabela;
}


int main()
{
    int N = 200000;
    int * Tablica = new int[N];

    Tablica = WczytanieTablicy ();

    Tablica = GlownaFunkcjaPrzesuwania(Tablica,sizeof(Tablica));

    cout<<"Tabica po przesunieciu = [ ";
    for (int j=0; j<sizeof(Tablica); j++){
       cout<<Tablica[j]<<" ";
    }
    cout<<"]"<<endl;

    fstream zapisywanie;
    zapisywanie.open("Wynik.txt", ios::out);
    zapisywanie<<"Tabica po przesunieciu = [ ";
    for (int j=0; j<sizeof(Tablica); j++){
       zapisywanie<<Tablica[j]<<" ";
    }
    zapisywanie<<"]"<<endl;
    zapisywanie.close();

    fstream zapisywanie2;
    zapisywanie2.open("Czasy.txt", ios::out);

for (int ile=100000; ile<250000; ile+=100){

    Tablica = GenerowanieTablic (ile);

auto start = high_resolution_clock::now();

    GlownaFunkcjaPrzesuwania(Tablica,ile);

auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
zapisywanie2<<duration.count()<<endl;

}

    return 0;
}
