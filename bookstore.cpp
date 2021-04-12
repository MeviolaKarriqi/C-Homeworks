#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class librari
{

    char autori[20];
    char titulli[20];
    double cmimi;
    int neGjendje;
public:
    librari();
    void futTedhenat();
    void shfaq();
    int kerko(char[],char[]);
    void skaKopje(int);
};
librari::librari()
{
    char *autori=new char[50];
    char * titulli=new char[50];
    cmimi=0;
    neGjendje=0;
}
void librari::futTedhenat()
{
    cout<<"\n Vendosni emrin e librit:";
    cin>>titulli;
    cout<<"\n Vendosni emrin e autorit:";
    cin>>autori;
    cout<<"\n Vendosni cmimin:";
    cin>>cmimi;
    cout<<"\n Vendosni sa libra ka ne gjendje:";
    cin>>neGjendje;
}


void librari::shfaq()
{
    cout<<"\n "<<titulli<<"\t\t "<<autori<<"\t\t  "<<cmimi<<"\t "<<neGjendje;
}
int librari::kerko(char t[],char a[])
{
    if(strcmp(titulli,t)&&(strcmp(autori,a)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void librari::skaKopje(int num)
{
    if(neGjendje>=num)
    {
        cout<<"\n Titulli ne gjendje";
        cout<<"\n Kostoja "<<num<<" librit."<<(cmimi*num);
    }
    else
    {
        cout<<"\n Libri i kerkuar nuk eshte ne gjendje";
    }
}
int main()
{
    int z,n,i,flag=0,kopje,index=0;
    librari lib[100];
    char emriLibrit[50],emriAutor[50];
    do
    {
        cout<<"\n\t\tMENU";
        cout<<"\n 1. Vendosni te dhenat e librit \n 2.Shfaq \n 3.Kerko \n 4.Dil";
        cout<<"\n Ju lutem beni zgjedhjen tuaj nga menuja:";
        cin>>z;
        switch(z)
        {
            case 1:
                cout<<"\n Sa libra doni te vendosni";
                cin>>n;
                for(i=0;i<n;i++)
                {
                    lib[i].futTedhenat();
                }
                break;
            case 2:
                cout<<"\n"<<"TITULLI"<<"\t \t "<<"AUTORI"<<"\t\t"<<"CMIMI"<<"\t "<<"NE GJENDJE";
                for(i=0;i<n;i++)
                {
                    cout<<"\n";

                    lib[i].shfaq();
                }

                break;

            case 3:
                cout<<"\n Vendosni emrin e librit qe kerkoni";
                cin>>emriLibrit;
                cout<<"\n Vendosni emrin e autorit te librit";
                cin>>emriAutor;

                for(i=0;i<n;i++)
                {
                    if(lib[i].kerko(emriLibrit,emriAutor))
                    {
                        flag=1;
                        cout<<"\n"<<"TITULLI"<<"\t \t "<<"AUTORI"<<"\t\t"<<"CMIMI"<<"\t "<<"NE GJENDJE";
                        lib[i].shfaq();
                        index=i;
                    }
                }
                if(flag==1)
                    cout<<"\n Libri eshte ne gjendje";
                else
                {
                    cout<<"\n Libri nuk eshte ne gjendje";
                    break;
                }
                if(flag==1)
                {
                    cout<<"\nSa libra te tille kerkoni";
                    cin>>kopje;
                    lib[index].skaKopje(kopje);
                }

                break;
            case 4: exit(EXIT_SUCCESS);
            default :
                cout<<"\n Zgjedhje e gabuar";
                break;
        }
    }while(z!=5);
    return 0;
}
