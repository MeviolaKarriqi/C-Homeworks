#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class banka
{
    int idELlogarise;
    char emriIPerdoruesit[100];
    float bal;
public:
    banka(int nr_llog, char *emri, float balanca)
    {
        idELlogarise=nr_llog;
        strcpy(emriIPerdoruesit, emri);
        bal=balanca;
    }
    void depozitim();
    void terheqje();
    void shfaq();
};
void banka::depozitim()
{
    int depozit;
    cout<<"\n Vendosni shumen qe doni te depozitoni = ";
    cin>>depozit;
    bal+=depozit;
}
void banka::terheqje()
{
    int terheq;
    cout<<"\n Vendosni shumen qe doni te terhiqni = ";
    cin>>terheq;
    if(terheq>bal)
        cout<<"\n Nuk mund te terhiqni shumen e kerkuar";
    bal-=terheq;
}
void banka::shfaq()
{
    cout<<"\n Nr i llogarise : "<<idELlogarise;
    cout<<"\n Emri: "<<emriIPerdoruesit;
    cout<<"\n Balanca : "<<bal;
}
int main()
{
    int nrLlogarie;
    char emri[100];
    float balanca;
    cout<<"\n Ju lutem vendosni te dhenat: \n";
    cout<<"\n Nr i llogarise: ";
    cin>>nrLlogarie;
    cout<<"\n Emri : ";
    cin>>emri;
    cout<<"\n Balanca : ";
    cin>>balanca;

    banka bank(nrLlogarie, emri, balanca);
    bank.depozitim();
    bank.terheqje();
    bank.shfaq();
    return 0;
}
