/*
 * Të deklarohen dhe të implementohen dy klasa circle dhe cylinder me kërkesa si më poshtë:
Klasa circle do ketë si variabël instance rrezen e rrethit. Funksionet anëtarë të saj duhet të lexojnë/shkruajnë vlerat e variablit të instances
 (metodat get dhe set), të llogarisin vlerën e sipërfaqes dhe të afishojnë vlerën e sipërfaqes.
 Gjithashtu klasa duhet të përfshijë dy konstruktorë (një me parametra dhe një pa parametra).Klasa cylinder duhet të trashëgojë nga klasa circle.
 Përveç anëtarëve që trashëgon nga klasa prind, kjo klasë duhet të ketë një variabël instance shtesë për lartësinë e cilindrit,
 duhet të përfshijë një metodë të re për llogaritjen e vëllimit të cilindrit dhe të riimplementojë funksionin e gjetjes së sipërfaqes.
 Riimplementoni konstruktorët e klasës cylinder duke ripërdorur konstruktorët e klasës circle.
 */

#include<iostream>

using namespace std;
class Rrethi{
public:
    Rrethi() {}
    int rreze;
    float sip;
    Rrethi(int a){
        rreze=a;
    }
    int getRreze(){
        cout<<"Vendosni rrezen = ";
        cin>>rreze;
        return rreze;
    }

    float siperaqe(){
        sip=3.14*rreze*rreze;
        return sip;
    }

    float Perimetri(){
        float perimeter;
        perimeter=2*3.14*rreze;
        return perimeter;
    }
};

class Cilinder:public Rrethi{
public:
    int lartesia;
    Cilinder() {}
    Cilinder(int a){
        lartesia=a;
    }
    int getlartesine()
    {
        cout<<"Vendosni lartesine = ";
        cin>>lartesia;
        return lartesia;
    }

    float sipCilinder (){
        float siperfaqe;
        siperfaqe=2*siperaqe()+(2*3.14*rreze*lartesia);
        return siperfaqe;
    }

    float vellimi(){
        return 3.14*rreze*rreze*lartesia;
    }
};

int main(){
    Cilinder cilinder;

    cilinder.getRreze();
    cilinder.getlartesine();

    cout<<"\n\n############################################################################################################################################\n\n";
    cout<<"\n\t\t\tRRETHI\n\n";

    cout<<"Perimetri eshte : "<<cilinder.Perimetri()<<endl;
    cout<<"Siperfaqja eshte : "<<cilinder.siperaqe()<<endl;

    cout<<"\n\n############################################################################################################################################\n\n";
    cout<<"\n\t\t\tCILINDER\n\n";

    cout<<"Siperaqja eshte : " << cilinder.sipCilinder()<<endl;
    cout<<"Vellimi eshte :  " << cilinder.vellimi()<<endl;
    return 0;
}

