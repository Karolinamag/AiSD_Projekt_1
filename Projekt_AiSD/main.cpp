#include <iostream>
#include <ctime> //biblioteka potrzebna to losowania
#include <fstream> //biblioteka do wczytywania i zapisywania do txt
#include <chrono> //biblioteka do mierzenia czasu
using namespace std::chrono; //potrzebne do mierzenia czasu
using namespace std;

//Pierwsza funkcja s�u�y do wczytania tabeli z pliku txt
int * WczytanieTablicy (){ //Funkcja zdefiniowana tak �eby nie przyjmowa�a �adnych argument�w i tak �eby zwraca�a wczytan� tablicy

    fstream wczytywanie; //Tworzenie zmiennej, do kt�rej zapisany b�dzie plik, typu do tego przeznaczonego

    wczytywanie.open("Liczby.txt", ios::in); //Otwieranie wcze�niej przygotowanego pliku tekstowego

    int i=0; //Deklaracja iteratora kt�ry b�dzie s�u�y� do zapisywania danych i r�wnocze�nie do zmierzenia d�ugo�ci tablicy
    int * WczytanaTabela = new int[i]; //Tworzenie tablicy dynamicznej do kt�rej zapisane b�d� liczby
    while(!wczytywanie.eof()){ //While wykonuje si� a� sko�czy si� plik
       wczytywanie >> WczytanaTabela[i]; //Po kolei wczytywane s� liczby na kolejne miejsca w tablicy
       i++; //Iterator jest zwi�kszany przy ka�dym wczytaniu liczby, co na raz liczy ile liczb jest wczytane i s�u�y do wskazania kolejnego miejsca na kt�re wpisywana jest liczba
    }
    wczytywanie.close(); //Zamykanie pliku

    //Wypisywanie do konsoli wczytanej tablicy
    cout<<"Wczytana Tablica = [ ";
    for (int j=0; j<i; j++){ //For id�cy od 0 do i (kt�re jest jest ilo�ci� liczb)
        cout <<WczytanaTabela[j]<<" ";
    }
    cout<<"]"<<endl;

return WczytanaTabela; //Funkcja zwraca wczytan� tablicy

}

//Druga funkcja generuje tablic� liczb naturalnych od -100 do 100
int * GenerowanieTablic (int N) { //Przyjmuje argument d�ugo�ci tabicy do wygenerowania i zwraca tablic�

srand((unsigned) time(0)); //Potrzebne do generowania liczb losowych
int * GenerowanaTablica = new int[N]; //Deklaracja tablicy dynamicznej na liczby

for (int j=0; j<N; j++){ //for dzia�aj�cy N (przes�ana do funkcji porz�dana d�ugo�� tablicy) razy
    GenerowanaTablica[j]=((rand()%400)-200); //Wykonywanie na rand modulo 200 daje liczby od 0 do 200, a potem odj�cie 100, daje liczby od -100 do 100
}

//Kolejna sekcja do wy�wietlania, przeszkadza przy generowaniu du�ej ilo�ci tablic
//cout<<"Wygenerowana Tabica = [ ";
//for (int j=0; j<N; j++){
//    cout <<GenerowanaTablica[j]<<" ";
//}
//cout<<"]"<<endl;

return GenerowanaTablica; //Funkcja zwraca wygenerowan� tablic�
}

//G��wana funkcja projektu, bierze tablic�, znajduje w niej liczby ujemne i przes�wa je na koniec
int * GlownaFunkcjaPrzesuwania (int PrzesuwanaTablica[]){ //Funkcja przyjmuje jeden argument, tablic� do przesortowania, i zwraca przesortowan� tablic�

int N=sizeof(PrzesuwanaTablica); //Mierzenie d�ugo�ci tablicy
int TablicaUjemnych[N]; //Tworzenie pustej tablicy gdzie zapisane b�d� liczby ujemne
int IteratorUjemnych = 0; //Tworzenie iteratora kt�ry b�dzie s�u�y� do wstawiania do tablicy ujemnych i do liczenia ich ilo�ci
int TablicaNieujemnych[N]; //Tworzenie pustej tablicy gdzie zapisane b�d� liczby nieujemne
int IteratorNieujemnych = 0; //Tworzenie iteratora kt�ry b�dzie s�u�y� do wstawiania do tablicy nieujemnych i do liczenia ich ilo�ci
int * PrzesunietaTablica = new int[N]; //Tworzenie tablicy dynamicznej na finalny wynik
int IteratorPrzesunietejtablicy = 0; //Tworzenie iteratora kt�ry b�dzie s�u�y� do wstawiania do tablicy finalnej

for (int j=0; j<N; j++){ //For wykonuje si� N (d�ugo�� tablicy) razy
    if(PrzesuwanaTablica[j]<0){ //Je�li element tablicy jest mniejszy od zera to przej�cie do pierwszej sekcji
        TablicaUjemnych[IteratorUjemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z ujemnymi
        IteratorUjemnych++; //Zwi�kszanie o 1 liczby ujmnych element�w i zarazem liczenie ich
    }else{ //Je�li nie jest mniejszy od zera to do drugiej sekcji
        TablicaNieujemnych[IteratorNieujemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z nieujemnymi
        IteratorNieujemnych++; //Zwi�kszanie o 1 liczby nieujmnych element�w i zarazem liczenie ich
    }
}

    for (int j=0; j<IteratorNieujemnych; j++){ //For wykonuje si� tyle razy, ile znaleziono liczb nieujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaNieujemnych[j]; //Dopisywanie do Finalnej tablicy liczb nieujemnych
        IteratorPrzesunietejtablicy++; //Zwi�kszanie iteratora element�w w finalnej tabeli i zarazem liczenie ich
    }
    for (int j=0; j<IteratorUjemnych; j++){//For wykonuje si� tyle razy, ile znaleziono liczb ujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaUjemnych[j]; //Dopisywanie do Finalnej tablicy liczb ujemnych (to dalej ten sama tablica z poprzedniego fora)
        IteratorPrzesunietejtablicy++; //Zwi�kszanie iteratora element�w w finalnej tabeli i zarazem liczenie ich (to dalej ten sam iterator z poprzedniego fora)
    }



return PrzesunietaTablica; //Funkcja zwraca przesuni�t� tablic�
}

//Funkcja main, tu odpalane s� inne fukncje i ich obs�uga
