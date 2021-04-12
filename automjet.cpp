/*
 * Ndërtoni një klasë Automjet që ruan shpejtësinë e një automjeti, ka një konstruktor me parametra dhe kthen shpejtësinë.
 * Gjithashtu duhet të ofrojë mundësinë e ndryshimit të shpejtësisë vetëm brenda klasës ose nga klasat që trashëgojnë prej Automjet.
Ndërtoni klasën Tren që trashëgon në mënyrë private nga klasa Automjet dhe ruan numrin e vagonave të trenit.
 Kjo klasë duhet të ketë një konstruktor me parametra, të ofrojë mundësinë e kthimit të numrit të vagonave dhe të riimplementojë ndryshimin e te dhënave të trenit.
Një tren pasagjerësh është një tren, por ruan edhe numrin e pasagjerëve që suporton.
 Për këtë arsye, krijoni një klasë për të, që trashëgon në mënyrë protected nga Tren. Kjo klasë duhet të
 ketë një konstruktor me parametra, të kthejë numrin e pasagjerëve për vagon dhe të afishojë në ekran të gjitha të dhënat që mundet për trenin e pasagjerëve.
Përdorni të treja klasat dhe shpjegoni aksesimin e secilës prej metodave të tyre
 */
#include <iostream>

#include <string>
using namespace std;
class Automjete {
private:
    int shpejtesia;
public:
    Automjete(){
        shpejtesia = 0;
    }
    int merrShpejtesine(int s){
        shpejtesia =s;
        return shpejtesia;
    }
    int rritShpejtesine(int rr){
        shpejtesia = shpejtesia+rr;
        return shpejtesia;
    }
    int ngadalesoShpejetesine(int u){
        shpejtesia = shpejtesia - u;
        return shpejtesia;
    }
};

class Treni : private Automjete{
private:
    int nrVagonash;
    int vagon;
public:
    Treni(){
        nrVagonash =0 ;
        vagon =0;
    }
    int merrNrEVagoneve(int nrvg){
        nrVagonash = nrvg;
        return  nrVagonash;
    }

    int merrVagon(int vg){
        vagon = vg;
        return vagon;
    }
    int shtoVagon(int vagon){
        nrVagonash= nrVagonash + vagon;
        return nrVagonash;
    }
};

class TrenPasagjeresh : protected Treni{
private:
    int nrPasagjeresh;

public:
    TrenPasagjeresh(){
        nrPasagjeresh = 0;
    }
    void merrNrPasagjeresh(int nrP){
        nrPasagjeresh = nrP;
    }
    int ktheNrPasagjeresh(int nrpasageresh){
        return nrpasageresh;
    }
    bool nrILejuar(){
        if (nrPasagjeresh>500){
            return true;
        } else{
            return false;
        }
    }

};

int main() {
    Automjete automjete;
    Treni tr;
    cout<<"\t\t\tAUTOMJETE\n\n";
    cout<<"\nVendosni shpejtesine e automjetit : ";
    int shpejtesi ;
   cin>>shpejtesi;
   cout<<automjete.merrShpejtesine(shpejtesi);
   cout<<"\nVendosni 1 nqs doni te rrisni shpejtesine dhe 2 nqs doni ta zvogeloni ate";
   int opsioni;
   cin>>opsioni;
    if (opsioni ==1){
        cout<<"\nVendosni me sa doni te shpejtoni : ";
        int sh;
        cin>>sh;
        cout<<"\nShpejtesia e automjetit pas pershpejtimit : "<<automjete.rritShpejtesine(sh);
    } else{
        cout<<"\nVendosni me sa doni te nagdalesoni : ";
        int sh;
        cin>>sh;
        cout<<"\nShpejtesia e automjetit pas ngadalesimit : "<<automjete.ngadalesoShpejetesine(sh);
    }
    cout<<"\n######################################################################################\n";
    cout<<"\n\t\t\tTRENI\n";
    cout<<"\nVendosni nr e vagonave : ";
    int ntVagonash ;
    cin>>ntVagonash;
    tr.merrNrEVagoneve(ntVagonash);
    cout<<"\nNumri i vagonave ne tren eshte : "<<tr.merrNrEVagoneve(ntVagonash);
    cout<<"\n\nDeshironi te shtoni vagon ne tren ? \n\n\t\t\t1.PO\n\t\t\t2.Jo";
    int zgjidhShto;
    cin>>zgjidhShto;
    if (zgjidhShto==1){
        cout<<"\n\nSa vagoni do ti shtohen trenit?\n";
        int vagon;
        cin>>vagon;
        cout<<"\nNumri i vagoneve qe i keni shtuar trenit : "<<tr.merrVagon(vagon);
        cout<<"\nNr i vagoneve te trenit tashme : "<<tr.shtoVagon(vagon);
    }
    cout<<"\n\n#####################################################################################\n";
    cout<<"\n\t\t\tTREN PASAGJERESH\n";
    TrenPasagjeresh trenPasagjeresh;
    cout<<"\nVendos numrin e pasagjereve : \n";
    int nrPasagjeresh ;
    cin>>nrPasagjeresh;
    trenPasagjeresh.merrNrPasagjeresh(nrPasagjeresh);
    cout<<"\n\nNumri i pasagjereve ne tren : "<<trenPasagjeresh.ktheNrPasagjeresh(nrPasagjeresh);
    bool nr=trenPasagjeresh.nrILejuar();
    if (nr== true){
        cout<<"\n\nTreni nuk e suporton numrin e pasagjereve qe ju keni vendosur sepse treni nuk suporton me shume se 500 pasagjere ";
    }else{
        cout<<"\n\nTren suporton numrin e pasagjereve te vendosur nga ju ";
    }
    return 0;
}
