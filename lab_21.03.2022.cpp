#include <iostream>

using namespace std;

class Samochod {
    string rodzaj, marka, model;
    int rocznik, moc, przyspieszenie, zasieg;

public:

    Samochod(string r = "kombi", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900) {
        rodzaj = r;
        marka = ma;
        model = mo;
        rocznik = ro;
        moc = m;
        przyspieszenie = p;
        zasieg = z;
        pokaz();
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

    Spalinowy( string r = "sedan", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900, string typ_p = "diesel") :Samochod(r, ma, mo, ro, m, p, z) {
        typ_paliwa = typ_p;
        pokaz();
    }

    void pokaz() {
        cout << "Rodzaj paliwa: " << typ_paliwa << endl;
    }
};

class Hybrydowy :public Spalinowy, public Elektryczny {
public:
    Hybrydowy(string r = "suv", string ma = "Volkswagen", string mo = "Passat", int ro = 2003, int m = 140, int p = 5, int z = 900, string typ_p ="benzyna", int sb=60) :Elektryczny(sb), Spalinowy(typ_p), Samochod(r, ma, mo, ro, m, p, z) {
  
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
    Hybrydowy samochod_hybrydowy;
    //samochod_hybrydowy.pokaz();
    //samochod_elektryczny.pokaz();
    //cout << endl;
   // samochod_hybrydowy.pokaz();

    return 0;
}