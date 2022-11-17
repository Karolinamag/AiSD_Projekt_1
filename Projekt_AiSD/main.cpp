/*
Dla zadanej tablicy liczb całkowitych przesuń wszystkie elementy mniejsze od 0 na jej koniec (należy zachować kolejność występowania!).
Przykład:
Wejście: A[] = [-10, 5, 8, -4, 1, 3, 0, -7]
Wyjście: [5, 8, 1, 3, 0, -10, -4, -7]
*/

#include <iostream>
#include <ctime> //biblioteka potrzebna do losowania
#include <fstream> //biblioteka do wczytywania i zapisywania do txt
#include <chrono> //biblioteka do mierzenia czasu
using namespace std::chrono; //potrzebne do mierzenia czasu
using namespace std;


//Pierwsza funkcja sluzy do wczytania tabeli z pliku txt
int * WczytanieTablicy (){ //Funkcja zdefiniowana tak zeby nie przyjmowala zadnych argumentow i tak zeby zwracala wczytana tablicy

    fstream wczytywanie; //Tworzenie zmiennej, do ktorej zapisany bedzie plik, typu do tego przeznaczonego

    wczytywanie.open("Liczby.txt", ios::in); //Otwieranie wczesniej przygotowanego pliku tekstowego

    int i=0; //Deklaracja iteratora ktory bedzie sluzyl do zapisywania danych i rownoczeœnie do zmierzenia dlugoœci tablicy
    int * WczytanaTabela = new int[i]; //Tworzenie tablicy dynamicznej do ktorej zapisane beda liczby
    while(!wczytywanie.eof()){ //While wykonuje sie az skonczy sie plik
       wczytywanie >> WczytanaTabela[i]; //Po kolei wczytywane sa liczby na kolejne miejsca w tablicy
       i++; //Iterator jest zwiekszany przy kazdym wczytaniu liczby, co na raz liczy ile liczb jest wczytane i sluzy do wskazania kolejnego miejsca na ktore wpisywana jest liczba
    }
    wczytywanie.close(); //Zamykanie pliku

    //Wypisywanie do konsoli wczytanej tablicy
    cout<<"Wczytana Tablica = [ ";
    for (int j=0; j<i; j++){ //For idacy od 0 do i (ktore jest jest iloœcia liczb)
        cout <<WczytanaTabela[j]<<" ";
    }
    cout<<"]"<<endl;

return WczytanaTabela; //Funkcja zwraca wczytana tablicy

}

//Druga funkcja generuje tablice liczb naturalnych od -100 do 100
int * GenerowanieTablic (int N, int gran) { //Przyjmuje argument dlugoœci tabicy do wygenerowania i granice rozrzutu wartości i zwraca tablice

srand((unsigned) time(0)); //Potrzebne do generowania liczb losowych
int * GenerowanaTablica = new int[N]; //Deklaracja tablicy dynamicznej na liczby

for (int j=0; j<N; j++){ //for dzialajacy N (przeslana do funkcji porzadana dlugoœæ tablicy) razy
    GenerowanaTablica[j]=((rand()%gran*2)-gran); //Wykonywanie na rand modulo  np. 200 daje liczby od 0 do 200, a potem odjecie 100, daje liczby od -100 do 100
}

//Kolejna sekcja do wyœwietlania, przeszkadza przy generowaniu duzej iloœci tablic
//cout<<"Wygenerowana Tabica = [ ";
//for (int j=0; j<N; j++){
//    cout <<GenerowanaTablica[j]<<" ";
//}
//cout<<"]"<<endl;

return GenerowanaTablica; //Funkcja zwraca wygenerowana tablice
}

//Glowana funkcja projektu, bierze tablice, znajduje w niej liczby ujemne i przesowa je na koniec
int * GlownaFunkcjaPrzesuwania (int PrzesuwanaTablica[], int N){ //Funkcja przyjmuje dwa argumenty, tablice do przesortowania i jej długość, i zwraca przesortowana tablice

int TablicaUjemnych[N]; //Tworzenie pustej tablicy gdzie zapisane beda liczby ujemne
int IteratorUjemnych = 0; //Tworzenie iteratora ktory bedzie sluzyl do wstawiania do tablicy ujemnych i do liczenia ich iloœci
int TablicaNieujemnych[N]; //Tworzenie pustej tablicy gdzie zapisane beda liczby nieujemne
int IteratorNieujemnych = 0; //Tworzenie iteratora ktory bedzie sluzyl do wstawiania do tablicy nieujemnych i do liczenia ich iloœci
int * PrzesunietaTablica = new int[N]; //Tworzenie tablicy dynamicznej na finalny wynik
int IteratorPrzesunietejtablicy = 0; //Tworzenie iteratora ktory bedzie sluzyl do wstawiania do tablicy finalnej

for (int j=0; j<N; j++){ //For wykonuje sie N (dlugoœæ tablicy) razy
    if(PrzesuwanaTablica[j]<0){ //Jeœli element tablicy jest mniejszy od zera to przejœcie do pierwszej sekcji
        TablicaUjemnych[IteratorUjemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z ujemnymi
        IteratorUjemnych++; //Zwiekszanie o 1 liczby ujmnych elementow i zarazem liczenie ich
    }else{ //Jeœli nie jest mniejszy od zera to do drugiej sekcji
        TablicaNieujemnych[IteratorNieujemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z nieujemnymi
        IteratorNieujemnych++; //Zwiekszanie o 1 liczby nieujmnych elementow i zarazem liczenie ich
    }
}

    for (int j=0; j<IteratorNieujemnych; j++){ //For wykonuje sie tyle razy, ile znaleziono liczb nieujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaNieujemnych[j]; //Dopisywanie do Finalnej tablicy liczb nieujemnych
        IteratorPrzesunietejtablicy++; //Zwiekszanie iteratora elementow w finalnej tabeli i zarazem liczenie ich
    }
    for (int j=0; j<IteratorUjemnych; j++){//For wykonuje sie tyle razy, ile znaleziono liczb ujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaUjemnych[j]; //Dopisywanie do Finalnej tablicy liczb ujemnych (to dalej ten sama tablica z poprzedniego fora)
        IteratorPrzesunietejtablicy++; //Zwiekszanie iteratora elementow w finalnej tabeli i zarazem liczenie ich (to dalej ten sam iterator z poprzedniego fora)
    }



return PrzesunietaTablica; //Funkcja zwraca przesunieta tablice
}

//Funkcja main, tu odpalane sa inne fukncje i ich obsluga
int main()
{
    int * Tablica; //Tworzenie tablicy dynamicznej do ktorej beda przypisywane wyniki




    cout<<"Pzyklad wczytywania z pliku:"<<endl<<endl;

    Tablica = WczytanieTablicy (); //Wywolanie funkcji wczytywania tablicy i przypisanie wyjœcia do zmiennej "Tablica" (czyli tablicy z pliku)

    Tablica = GlownaFunkcjaPrzesuwania(Tablica,sizeof(Tablica)); //Wywolanie glownej funkcji gdzie argumentem jest tablica wczytana z pliku

    //Wypisanie wyniku przesuwania
    cout<<"Tablica po przesunieciu = [ ";
    for (int j=0; j<sizeof(Tablica); j++){
       cout<<Tablica[j]<<" ";
    }
    cout<<"]"<<endl<<endl;


fstream zapisywanie; //Tworzenie zmiennej, ktora bedzie przekazywaæ dane do pliku, typu do tego przeznaczonego
    zapisywanie.open("Wynik.txt", ios::out); //Otwieranie nowego pliku tekstowego do ktorego zapisywany bedzie wynik
    zapisywanie<<"Tablica po przesunieciu = [ "; //Zamiast "cout" mamy zmienna "zapisywanie" wiec wszytko idzie do pliku txt
    for (int j=0; j<sizeof(Tablica); j++){
       zapisywanie<<Tablica[j]<<" ";
    }
    zapisywanie<<"]"<<endl;
    zapisywanie.close(); //Zamkniecie pliku

    //Tutaj 3 razy sa generowane, przesuwane i wyswietlana tablice o roznej dlugosci, zeby pokazac dzialanie algorytmu
    cout<<"Pzyklad generowania Tablic:"<<endl<<endl;



    cout<<"Dlugosc: 10 Granica: 100"<<endl;

    Tablica = GenerowanieTablic (10,100);

    cout<<"Wygenerowana Tablica = [ ";
    for (int j=0; j<10; j++){
        cout <<Tablica[j]<<" ";
    }
    cout<<"]"<<endl;

    Tablica = GlownaFunkcjaPrzesuwania(Tablica,10);

    cout<<"Posortowana Tablica = [ ";
    for (int j=0; j<10; j++){
        cout <<Tablica[j]<<" ";
    }
    cout<<"]"<<endl<<endl;



    cout<<"Dlugosc: 100 Granica: 200"<<endl;

    Tablica = GenerowanieTablic (100,200);

    cout<<"Wygenerowana Tablica = [ ";
    for (int j=0; j<100; j++){
        cout <<Tablica[j]<<" ";
    }
    cout<<"]"<<endl;

    Tablica = GlownaFunkcjaPrzesuwania(Tablica,100);

    cout<<"Posortowana Tablica = [ ";
    for (int j=0; j<100; j++){
        cout <<Tablica[j]<<" ";
    }
    cout<<"]"<<endl<<endl;



    cout<<"Dlugosc: 1000 Granica: 5000"<<endl;

    Tablica = GenerowanieTablic (500,5000);

    cout<<"Wygenerowana Tablica = [ ";
    for (int j=0; j<500; j++){
        cout <<Tablica[j]<<" ";
    }
    cout<<"]"<<endl;

    Tablica = GlownaFunkcjaPrzesuwania(Tablica,500);

    cout<<"Posortowana Tablica = [ ";
    for (int j=0; j<500; j++){
        cout <<Tablica[j]<<" ";
    }
    cout<<"]"<<endl;



    fstream zapisywanie2; //Tworzenie zmiennej, ktora bedzie przekazywaæ dane do pliku, typu do tego przeznaczonego
    zapisywanie2.open("Czasy.txt", ios::out); //Otwieranie nowego pliku tekstowego do ktorego zapisywane beda wyniki

    for (int ile=100000; ile<250000; ile+=100){ //For ktory wykonuje sie 1500 razy, wartosc iteratora jest na raz tez dlugoœcia tablicy ktora kazemy wygenerowaæ programowi. Jest ona tak duza bo co dopiero taka dlugoœæ daje jakikolwiek czas dzialania

        Tablica = GenerowanieTablic (ile,200); //Wywolanie generowania tablic o dlugoœci zgodnej z iteratorem for'a

        auto start = high_resolution_clock::now(); //Start mierzenia czasu

        GlownaFunkcjaPrzesuwania(Tablica,ile); //Wywolanie glownej funkcji z wygnenrowana tablica

        auto koniec = high_resolution_clock::now(); //Koniec mierzenia czasu
        auto duration = duration_cast<microseconds>(koniec - start); //Odejmowanie czasu poczatkowego od koncowego i konwersja na microsekundy
        zapisywanie2<<duration.count()<<endl; //zapisywanie kazdego czasu do pliku

    }
    zapisywanie.close(); //zamkniecie pliku

    return 0;
}
