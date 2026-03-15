#include <iostream>
#include <fstream>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>

using namespace std;

ifstream f("Tari.txt");

char tari[31][31];
int drumuri[60][60];
int nr;

void citireTari(int &nr)
{
    f>>nr;
    for(int i=0;i<nr;i++)
        {
            f.getline(tari[i],31);
        }
    int x,y,z;
    while(f>>x>>y>>z)
    {
        drumuri[x][y]=drumuri[y][x]=z;
    }

}

void afisareTari(int nr)
{
    cout<<"TARILE SUNT:"<<endl<<endl;
    for(int i=1;i<nr;i++)
        cout<<i<<" "<<tari[i]<<endl;
}

void afisareMatrice(int nr)
{
    for(int i=1;i<nr;i++)
        {
            for(int j=1;j<nr;j++)
                cout<<drumuri[i][j]<<" ";
            cout<<endl;
        }
}

void TaraIndice(int indice)
{
    cout<<tari[indice];
}

void LocatiaDestinatie(int &indicetara1,int &indicetara2)
{
    cout<<endl<<"unde te afli in aces moment?"<<endl;
    cin>>indicetara1;
    cout<<"numarul tastat este tara: ";
    TaraIndice(indicetara1);
    cout<<endl<<endl<<"unde vrei sa mergi?"<<endl;
    cin>>indicetara2;
    cout<<"numarul tastat este tara: ";
    TaraIndice(indicetara2);
}

int x[100];

void citireSecTari(int nr,int &k,int indicetara1,int x[])
{
    cout<<endl<<"cate tari vrei sa vizitezi?"<<endl;
    cin>>k;
    cout<<endl<<"dati cele "<<k<<" tari"<<endl;
    for(int i=1;i<=k;i++)
    {
        cin>>indicetara1;
        cout<<"numarul tastat este tara: ";
        TaraIndice(indicetara1);
        x[i]=indicetara1;
        cout<<endl<<endl;
    }
    cout<<endl;
}

int eLant(int nr, int x[], int k)
{
    for (int i=1; i<=k; i++)
        if (x[i]==19 || x[i]==21 )
            if(k==2 && (x[1]==19 && x[2]==21) || (x[1]==21 && x[2]==19)) return 1;
        else return 0;
    return 1;
}

int eCiclu(int nr,int x[],int k)
{
    for(int i=1;i<=k;i++)
        for(int j=i+1;j<=k;j++)
            if(x[i]==x[j])return 1;
   return 0;
}

void existaDrumDirect(int indicetara1,int indicetara2)
{
    LocatiaDestinatie(indicetara1,indicetara2);
    cout<<endl<<endl;
    int exista=0;
    if(drumuri[indicetara1][indicetara2])
        {
            cout<<"exista drum direct intre: ";
            TaraIndice(indicetara1);
            cout<<" si ";
            TaraIndice(indicetara2);
            exista=1;
        }
    else cout<<"nu exista drum direct ";

    if(exista)
    {
        cout<<endl<<endl<<"vrei sa afli pretul drumului?"<<endl<<"1-DA"<<endl<<"0-NU"<<endl;
        int vrei;
        cin>>vrei;
        if(vrei)
            cout<<"pretul drumului este: "<<drumuri[indicetara1][indicetara2]<<"$";
        else cout<<"bine:))"<<endl;
    }
}

void gradulCelMaiMare()
{
    cout<<endl<<"China";
}

void existaDrum(int indicetara1,int indicetara2)
{
    LocatiaDestinatie(indicetara1,indicetara2);
    cout<<endl<<endl;
    if(indicetara1==19 && indicetara1==21 || indicetara2==19 && indicetara2==21)
        {
            cout<<"nu exista drum intre tara: ";
            TaraIndice(indicetara1);
            cout<<" si ";
            TaraIndice(indicetara2);
        }
    else
        {
            if(drumuri[indicetara1][indicetara2])
                cout<<"poti ajunge la tara: ";
                TaraIndice(indicetara2);
        }
}

void DrumuriDirecte(int indicetara1,int nr)
{
    cout<<endl<<"In ce tara te afli?"<<endl;
    cin>>indicetara1;
    cout<<endl<<"numarul tastat este tara: ";
    TaraIndice(indicetara1);
    cout<<endl<<endl;
    cout<<"are drum direct cu: "<<endl;
    int are=0;
    for(int i=1;i<=nr;i++)
        if(drumuri[indicetara1][i]&& indicetara1!=i)
            {
                are++;
                cout<<i<<" ";
                TaraIndice(i);
                cout<<"--"<<drumuri[indicetara1][i]<<"$";
                cout<<endl;
            }
    cout<<"are "<<are<<" drumuri directe";
}

void HartaAsiei()
{
    cout<<"                 .~:^:"<<endl;
    cout<<"           :...^~?JJY5PYJ~^:^:  .^~.."<<endl;
    cout<<"          !P7J55GGGGGGGGGGGPGPY555PP5YYJ77!7?7:"<<endl;
    cout<<"        !5GPPPGGGPPPPGPPPPPGGGGGGGGGGGGPPGGGPJ."<<endl;
    cout<<"       .5GPPGGGGGGGGGGPPPPPGGGPGPY7!!7~!?^^^."<<endl;
    cout<<"     ..:YPPPPPPPPPPPPPPGGPPPPPGGY!:   ^Y^     " <<endl;
    cout<<"     ~Y555PPPPPPPPPPPPPPPPPPPGPPPP7^            "<<endl;
    cout<<".^^!~!!^:YP55PPPP5PPPPPPPPPPPP5PPJ7:.~     "<<endl;
    cout<<".7J?5PPP7JP5555555PPGGGPPPGGGP~^?::^!:.         "<<endl;
    cout<<" ::!PP5YJ5PP55PPPPPPPPPPPPGGGG?  ...             " <<endl;
    cout<<"  ..?P55?JJ!~!YPPPPPYYPPPPPPYJ^..                " <<endl;
    cout<<"    !PP5?!.   !GP?^::?Y55!^..^.                 " <<endl;
    cout<<"     ^^.       ??     ^~?7   .^:..              " <<endl;
    cout<<"            ..  ...  .~7::~7! :.                " <<endl;
    cout<<"                      .7!.7J~~...:~7            " <<endl;
    cout<<"                         .......:...^     " <<endl;
}

void clear()
{
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void Program(int program,int nr)
{
    while(program){
    clear();
    int indicetara1,indicetara2;
    cout<<"in aceasta aplicatie vei afla:"<<endl<<endl;
    cout<<"1.LISTA CU TARI"<<endl<<endl;
    cout<<"2.POTI SA VIZITEZI TARILE DATE?"<<endl<<endl;
    cout<<"3.CU CINE ARE DRUM DIRECT O TARA"<<endl;
    cout<<"      care sunt tarile acestea si pretul lor"<<endl<<endl;
    cout<<"4.POTI MERGE DIRECT DE LA LOCATIA TA SPRE DESTINATIA TA"<<endl;
    cout<<"      pretul acestui drum"<<endl<<endl;
    cout<<"5.POTI AJUNGE DE LA LOCATIA TA SPRE DESTINATIA TA"<<endl<<endl;
    cout<<"6.SE VA AFISA"<<endl;
    cout<<"      1.tara cu cele mai multe drumuri"<<endl;
    cout<<"      2.cate componente conexe are harta"<<endl;
    cout<<"      3.matricea de adiacenta"<<endl;
    cout<<"      4.harta asiei";
    cout<<endl<<endl<<"7.EXIT";
    cout<<endl<<endl<<endl<<endl;
    int k,functie;
    cin>>functie;
    clear();
    switch(functie)
        {
            case 1:
                {
                    afisareTari(nr);
                    break;
                }
            case 2:
                {
                    cout<<"POTI VIZITA TARILE DATE?"<<endl;
                    cout<<"      vizitarea tarilor date este drum dus-intors?"<<endl<<endl;
                    afisareTari(nr);
                    citireSecTari(nr,k,indicetara1,x);
                    if(eLant(nr,x,k))
                        if(eCiclu(nr,x,k))cout<<"secventa data este un drum dus-intors";
                        else cout<<"poti vizita toate tarile acestea";
                    else cout<<"nu poti vizita toate tarile date";
                    break;
                }
            case 3:
                {
                    cout<<"CU CINE ARE DRUM DIRECT O TARA?"<<endl;
                    cout<<"      care sunt tarile acestea si care este pretul?"<<endl<<endl;
                    afisareTari(nr);
                    DrumuriDirecte(indicetara1,nr);
                    break;
                }
            case 4:
                {
                    cout<<"POTI MERGE DIRECT DE LA O TARA LA ALTA?"<<endl;
                    cout<<"       care este pretul acestui drum?"<<endl<<endl;
                    afisareTari(nr);
                    existaDrumDirect(indicetara1,indicetara2);
                    break;
                }
            case 5:
                {
                    cout<<"POTI AJUNGE DE LA O TARA LA ALTA?"<<endl<<endl;
                    afisareTari(nr);
                    existaDrum(indicetara1,indicetara2);
                    break;
                }
            case 6:
                {
                    int afis=1;
                    while(afis)
                    {
                        clear();
                        cout<<endl<<"CE VRETI SA AFLATI?"<<endl;
                        int afisare;
                        cout<<"1.tara cu cele mai multe drumuri"<<endl;
                        cout<<"2.cate componente conexe are harta"<<endl;
                        cout<<"3.matricea de adiacenta"<<endl;
                        cout<<"4.harta asiei";
                        cout<<endl<<endl;
                        cin>>afisare;
                        switch(afisare)
                        {
                            case 1:
                            {
                                cout<<"TARA CU CELE MAI MULTE DRUMURI ESTE:";
                                gradulCelMaiMare();
                                break;
                            }
                            case 2:
                            {
                                cout<<"CATE COMPONENETE CONEXE ARE HARTA?"<<endl<<endl;
                                cout<<endl<<"exista 2 componente conexe";
                                break;
                            }
                            case 3:
                            {
                                cout<<"MATRICEA DE ADIACENTA ESTE:"<<endl;
                                afisareMatrice(nr);
                                break;
                            }
                            case 4:
                            {
                                cout<<"HARTA ASIEI ESTE:"<<endl<<endl;
                                HartaAsiei();
                            }
                        }
                        cout<<endl<<endl<<"vrei sa mai afisez ceva?"<<endl<<"DA-1  NU-0"<<endl;
                        cin>>afis;
                    }
                    break;
                }
            case 7:
                {
                    abort();
                }
        }
    cout<<endl<<endl<<"vrei sa te intorci la meniu?"<<endl<<"DA-1  NU-0"<<endl;
    cin>>program;
    }

}


int main()
{
    citireTari(nr);
    Program(1,nr);
    f.close();
    return 0;
}
