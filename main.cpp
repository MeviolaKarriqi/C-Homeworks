/*
 * 1.Ndertoni nje klase Karte_Klienti per bleresit e nje rrjeti supermarketesh. Per nje kate do te ruhet emri I
 * zoteruesit te kartes, numri aktuel I pikeve dhe nje container me blerjet e kryera. Per cdo blerje te ruhet vlera ne
 * leke e blerjes dhe piket qe perfitohen. (krijoni nje tip te ri te strukturuar per blerjet)
 * Klasa duhet te ofroje keto veprime:
 * Te jape mundesine e krijimit te nje karte klienti duke specifikuar emrin, piket dhe emrin e nje skedari qe do te permbaje
 * te dhenat e blerjeve te kryera. Ne kete skedar cdo blerje do te jete ne rresht te vecante dhe vlerat e blerjes te ndara me hapesira.
 * Piket e nje karte do te llogariten duke marre parasysh gjithe blerjet e kryera. Merrni parasysh perdorimin e kujteses ne rastet kur
 * skedari mund te kete nje nr shume te madh blerjesh. (30 pike)
 * Te kryeje blerje me nje vlere te caktuar dhe te modifikoje te dhenat e kartes pas blerjes. Per cdo 10 leke perfitohet 1 pike. (10pike)
 * Te ktheje zoteruesin, numrin e pikeve si dhe vleren totale te blerjeve. (10 pike)
 * Perdorni klasen dhe gjithe funksionalitet e saj. (10 pike)
 */
#include <iostream>
#include <fstream>

using namespace std;

class Karte_Klienti{
private:
    string emriIKlientit;
    double numriAktualIPikeve;

};

int main() {


    return 0;

}
/*
 * fstream file; //object of fstream class

    //opening file "sample.txt" in out(write) mode
    file.open("sample.txt",ios::out);

    if(!file)
    {
        cout<<"Error in creating file!!!"<<endl;
        return 0;
    }

    cout<<"File created successfully."<<endl;
    //write text into file
    file<<"ABCD.";
    //closing the file
    file.close();

    //again open file in read mode
    file.open("sample.txt",ios::in);

    if(!file)
    {
        cout<<"Error in opening file!!!"<<endl;
        return 0;
    }

    //read untill end of file is not found.
    char ch; //to read single character
    cout<<"File content: ";

    while(!file.eof())
    {
        file>>ch; //read single character from file
        cout<<ch;
    }

    file.close(); //close file
 */