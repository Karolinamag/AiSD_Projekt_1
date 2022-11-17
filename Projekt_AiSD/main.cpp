#include <iostream>
#include <ctime> //biblioteka potrzebna to losowania
#include <fstream> //biblioteka do wczytywania i zapisywania do txt
#include <chrono> //biblioteka do mierzenia czasu
using namespace std::chrono; //potrzebne do mierzenia czasu
using namespace std;

//Pierwsza funkcja służy do wczytania tabeli z pliku txt
int * WczytanieTablicy (){ //Funkcja zdefiniowana tak żeby nie przyjmowała żadnych argumentów i tak żeby zwracała wczytaną tablicy

    fstream wczytywanie; //Tworzenie zmiennej, do której zapisany będzie plik, typu do tego przeznaczonego

    wczytywanie.open("Liczby.txt", ios::in); //Otwieranie wcześniej przygotowanego pliku tekstowego

    int i=0; //Deklaracja iteratora który będzie służył do zapisywania danych i równocześnie do zmierzenia długości tablicy
    int * WczytanaTabela = new int[i]; //Tworzenie tablicy dynamicznej do której zapisane będą liczby
    while(!wczytywanie.eof()){ //While wykonuje się aż skończy się plik
       wczytywanie >> WczytanaTabela[i]; //Po kolei wczytywane są liczby na kolejne miejsca w tablicy
       i++; //Iterator jest zwiększany przy każdym wczytaniu liczby, co na raz liczy ile liczb jest wczytane i służy do wskazania kolejnego miejsca na które wpisywana jest liczba
    }
    wczytywanie.close(); //Zamykanie pliku

    //Wypisywanie do konsoli wczytanej tablicy
    cout<<"Wczytana Tablica = [ ";
    for (int j=0; j<i; j++){ //For idący od 0 do i (które jest jest ilością liczb)
        cout <<WczytanaTabela[j]<<" ";
    }
    cout<<"]"<<endl;

return WczytanaTabela; //Funkcja zwraca wczytaną tablicy

}

//Druga funkcja generuje tablicę liczb naturalnych od -100 do 100
int * GenerowanieTablic (int N) { //Przyjmuje argument długości tabicy do wygenerowania i zwraca tablicę

srand((unsigned) time(0)); //Potrzebne do generowania liczb losowych
int * GenerowanaTablica = new int[N]; //Deklaracja tablicy dynamicznej na liczby

for (int j=0; j<N; j++){ //for działający N (przesłana do funkcji porządana długość tablicy) razy
    GenerowanaTablica[j]=((rand()%400)-200); //Wykonywanie na rand modulo 200 daje liczby od 0 do 200, a potem odjęcie 100, daje liczby od -100 do 100
}

//Kolejna sekcja do wyświetlania, przeszkadza przy generowaniu dużej ilości tablic
//cout<<"Wygenerowana Tabica = [ ";
//for (int j=0; j<N; j++){
//    cout <<GenerowanaTablica[j]<<" ";
//}
//cout<<"]"<<endl;

return GenerowanaTablica; //Funkcja zwraca wygenerowaną tablicę
}

//Główana funkcja projektu, bierze tablicę, znajduje w niej liczby ujemne i przesówa je na koniec
int * GlownaFunkcjaPrzesuwania (int PrzesuwanaTablica[]){ //Funkcja przyjmuje jeden argument, tablicę do przesortowania, i zwraca przesortowaną tablicę

int N=sizeof(PrzesuwanaTablica); //Mierzenie długości tablicy
int TablicaUjemnych[N]; //Tworzenie pustej tablicy gdzie zapisane będą liczby ujemne
int IteratorUjemnych = 0; //Tworzenie iteratora który będzie służył do wstawiania do tablicy ujemnych i do liczenia ich ilości
int TablicaNieujemnych[N]; //Tworzenie pustej tablicy gdzie zapisane będą liczby nieujemne
int IteratorNieujemnych = 0; //Tworzenie iteratora który będzie służył do wstawiania do tablicy nieujemnych i do liczenia ich ilości
int * PrzesunietaTablica = new int[N]; //Tworzenie tablicy dynamicznej na finalny wynik
int IteratorPrzesunietejtablicy = 0; //Tworzenie iteratora który będzie służył do wstawiania do tablicy finalnej

for (int j=0; j<N; j++){ //For wykonuje się N (długość tablicy) razy
    if(PrzesuwanaTablica[j]<0){ //Jeśli element tablicy jest mniejszy od zera to przejście do pierwszej sekcji
        TablicaUjemnych[IteratorUjemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z ujemnymi
        IteratorUjemnych++; //Zwiększanie o 1 liczby ujmnych elementów i zarazem liczenie ich
    }else{ //Jeśli nie jest mniejszy od zera to do drugiej sekcji
        TablicaNieujemnych[IteratorNieujemnych]=PrzesuwanaTablica[j]; //Zapisywanie liczby do tablicy z nieujemnymi
        IteratorNieujemnych++; //Zwiększanie o 1 liczby nieujmnych elementów i zarazem liczenie ich
    }
}

    for (int j=0; j<IteratorNieujemnych; j++){ //For wykonuje się tyle razy, ile znaleziono liczb nieujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaNieujemnych[j]; //Dopisywanie do Finalnej tablicy liczb nieujemnych
        IteratorPrzesunietejtablicy++; //Zwiększanie iteratora elementów w finalnej tabeli i zarazem liczenie ich
    }
    for (int j=0; j<IteratorUjemnych; j++){//For wykonuje się tyle razy, ile znaleziono liczb ujemnych
        PrzesunietaTablica[IteratorPrzesunietejtablicy]=TablicaUjemnych[j]; //Dopisywanie do Finalnej tablicy liczb ujemnych (to dalej ten sama tablica z poprzedniego fora)
        IteratorPrzesunietejtablicy++; //Zwiększanie iteratora elementów w finalnej tabeli i zarazem liczenie ich (to dalej ten sam iterator z poprzedniego fora)
    }



return PrzesunietaTablica; //Funkcja zwraca przesuniętą tablicę
}

//Funkcja main, tu odpalane są inne fukncje i ich obsługa
int main()
{
    int * Tablica; //Tworzenie tablicy dynamicznej do której będą przypisywane wyniki

    Tablica = WczytanieTablicy (); //Wywołanie funkcji wczytywania tablicy i przypisanie wyjścia do zmiennej "Tablica" (czyli tablicy z pliku)

    Tablica = GlownaFunkcjaPrzesuwania(Tablica); //Wywołanie głównej funkcji gdzie argumentem jest tablica wczytana z pliku

    //Wypisanie wyniku przesuwania
    cout<<"Tabica po przesunieciu = [ ";
    for (int j=0; j<sizeof(Tablica); j++){
       cout<<Tablica[j]<<" ";
    }
    cout<<"]"<<endl;

    fstream zapisywanie; //Tworzenie zmiennej, która będzie przekazywać dane do pliku, typu do tego przeznaczonego
    zapisywanie.open("Wynik.txt", ios::out); //Otwieranie nowego pliku tekstowego do którego zapisywany będzie wynik
    zapisywanie<<"Tabica po przesunieciu = [ "; //Zamiast "cout" mamy zmienną "zapisywanie" więc wszytko idzie do pliku txt
    for (int j=0; j<sizeof(Tablica); j++){
       zapisywanie<<Tablica[j]<<" ";
    }
    zapisywanie<<"]"<<endl;
    zapisywanie.close(); //Zamknięcie pliku

    fstream zapisywanie2; //Tworzenie zmiennej, która będzie przekazywać dane do pliku, typu do tego przeznaczonego
    zapisywanie2.open("Czasy.txt", ios::out); //Otwieranie nowego pliku tekstowego do którego zapisywane będą wyniki

    for (int ile=100000; ile<250000; ile+=100){ //For który wykonuje się 1500 razy, wartość iteratora jest na raz też długością tablicy którą każemy wygenerować programowi. Jest ona tak duża bo co dopiero taka długość daje jakikolwiek czas działania

        Tablica = GenerowanieTablic (ile); //Wywołanie generowania tablic o długości zgodnej z iteratorem for'a

        auto start = high_resolution_clock::now(); //Start mierzenia czasu

        GlownaFunkcjaPrzesuwania(Tablica); //Wywołanie głównej funkcji z wygnenrowaną tablicą

        auto koniec = high_resolution_clock::now(); //Koniec mierzenia czasu
        auto duration = duration_cast<microseconds>(koniec - start); //Odejmowanie czasu początkowego od końcowego i konwersja na microsekundy
        zapisywanie2<<duration.count()<<endl; //zapisywanie każdego czasu do pliku

    }
    zapisywanie.close(); //zamknięcie pliku

    return 0;
}
