//Klasa Time si ne figure. Pervec kesaj klasa duhet te kete mundesine e krahasimit te dy oreve nese
//jane te barabarta, nese njera eshte me e madhe se tjetra, te afishoje ne ekran nje ore ne formatin hh:mm:ss
//(te shtoje zero para nese duhet) si dhe te mbledhe dy ore.
//(metodat nextSecond() dhe previousSecond() mund te realizohen edhe si operatoret ++ dhe -)

#include <iostream>
#include <iomanip>
using namespace std;

class Time{
private:
    int ore, min, sek;
public:
    Time(){
        ore=0;
        min=0;
        sek=0;
    }
    Time(int o, int m , int s){
        ore=o;
        min=m;
        sek=s;
    }
    friend istream& operator >>(istream& input, Time& koha);
    friend ostream& operator<<(ostream& output, Time& koha);
    friend bool operator== (Time& k1, Time& k2);
    friend bool operator > (Time& k1, Time& k2);
    Time operator +(Time& k){
        Time k1;
        int a, b;
        a=sek + k.sek;
        k1.sek=a%60;
        b=(a/60)+min+k.min;
        k1.min=b%60;
        k1.ore=(b/60)+ore+k.ore;
        //k1.ore=k1.ore%12;
        return k1;
    }

};

istream& operator >>(istream& input, Time& koha){
    cout<<"\nVendos oren : ";
    input>>koha.ore;
    cout<<"\nVendos minutat : ";
    input>>koha.min;
    cout<<"\nVendos sekondat  : ";
    input>>koha.sek;
    return input;
}

ostream& operator<<(ostream& output, Time& koha){
    output<<"Koha : "<<setw(2)<<setfill('0')<<koha.ore<<" : "<<setw(2)<<setfill('0')<<koha.min<<" : "<<setw(2)<<setfill('0')<<koha.sek;
    return output;
}

bool operator== (Time& k1, Time& k2){
    return (k1.ore==k2.ore && k1.min==k2.min && k1.sek==k2.sek);
}

bool operator > (Time& k1, Time& k2){
    return (k1.ore>k2.ore && k1.min>k2.min && k1.sek>k2.sek);
}



int main() {
    int oret, minutat, sekondat;
    Time koha1 (oret, minutat, sekondat);
    cout<<"Koha 1 : ";
    cin>>koha1;
    Time koha2 (oret, minutat, sekondat);
    cout<<"\nKoha 2 : ";
    cin>>koha2;

    cout<<"\nKoha 1 qe ju vendoset eshte : ";
    cout<<koha1;

    cout<<"\nKoha 2 qe ju vendoset eshte : ";
    cout<<koha2;

    if (koha1==koha2){
        cout<<"\nKohet jane te barabarta.";
    }
    else{
        cout<<"\nKohet nuk jane te barabarta. ";
    }

    if (koha1>koha2){
        cout<<"\nKoha e pare eshte me e madhe se koha e dyte. ";
    }
    else{
        cout<<"\nKoha e dyte eshte me e madhe se koha e pare. ";
    }
    Time koha3(oret, minutat, sekondat);
    koha3 = koha1 + koha2;
    cout<<"\nShuma e kohes se pare me kohen e dyte eshte : ";
    cout<<koha3;
    return 0;
}
