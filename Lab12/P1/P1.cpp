#include <iostream>
#include <cstring>
#define MAX 10001
using namespace std;

enum Tip_Contact
{
    prieten, cunoscut, coleg
};

class Contact
{public:
    const char* name;
    Tip_Contact type;
};

class Prieten : public Contact
{
    const char* data_nastere;
    const char* nr_telefon;
    const char* adresa;
public:
    Prieten(Tip_Contact x,const char* Nume ,const char* Data_Nastere, const char* Nr_Tel, const char* Adresa)
    {
        type = x;
        name = Nume;
        data_nastere = Data_Nastere;
        nr_telefon = Nr_Tel;
        adresa = Adresa;
    }
};

class Cunoscut : public Contact
{
    const char* numar_telefon;
public:
    Cunoscut(Tip_Contact x, const char* Nume, const char* Nr_Tel)
    {
        type = x;
        name = Nume;
        numar_telefon = Nr_Tel;
    }
};

class Coleg : public Contact
{
    const char* numar_tel;
    const char* firma;
    const char* adresa;
public:
    Coleg(Tip_Contact x, const char* Nume, const char* Nr_Tel, const char* Firma, const char* Adresa)
    {
        type = x;
        name = Nume;
        numar_tel = Nr_Tel;
        firma = Firma;
        adresa = Adresa;
    }

};

class Agenda
{
private:
    Contact* vect[MAX];
    int n=0;
public:
  
    Contact* Cautare_Contact(const char* nume)
    {
        for (int i = 0; i < n; i++)
        {
            if (strcmp(vect[i]->name, nume) == 0)
                return vect[i];
        }
        return nullptr;
    }
    int Nr_Prieteni()
    {
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            if (vect[i]->type == prieten)
                ct++;
        }
        return ct;
    }

    Prieten** Lista_Prieteni()
    {
        Prieten** lista;
        int l = this->Nr_Prieteni();
      
         lista = new Prieten * [l];     
        l = 0;
        for (int i = 0; i < n; i++)
            if (vect[i]->type == prieten)
                lista[l++] = (Prieten*)vect[i];

        return lista;
    }

    bool Stergere_Contact(const char* nume)
    {
        int i;
        for ( i = 0; i < n; i++)
        {
            if (strcmp(vect[i]->name, nume) == 0)
                break;
        }
        if (i == n) 
            return false;

        for (int j = i; j < n - 1; j++)
            vect[j] = vect[j + 1];
        n--;
        return true;
    }

    void Adaugare_Contact( Contact* x)
    {
        if (n >= MAX)
            return ;
        vect[n++] = x;
    }
    
    void Afisare()
    {
        cout << "Sunt " << n << " persoane in agenda." << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << vect[i]->name<<" "<<vect[i]->type<<"\n";
        }
    }

    void Afisare_Contact(Contact* C)
    {
        cout << C->name << " " << C->type << "\n";
    }
   
};

int main()
{
    Prieten* P = new Prieten(prieten, "Marcel", "16.06.1992", "0725386419", "Str. Lastarului, Nr. 6");
    Cunoscut* C = new Cunoscut(cunoscut, "Petrica", "0754768219");
    Coleg* X = new Coleg(coleg, "Mircea", "0789126547", "Samsung", "Str. Castanilor, Nr 90");
    Prieten* P1 = new Prieten(prieten, "Mihai", "14.09.2000", "0712769823", "Str. 1 Iunie, Bl. 321, Sc. A, Ap. 10");
    Prieten* P2 = new Prieten(prieten, "Andrei", "18.01.1999", "0725370112", "Str. Biruintei, Nr. 10");
    Prieten* P3 = new Prieten(prieten, "Paul", "07.11.2001", "0795032479", "Str. Republicii, Nr. 5");
 
    Agenda A;
    A.Adaugare_Contact(P);
    A.Adaugare_Contact(X);
    A.Adaugare_Contact(C);
    A.Adaugare_Contact(P1);
    A.Adaugare_Contact(P2);
    A.Adaugare_Contact(P3);
    A.Afisare();
    A.Stergere_Contact("Petrica");
    cout << "\n";
    A.Afisare();
    cout << "\nAm gasit: ";
    A.Afisare_Contact(A.Cautare_Contact("Mihai"));
    cout << "\n";

    Prieten** Lista;
    Lista = A.Lista_Prieteni();
    cout << "Sunt " << A.Nr_Prieteni()<<" in agenda: ";
    for (int i = 0; i <A.Nr_Prieteni() ; i++)
        cout << Lista[i]->name << " ";
    cout << "\n";

    return 0;
    
}

