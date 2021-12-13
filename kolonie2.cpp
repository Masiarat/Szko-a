#include<iostream>
#include<vector>
using namespace std;

class kolonia{
    public:
    int IQ_MAX;
    int IQ_MIN;
    int mass;
    vector<int> NalezaceBakterie;
};

class bakteria{
    public: 
    int IQ;
    int mass;
    kolonia *doJakiejKoloniiNalezy = NULL;
};

 
bakteria bakterie[1000000];
vector<kolonia> kolonie;

void stworzKolonie(bakteria *bak1,bakteria *bak2,int l1, int l2){
    //cout << "tworzeKolonie" << endl;
    kolonia *temp = new kolonia();
    //iq
    if (bak1->IQ > bak2->IQ)
    {
        temp->IQ_MAX = bak1->IQ;
        //cout << "bak1->IQ: " << bak1->IQ << endl;
        temp->IQ_MIN = bak2->IQ;
    }else
    {
        temp->IQ_MAX = bak2->IQ;
        //cout << "bak2->IQ: " << bak2->IQ << endl;
        temp->IQ_MIN = bak1->IQ;
    }
    //masa
    temp->mass = bak1->mass + bak2->mass;
    //nalezace
    temp->NalezaceBakterie.push_back(l1);
    temp->NalezaceBakterie.push_back(l2);
    //stworzKolonie i zapisz wskazniki do niej w bakteriach
    bak1->doJakiejKoloniiNalezy = temp;
    bak2->doJakiejKoloniiNalezy = temp;
}

void dodajDoKolonii(kolonia *kol,bakteria *bak,int liczba)
{
    //iq
    if(bak->IQ > kol->IQ_MAX)
    {
        kol->IQ_MAX = bak->IQ;
    }
    else if(bak->IQ < kol->IQ_MIN)
    {
        kol->IQ_MIN = bak->IQ;
    }
    //masa
    kol->mass += bak->IQ;
    //nalezace
    kol->NalezaceBakterie.push_back(liczba);
    //wskaznik
    bak->doJakiejKoloniiNalezy = kol;
}


void dodajKolonie(kolonia *wieksza,kolonia *mniejsza){

    //iq
    if (mniejsza->IQ_MAX > wieksza->IQ_MAX)
    {
        wieksza->IQ_MAX = mniejsza->IQ_MAX;
    }
    if (mniejsza->IQ_MIN < wieksza->IQ_MIN)
    {
        wieksza->IQ_MIN = mniejsza->IQ_MIN;
    }
    //mass
    wieksza->mass += mniejsza->mass;

    //wskazniki
    for (size_t i = 0; i < mniejsza->NalezaceBakterie.size(); i++)
    {
        bakterie[mniejsza->NalezaceBakterie[i]].doJakiejKoloniiNalezy = wieksza;
    }
    
    delete mniejsza;

}

void JOIN(bakteria *bak1, bakteria *bak2,int l1, int l2){
    if(!bak1->doJakiejKoloniiNalezy && !bak2->doJakiejKoloniiNalezy)
    {
        stworzKolonie(bak1,bak2,l1,l2);
    }
    else if(!bak1->doJakiejKoloniiNalezy)
    {
        dodajDoKolonii(bak2->doJakiejKoloniiNalezy, bak1, l1);
    }
    else if (!bak2->doJakiejKoloniiNalezy)
    {
        dodajDoKolonii(bak1->doJakiejKoloniiNalezy, bak2, l2);
    }
    else
    {
        if(bak1->doJakiejKoloniiNalezy->NalezaceBakterie.size() > bak2->doJakiejKoloniiNalezy->NalezaceBakterie.size())
        {
            dodajKolonie(bak1->doJakiejKoloniiNalezy,bak2->doJakiejKoloniiNalezy);
        }
        else
        {
            dodajKolonie(bak2->doJakiejKoloniiNalezy,bak1->doJakiejKoloniiNalezy);
        }
        
    }
    
    
}

int main(){

int n;
cin >> n;

for (size_t i = 0; i < n; i++)
{
    cin >> bakterie[i].mass >> bakterie[i].IQ;
    //cout << "bakterie[i].mass: " << bakterie[i].mass << "bakterie[i].IQ: " << bakterie[i].IQ;
}

string operacja;
int input;

while(cin >> operacja >> input){
    input--;
    if(operacja == "JOIN"){
        int druga;
        cin >> druga;
        druga --;

        JOIN(&bakterie[input], &bakterie[druga], input, druga);
        
    }
    else if(operacja == "IQ_MAX")
    {
        if(bakterie[input].doJakiejKoloniiNalezy)
        {
            cout << bakterie[input].doJakiejKoloniiNalezy->IQ_MAX << endl;
        }
        else
        {
        cout << bakterie[input].IQ;
        }
    }
    else if(operacja == "IQ_MIN")
    {
        if(bakterie[input].doJakiejKoloniiNalezy)
        {
        cout << bakterie[input].doJakiejKoloniiNalezy->IQ_MIN << endl;
        }
        else
        {
        cout << bakterie[input].IQ;
        }
    }
    else if(operacja == "MASA")
    {
        if(bakterie[input].doJakiejKoloniiNalezy)
        {
        cout << bakterie[input].doJakiejKoloniiNalezy->mass << endl;
        }
        else
        {
        cout << bakterie[input].mass;
        }
    }
    

}




}