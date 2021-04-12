/*
Supozojme se nje banke mban 2 lloje llogarish per klientet e saj: nje llogari rrjedhese dhe nje llogari kursimi.Llogaria e kursimit
 ofron interes mbitotalin e kursyer si dhe opsionin e terheqjes. Nderkohe llogaria rrjedhese nuk ofron interesin.
 Te gjithe klientet qe kane llogari rrjedhese gjithashtu  duhet te mbajne nje balance minimale dhe nese balanca
 e llogarise bie nen kete limit, atehere nje kosto shtese I faturohet klientit per cdo sherbim.
 Krijoni nje klase ACCOUNT e cila ruan emrin e klientit, numrin e llogarise dhe tipin e llogarise.
 Prej kesaj klase, derivoni 2 klasat Curr_act dhe Sav_act te cilat jane specifike sipas pershkrimit me siper.
 Perfshini ne dizenjim te klasave edhe funksionet e meposhtme:
 1.Te realizohet derdhja / depozita e klientit dhe te azhornohet balanca
 2.Te afishoje balancen e llogarise
 3.Perllogarise dhe te depozitoje interesin
 4.Lejoje terheqjen dhe te upadate-je balancen
 5.Te kontrolloje balancen, te vendose penalitet (nese duhet) dhe te azhornoje balancen
*/


#include <iostream>
#include <conio.h>
using namespace std;

class Account{
private:
    string clientName;
    int idOfAcc;
protected:
    int balance;
public:
    Account(){

    }
    Account(string c, int id, int bal){
        clientName = c;
        idOfAcc = id;
        balance = bal;
    }
    void setClientName(string cli){
        clientName  = cli;
    }
    string getClientName(){
        return clientName;
    }
    void setIDOfAcc(int idO){
        idOfAcc = idO;
    }
    int getIDOfAcc(){
        return idOfAcc;
    }
    void setBalance(int bala){
        balance = bala;
    }
    int getBalance(){
        return balance;
    }
    void shfaq(){
        cout<<clientName<<endl;
        cout<<idOfAcc<<endl;
        cout<<balance;
    }
};

class Curr_Acc : public Account{
public:
    Curr_Acc(){
        balance = 3000;
    }
    void terheqje(){
        cout<<"Vendosni vleren qe doni te terhiqni : \n";
        int vlera;
        cin>>vlera;
        if(vlera > balance){
            cout<<"Ju nuk keni balance te mjaftueshme per te terhequr kete vlere!"<<endl;
        }
        else{
            if(vlera>5000){
                cout<<"NE nje llogari rrjedhje nuk mund te terhiqni me shume se 5000!"<<endl;
            }else{
                cout<<"Vlera e terhequr eshte : "<<vlera;
                cout<<"Balanca e mbetur ne llogarine tuaj eshte : ";
                balance = balance - vlera;
                cout<<balance;
            }
        }
        getch();
    }
    void depozitim(){
        cout<<"Vendosni vleren qe doni te depozitoni : ";
        int vlera;
        cin>>vlera;
        cout<<"\nVlera qe ju keni depozituar eshte : "<<vlera;
        balance = balance + vlera;
        cout<<"\nBalanca juaj eshte : "<<balance;
        getch();
    }
};
class Sav_Acc  : public Account{
public:
    Sav_Acc(){
        balance = 0;
    }
    void terheqje(){
        cout<<"\n\nVendosni vleren qe doni te terhiqni : ";
        int vlera;
        cin>>vlera;
        if(vlera > balance){
            cout<<"\n\nVlera e dhene eshte me e madhe se balanca jua! ";
        }
        else{
            cout<<"\n\nVlera e terhequr eshte "<<vlera;
            cout<<"\n\nBalanca juaj eshte : ";
            balance = balance - vlera;
            cout<<balance;
        }
        if(balance<1000){
            balance = balance - (.01*(1000-balance));
            cout<<"Balanca pas shtimit te interesit eshte : "<<balance<<endl;
        }
        getch();
    }
    void depozitim(){
        int vlera;
        cout<<"\nVendosni vleren qe doni te depozitoni : ";
        cin>>vlera;
        cout<<"Vlera qe ju depozituat eshte : "<<vlera<<endl;
        cout<<"\nBalanca pas depozitimit eshte : ";
        balance = balance + vlera;
        cout<<balance;
        getch();
    }
};
int main(){
    Curr_Acc currAcc;
    Sav_Acc savAcc;
    Account("Meviola", 1213, 7000);

    cout<<"\n################################################################################################################\n";
    cout<<"                       MENU                                               "<<endl;
    cout<<"Vendosni 1 per llogari rrjedhese"<<endl;
    cout<<"Vendosni 2 per llogari kursimi"<<endl;
    int opsioni;
    cin>>opsioni;
    if (opsioni = 1){
        int ops;
        while (ops!=4){
            cout<<"\n########################################################################################################\n";
            cout<<"\n                             MENU                                                      "<<endl;
            cout<<"Vendos 1 per te terhequr "<<endl;
            cout<<"Vendos 2 per te depozituar "<<endl;
            cout<<"Vendos 3 per te shfaqur "<<endl;

            cin>>ops;
            switch(ops){
                case 1:
                    currAcc.terheqje();
                    break;
                case 2:
                    currAcc.depozitim();
                    break;
                case 3:
                    currAcc.shfaq();
                    break;
                case 4:
                    break;
            }
        }

    }else{
        int ops;
        while (ops!=4){
            cout<<"\n########################################################################################################\n";
            cout<<"\n                             MENU                                                      "<<endl;
            cout<<"Vendos 1 per te terhequr "<<endl;
            cout<<"Vendos 2 per te depozituar "<<endl;
            cout<<"Vendos 3 per te shfaqur "<<endl;

            cin>>ops;
            switch(ops){
                case 1:
                    currAcc.terheqje();
                    break;
                case 2:
                    currAcc.depozitim();
                    break;
                case 3:
                    currAcc.shfaq();
                    break;
                case 4:
                    break;
            }
        }
    }
    return 0;
}
