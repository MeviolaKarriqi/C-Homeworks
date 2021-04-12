/*
 * Dizenjoni te gjitha klasat e nevojshme per te krijuar nje program I cili realizon:
 * 1)	Krijon nje llogari (Account) per klientin me nje username dhe password
 * 2)	Login ne sistem permes username dhe password
 * 3)	Logout nga sistemi
 * Nese login ne sistem per perdoruesin/klientin eshte e suksesshme, atehere perdoruesi mund te :
 * 1)	Shikoje profilin e tij ne sistem
 * 2)	Te ndryshoje te dhenat ne profil (emri, mbiemri, viti I lindjes, email, nr Tel, te dhenat per edukimin e tij te
 *      pergjithshem dhe universitar)
 *      3)	Te dale nga sistemi
 *      Nese hyrja ne sistem nuk ka qene e suksesshme (nese username ose password nuk jane perputhur), atehere perdoruesi
 *      do te dergohet ne faqen e pare, ku do ti ofrohen 3 opsione:
 *      -	Login
 *      -	Krijo nje llogari te re me informacionin e detyrueshem per : emri, mbiemri, email , username, password,
 *          dhe informacion opsional : viti I lindjes, nr Tel, te dhenat per edukimin e tij te pergjithshem dhe universitar
 *          -	Dil/Logout
 *          Format e inputit per regjistrim dhe ndryshim te informacionit te jene te formatuara si me poshte, psh:
 *          Emri, mbiemri , username – te jene string dhe te mos permbaje asnje karakter numerik
 *          Email - te verifikohet saktesia e email duke kontrolluar nese stringu I futur nga perdoruesi permban @ dhe .
 *          NrTel - te jete I perbere vetem nga karaktere numerike dha asnje karakter tjeter
 *          Viti I lindjes – te jete sipas formatit  yyyy.mm.dd
 *          Password – te kontrollohet qe te permbaje te pakten: nje germe kapitale, nje germe jokapitale, nje karakter special,
 *          nje numer dhe te kete nje gjatesi jo me pak se 8 karaktere gjithsej.

 */
#include <iostream>

using namespace std;

class Llogari{
private:
    string emri;
    string mbiemri;
    string username;
    string nrTel;
    string email;
    string password;
    int dd,mm,yyyy;
public:
    Llogari(string e, string m, string u, string n, string em, string p, int d, int mu, int y){
        emri = e;
        mbiemri = m;
        username = u;
        nrTel = n;
        email = em;
        password = p;
        dd = d;
        mm = mu;
        yyyy = y;
    }
    string getEmri(){
        return emri;
    }
    void setEmri(string emrii){
        emri = emrii;
    }
    string getMbiemri(){
        return mbiemri;
    }
    void setMbiemri(string mbiemrii){
        mbiemri = mbiemrii;
    }
    string getUsername(){
        return username;
    }
    void setUsername(string usernamee){
        username = usernamee;
    }

    string getEmail(){
        return email;
    }
    string getNrTel(){
        return nrTel;
    }
    void setnrTel(string nrtell){
        nrTel = nrtell;
    }
    void setEmail(string emaill){
        int uGjet = emaill.find('@');
        if(uGjet < emaill.size()){
            email = emaill;
        }
    }
    string getPassword(){
        return password;
    }
    void setPassword(string passwordd){
        email = passwordd;
    }
    int getDd(){
        return dd;
    }
    void setDd(int dita){
        if (dita<=31){
            dd = dita;
        }
    }
    int getMm(){
        return mm;
    }
    void setMm(int muaji){
        if (muaji<=12){
            dd = muaji;
        }
    }
    int getYyyy(){
        return yyyy;
    }
    void setYyyy(int viti){
        dd = viti;
    }
    void vendosDaten(int dita, int muaji, int viti){
        cout<<"Jepni diten : ";
        cin>>dita;
        cout<<"Jepni muajin : ";
        cin>>muaji;
        cout<<"Jepni vitin : ";
        cin>>viti;
    }
    void shfaqDaten(){
        cout<<this->dd<<"."<< this->mm<<"."<< this->yyyy;
    }

    bool passwordIvlefshem(string passwordd){
        if ((passwordd.length()>=8) && (passwordd.length() <=15)){
            return false;
        }
        if (!((passwordd.find("@")!= std::string::npos) || (passwordd.find("!")!= string::npos) || (passwordd.find("#")!= std::string::npos) ||
              (passwordd.find("$")!= std::string::npos) || (passwordd.find("^")!= std::string::npos)|| (passwordd.find("&")!= std::string::npos) ||
              (passwordd.find("*")!= std::string::npos) || (passwordd.find("(") != std::string::npos) || (passwordd.find(")") != std::string::npos) ||
              (passwordd.find("-") != std::string::npos) || (passwordd.find("+") != std::string::npos) || (passwordd.find("/") != std::string::npos) ||
              (passwordd.find(":") != std::string::npos) || (passwordd.find(".") != std::string::npos) || (passwordd.find(",") != std::string::npos) ||
              (passwordd.find("<") != std::string::npos) || (passwordd.find(">") != std::string::npos) || (passwordd.find("?") != std::string::npos) ||
              (passwordd.find("|") != std::string::npos))){
            return false;
        }
        if (true){
            int counter = 0;
            for (int i = 65; i < 90; ++i) {
                char c = (char) i;
                string str1(1,c);
                if (passwordd.find(str1) != std::string::npos){
                    counter = 1;
                }
                if(counter == 0){
                    return false;
                }
            }
        }
        if (true){
            int counter = 0;
            for (int i = 90; i < 120; ++i) {
                char c = (char) i;
                string str1(1,c);
                if (passwordd.find(str1) != std::string::npos){
                    counter = 1;
                }
                if(counter == 0){
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Llogari llogari1("Jane", "MacTomson", "janeMacTomson123", "82137126372","janeMacTomson@gmail.com","Pass123#", 12,2,1955);
    string emri, mbiemri, username, numriITeel, emaili, password;
    int data, muaji, viti;
    Llogari llogari2(emri, mbiemri, username, numriITeel, emaili, password, data, muaji, viti);
    cout<<"##################################### MENU ###########################################"<<endl;
    cout<<"1). Ndryshoni llogarine tuaj "<<endl;
    cout<<"2). Shikoni llogarine tuaj "<<endl;
    cout<<"3). Per te dale <-] "<<endl;
    int ops;
    int ops1;
    string pass;
    cin>>ops;
    while (ops!=3){
        switch (ops) {
            case 1:
                cout<<"Vendosni paswordin per te shfaqur llogarine tuaj : ";
                cin>>pass;
                if (pass==llogari1.getPassword()){
                    cout<<"1).NDRYSHONI EMRIN "<<endl;
                    cout<<"2).NDRYSHONI MBIEMRIN "<<endl;
                    cout<<"3).NDRYSHONI USERNAME "<<endl;
                    cout<<"4).NDRYSHONI EMAILIN "<<endl;
                    string emriIRi, mbiermiIRi, usernameIRi, emailiIRi;
                    cin>>ops1;
                    switch(ops1){
                        case 1:
                            cout<<"Vendos emrin e ri : "<<endl;
                            cin>>emriIRi;
                            llogari1.setEmri(emriIRi);
                            break;
                        case 2:
                            cout<<"Vendos mbiemrin e ri : "<<endl;
                            cin>>mbiermiIRi;
                            llogari1.setMbiemri(mbiermiIRi);
                            break;
                        case 3:
                            cout<<"Vendos username e ri : "<<endl;
                            cin>>usernameIRi;
                            llogari1.setUsername(usernameIRi);
                            break;
                        case 4:
                            cout<<"Vendos emailin e ri : "<<endl;
                            cin>>emailiIRi;
                            llogari1.setEmail(emailiIRi);
                            break;
                    }
                }
                else{
                    cout<<"Krijoni nje llogari te re "<<endl;
                    cout<<"Vendosni emrin : "<<endl;
                    cin>>emri;
                    llogari2.setEmri(emri);
                    cout<<"Vendosni mbiemrin : "<<endl;
                    cin>>mbiemri;
                    llogari2.setMbiemri(mbiemri);
                    cout<<"Vendosni username : "<<endl;
                    cin>>username;
                    llogari2.setUsername(username);
                    cout<<"Vendosni emailin : "<<endl;
                    cin>>emaili;
                    llogari2.setEmail(emaili);
                    cout<<"Vendosni numrin e tel : "<<endl;
                    cin>>numriITeel;
                    llogari2.setnrTel(numriITeel);
                    cout<<"Vendosni daten muajin dhe vitin : "<<endl;
                    cin>>data;
                    cin>>muaji;
                    cin>>viti;
                    llogari2.setDd(data);
                    llogari2.setMm(muaji);
                    llogari2.setYyyy(viti);
                    cout<<"Vendosni password : "<<endl;
                    cin>>password;
                }
                break;
            case 2:
                cout<<llogari1.getEmri()<<endl;
                cout<<llogari1.getMbiemri()<<endl;
                cout<<llogari1.getEmail()<<endl;
                cout<<llogari1.getUsername()<<endl;
                cout<<llogari1.getDd()<<"."<<llogari1.getMm()<<"."<<llogari1.getYyyy()<<endl;
            case 3:
                break;
        }
    }

    return 0;
}
