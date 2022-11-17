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
int * GenerowanieTablic (int N, int gran) { //Przyjmuje argument d³ugoœci tabicy do wygenerowania i granice rozrzutu wartości i zwraca tablicê

srand((unsigned) time(0)); //Potrzebne do generowania liczb losowych
int * GenerowanaTablica = new int[N]; //Deklaracja tablicy dynamicznej na liczby

for (int j=0; j<N; j++){ //for dzia³aj¹cy N (przes³ana do funkcji porz¹dana d³ugoœæ tablicy) razy
    GenerowanaTablica[j]=((rand()%gran*2)-gran); //Wykonywanie na rand modulo  np. 200 daje liczby od 0 do 200, a potem odjêcie 100, daje liczby od -100 do 100
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
int * GlownaFunkcjaPrzesuwania (int PrzesuwanaTablica[], int N){ //Funkcja przyjmuje dwa argumenty, tablicê do przesortowania i jej długość, i zwraca przesortowan¹ tablicê

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
int main()
{
    int * Tablica; //Tworzenie tablicy dynamicznej do której bêd¹ przypisywane wyniki




    cout<<"Pzykład wczytywania z pliku:"<<endl<<endl;

    Tablica = WczytanieTablicy (); //Wywo³anie funkcji wczytywania tablicy i przypisanie wyjœcia do zmiennej "Tablica" (czyli tablicy z pliku)

    Tablica = GlownaFunkcjaPrzesuwania(Tablica,sizeof(Tablica)); //Wywo³anie g³ównej funkcji gdzie argumentem jest tablica wczytana z pliku

    //Wypisanie wyniku przesuwania
    cout<<"Tabica po przesunieciu = [ ";
    for (int j=0; j<sizeof(Tablica); j++){
       cout<<Tablica[j]<<" ";
    }
    cout<<"]"<<endl<<endl;




    cout<<"Pzykład generowania Tabel:"<<endl<<endl;



    cout<<"Długość: 10 Granica: 100"<<endl;

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



    cout<<"Długość: 100 Granica: 200"<<endl;

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



    cout<<"Długość: 1000 Granica: 5000"<<endl;

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




    fstream zapisywanie; //Tworzenie zmiennej, która bêdzie przekazywaæ dane do pliku, typu do tego przeznaczonego
    zapisywanie.open("Wynik.txt", ios::out); //Otwieranie nowego pliku tekstowego do którego zapisywany bêdzie wynik
    zapisywanie<<"Tabica po przesunieciu = [ "; //Zamiast "cout" mamy zmienn¹ "zapisywanie" wiêc wszytko idzie do pliku txt
    for (int j=0; j<sizeof(Tablica); j++){
       zapisywanie<<Tablica[j]<<" ";
    }
    zapisywanie<<"]"<<endl;
    zapisywanie.close(); //Zamkniêcie pliku

    fstream zapisywanie2; //Tworzenie zmiennej, która bêdzie przekazywaæ dane do pliku, typu do tego przeznaczonego
    zapisywanie2.open("Czasy.txt", ios::out); //Otwieranie nowego pliku tekstowego do którego zapisywane bêd¹ wyniki

    for (int ile=100000; ile<250000; ile+=100){ //For który wykonuje siê 1500 razy, wartoœæ iteratora jest na raz te¿ d³ugoœci¹ tablicy któr¹ ka¿emy wygenerowaæ programowi. Jest ona tak du¿a bo co dopiero taka d³ugoœæ daje jakikolwiek czas dzia³ania

        Tablica = GenerowanieTablic (ile,200); //Wywo³anie generowania tablic o d³ugoœci zgodnej z iteratorem for'a

        auto start = high_resolution_clock::now(); //Start mierzenia czasu

        GlownaFunkcjaPrzesuwania(Tablica,ile); //Wywo³anie g³ównej funkcji z wygnenrowan¹ tablic¹

        auto koniec = high_resolution_clock::now(); //Koniec mierzenia czasu
        auto duration = duration_cast<microseconds>(koniec - start); //Odejmowanie czasu pocz¹tkowego od koñcowego i konwersja na microsekundy
        zapisywanie2<<duration.count()<<endl; //zapisywanie ka¿dego czasu do pliku

    }
    zapisywanie.close(); //zamkniêcie pliku

    return 0;
}
