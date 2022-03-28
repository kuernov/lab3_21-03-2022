#include <iostream>

using namespace std;

class Samochod {
    string rodzaj, marka, model;
    int rocznik, moc, przyspieszenie, zasieg;
    int static liczba_samochodow;
    void static wyswietl_liczbe_samochodow();

public:

    Samochod(string r = "kombi", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900) {
        rodzaj = r;
        marka = ma;
        model = mo;
        rocznik = ro;
        moc = m;
        przyspieszenie = p;
        zasieg = z;
        liczba_samochodow++;
        wyswietl_liczbe_samochodow();
        pokaz();
    }
    ~Samochod()
    {
        liczba_samochodow--;
        wyswietl_liczbe_samochodow();
    }

    void pokaz() {
        cout << "Rodzaj: " << rodzaj << endl;
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Rocznik: " << rocznik << endl;
        cout << "Moc: " << moc << endl;
        cout << "Przyspieszenie: " << przyspieszenie << endl;
        cout << "Zasieg: " << zasieg << endl;
    }
};

void Samochod::wyswietl_liczbe_samochodow()
{
    cout << "Aktualna liczba samochodow: " << liczba_samochodow << endl;
}

int Samochod::liczba_samochodow = 0;

class Elektryczny : virtual public Samochod {
    int stan_baterii;

public:

    Elektryczny(int sb = 0, string r = "hatchback", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900) :Samochod(r, ma, mo, ro, m, p, z) {
        stan_baterii = sb;
        pokaz();
    }

    void pokaz() {
        cout << "Stan baterii: " << stan_baterii << endl;
    }
};

class Spalinowy : virtual public Samochod {
    string typ_paliwa;

public:

    Spalinowy(string r = "sedan", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900, string typ_p = "diesel") :Samochod(r, ma, mo, ro, m, p, z) {
        typ_paliwa = typ_p;
        pokaz();
    }

    void pokaz() {
        cout << "Rodzaj paliwa: " << typ_paliwa << endl;
    }
};

class Hybrydowy :public Spalinowy, public Elektryczny {
public:
    Hybrydowy(string typ_p = "benzyna", string r = "suv", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900, int sb = 60) :Spalinowy(typ_p), Elektryczny(sb), Samochod(r, ma, mo, ro, m, p, z) {

    }

    void pokaz() {
        Samochod::pokaz();
        Spalinowy::pokaz();
        Elektryczny::pokaz();
    }
};

int main()
{
    //Elektryczny samochod_elektryczny;
    Hybrydowy* hybryda;
    hybryda = new Hybrydowy;
    delete hybryda;
    Hybrydowy samochod_hybrydowy1;
    cout << endl;
    Spalinowy samochod_spalinowy1;
    cout << endl;
    Hybrydowy samochod_hybrydowy2;
    cout << endl;
    Spalinowy samochod_spalinowy2;
    cout << endl;
    Spalinowy samochod_spalinowy3;
    cout << endl;
    Elektryczny samochod_elektryczny1;
    cout << endl;
    Hybrydowy samochod_hybrydowy3;
    cout << endl;
    Elektryczny samochod_elektryczny2;
    cout << endl;
    Elektryczny samochod_elektryczny3;

    return 0;
}