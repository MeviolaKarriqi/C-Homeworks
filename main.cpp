/*
 * Ndertoni nje klase qe per disqet e nje videoteke , ruan daten e daljes ne treg dhe kohezgjatjen e diskut.
 * Klasa duhet te permbaje nje konstruktor me parametra, nje metode qe do te vendose vlerat e variablave
 * te instances dhe dy metoda qe do te kthejne vlerat e tyre.
 * Ndertoni nje klase per albumet e kengeve e cila do te derivoje nga klasa e disqeve.
 * Kjo klase do te ruaje titullin e albumit, si dhe nje vektor me rekorde, qe do te mbaje titujt dhe kengetaret
 * e kengeve te albumit. Klasa ne konstruktorin e saj, nder te tjera, do ti jape vlere titullit dhe do te populloje
 * vektorin duke i marre vlerat nga nje skedar. Ky skedar, ne cdo dy rreshta te tij do te mbaje te dhenat e nje kenge.
 * Ai do te kete pamjen e meposhtme:
 *
 * Kenge.txt
 * kengetar1
 * titull1
 * kengetar2
 * titull2
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Disqe{
private:
    string data;
    string kohezgjatja;
public:
    Disqe(string date , string kohe){
        data = date;
        kohezgjatja = kohe;
    }
    string getDaten (){
        return data;
    }
    void setDaten(string dataa){
        this->data = dataa;
    }
    string getKhezgjatjen (){
        return kohezgjatja;
    }
    void setKohezgjatjen(string kohee){
        this->kohezgjatja = kohee;
    }
};
class Albume : public Disqe{
private:
    string emriIAlbumit;
    vector<string>tituj;
public:
    Albume(string date, string kohe, string emri, vector<string> titujj) : Disqe(date, kohe) {
        emriIAlbumit = emri;
        tituj =titujj;
    }

    string getEmri(){
        return emriIAlbumit;
    }
    void setEmri(string emri){
        emriIAlbumit = emri;
    }
    vector<string> getTituj(){
        return tituj;
    }
    void setTituj(vector<string>titujj){
        tituj = titujj;
    }
    bool mbushVecMeAneTeSkedarit(string emriSkedarit , vector<string> & vecITitujve){
        ifstream in(emriSkedarit.c_str());
        if(!in){
            cerr<<"Nuk mundemi te hapim kete skedar! "<<endl;
            return false;
        }
        string str;
        while(getline(in, str)){
            if (str.size()>0){
                vecITitujve.push_back(str);
            }
        }
        in.close();
        return true;
    }
};

int main() {
    string data;
    string koha;
    string emriIAlbumit;
    vector<string>tituj;
    cout<<"Jepni daten e daljes ne treg te albumit : "<<endl;
    cin>>data;
    cout<<"Jepni kohezjatjen e albumit : "<<endl;
    cin>>koha;
    cout<<"Jepni emrin e Albumit : "<<endl;
    cin>>emriIAlbumit;
    Albume albume(data, koha, emriIAlbumit, tituj);
    bool titujtt = albume.mbushVecMeAneTeSkedarit("albume.txt", tituj);
    if (titujtt){
        for (string & line : tituj){
            cout<<line<<endl;
        }
    }

    return 0;
}
