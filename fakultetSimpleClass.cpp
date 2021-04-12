//Ndertoni nje klase Fakultet qe ruan emrin dhe numrin e studenteve te nje fakulteti.
// Ndërtoni për të konstruktorin me parametra. Ndërtoni metodën vendosVlera për ti dhënë vlerë variablave
// të instances, nga një metode që kthen secilën prej variablave të instancës, si dhe një metodë afisho
// që i afishon në ekran. Ndertoni operatorin overload > per klasen Fakultet  duke u bazuar tek numri
// i studenteve. Implementioni kete operator si anetar klase dhe si funksion friend.
// Perdorini te dyja versionet
#include <iostream>
using namespace std;

class student {
    friend class fakultet;
private:
    int id;
    double mes;
    char *emri;
public:
    student() {
        id = 0;
        mes = 3.0;
        emri = "null";
    }
};

class fakultet {
private:
    student *studenti;
    int size;
public:
    fakultet(int num) {
        studenti = new student[num];
        size = num;
    }
    void vendostedhenat();
    void ndryshomes(int id, double newgpa);
    double merrmes(int id);
    friend class afishoClass;
};

void fakultet::vendostedhenat() {
    int i;
    for(int i=0; i<size; i++){
        studenti[i].id = i;
    }

}

void fakultet::ndryshomes(int id, double mesere) {
    int i;
    for(i=0; i<size; i++) {
        if(studenti[i].id == id) {
            studenti[i].mes = mesere;
            return;
        }
    }
}

double fakultet::merrmes(int id) {
    int i;
    for(i=0; i<size; i++)
        if(studenti[i].id == id)
            return studenti[i].mes;
    return 1;
}
class afishoClass{
public:
    void printoTeDhenat(){

    }
};

int main(){
    int i;
    fakultet amr(100);

    for(i=0; i<100; i++)
        amr.vendostedhenat();
    amr.ndryshomes(50, 3.99);
    cout << "ID#50 ka " << amr.merrmes(50) << " mesatare\n";
    return 0;
}
