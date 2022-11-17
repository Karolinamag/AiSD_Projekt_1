#include <iostream>
#include <ctime> //biblioteka potrzebna to losowania
#include <fstream> //biblioteka do wczytywania i zapisywania do txt
#include <chrono> //biblioteka do mierzenia czasu
using namespace std::chrono; //potrzebne do mierzenia czasu
using namespace std;

//Pierwsza funkcja s³u¿y do wczytania tabeli z pliku txt
int * WczytanieTablicy (){ //Funkcja zdefiniowana tak ¿eby nie przyjmowa³a ¿adnych argumentów i tak ¿eby zwraca³a wczytan¹ tablicy

    fstream wczytywanie; //Tworzenie zmiennej, do której zapisany bêdzie plik, typu do tego przeznaczonego

    wczytywanie.open("Liczby.txt", ios::in); //Otwieranie wczeœniej przygotowanego pliku tekstowego

    int i=0; //Deklaracja iteratora który bêdzie s³u¿y³ do zapisywania danych i równoczeœnie do zmierzenia d³ugoœci tablicy
    int * WczytanaTabela = new int[i]; //Tworzenie tablicy dynamicznej do której zapisane bêd¹ liczby
    while(!wczytywanie.eof()){ //While wykonuje siê a¿ skoñczy siê plik
       wczytywanie >> WczytanaTabela[i]; //Po kolei wczytywane s¹ liczby na kolejne miejsca w tablicy
       i++; //Iterator jest zwiêkszany przy ka¿dym wczytaniu liczby, co na raz liczy ile liczb jest wczytane i s³u¿y do wskazania kolejnego miejsca na które wpisywana jest liczba
    }
    wczytywanie.close(); //Zamykanie pliku

    //Wypisywanie do konsoli wczytanej tablicy
    cout<<"Wczytana Tablica = [ ";
    for (int j=0; j<i; j++){ //For id¹cy od 0 do i (które jest jest iloœci¹ liczb)
        cout <<WczytanaTabela[j]<<" ";
    }
    cout<<"]"<<endl;

return WczytanaTabela; //Funkcja zwraca wczytan¹ tablicy

}

//Druga funkcja generuje tablicê liczb naturalnych od -100 do 100
int * GenerowanieTablic (int N) { //Przyjmuje argument d³ugoœci tabicy do wygenerowania i zwraca tablicê

srand((unsigned) time(0)); //Potrzebne do generowania liczb losowych
int * GenerowanaTablica = new int[N]; //Deklaracja tablicy dynamicznej na liczby

for (int j=0; j<N; j++){ //for dzia³aj¹cy N (przes³ana do funkcji porz¹dana d³ugoœæ tablicy) razy
    GenerowanaTablica[j]=((rand()%400)-200); //Wykonywanie na rand modulo 200 daje liczby od 0 do 200, a potem odjêcie 100, daje liczby od -100 do 100
}

//Kolejna sekcja do wyœwietlania, przeszkadza przy generowaniu du¿ej iloœci tablic
//cout<<"Wygenerowana Tabica = [ ";
//for (int j=0; j<N; j++){
//    cout <<GenerowanaTablica[j]<<" ";
//}
//cout<<"]"<<endl;

return GenerowanaTablica; //Funkcja zwraca wygenerowan¹ tablicê
}

//G³ówana funkcja projektu, bierze tablicê, znajduje w niej liczby ujemne i przesówa je na koniec
int * GlownaFunkcjaPrzesuwania (int PrzesuwanaTablica[]){ //Funkcja przyjmuje jeden argument, tablicê do przesortowania, i zwraca przesortowan¹ tablicê

int N=sizeof(PrzesuwanaTablica); //Mierzenie d³ugoœci tablicy
int TablicaUjemnych[N]; //Tworzenie pustej tablicy gdzie zapisane bêd¹ liczby ujemne
int IteratorUjemnych = 0; //Tworzenie iteratora który bêdzie s³u¿y³ do wstawiania do tablicy ujemnych i do liczenia ich iloœci
int TablicaNieujemnych[N]; //Tworzenie pustej tablicy gdzie zapisane bêd¹ liczby nieujemne
int IteratorNieujemnych = 0; //Tworzenie iteratora który bêdzie s³u¿y³ do wstawiania do tablicy nieujemnych i do liczenia ich iloœci
int * PrzesunietaTablica = new int[N]; //Tworzenie tablicy dynamicznej na finalny wynik
int IteratorPrzesunietejtablicy = 0; //Tworzenie iteratora który bêdzie s³u¿y³ do wstawiania do tablicy finalnej

for (int j=0; j<N; j++){ //For wykonuje siê N (d³ugoœæ tablicy) razy
    if(PrzesuwanaTablica[j]<0){ //Jeœli element tablicy jest mniejszy od zera to przejœcie do pierwszej sekcji
        TablicaUjemnych[IteratorUjemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z ujemnymi
        IteratorUjemnych++; //Zwiêkszanie o 1 liczby ujmnych elementów i zarazem liczenie ich
    }else{ //Jeœli nie jest mniejszy od zera to do drugiej sekcji
        TablicaNieujemnych[IteratorNieujemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z nieujemnymi
        IteratorNieujemnych++; //Zwiêkszanie o 1 liczby nieujmnych elementów i zarazem liczenie ich
    }
}

    for (int j=0; j<IteratorNieujemnych; j++){ //For wykonuje siê tyle razy, ile znaleziono liczb nieujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaNieujemnych[j]; //Dopisywanie do Finalnej tablicy liczb nieujemnych
        IteratorPrzesunietejtablicy++; //Zwiêkszanie iteratora elementów w finalnej tabeli i zarazem liczenie ich
    }
    for (int j=0; j<IteratorUjemnych; j++){//For wykonuje siê tyle razy, ile znaleziono liczb ujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaUjemnych[j]; //Dopisywanie do Finalnej tablicy liczb ujemnych (to dalej ten sama tablica z poprzedniego fora)
        IteratorPrzesunietejtablicy++; //Zwiêkszanie iteratora elementów w finalnej tabeli i zarazem liczenie ich (to dalej ten sam iterator z poprzedniego fora)
    }



return PrzesunietaTablica; //Funkcja zwraca przesuniêt¹ tablicê
}

//Funkcja main, tu odpalane s¹ inne fukncje i ich obs³uga
