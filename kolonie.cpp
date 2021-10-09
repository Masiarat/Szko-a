#include<iostream>
#include<vector>
using namespace std;

class Bakteria {
    public:
    int IQ;
    int mass;
    int DoJakiejKoloniNalezy = -1;
};

class Kolonia {
    public:
    vector<int> NalezaceBakterie;
    int IQ_MAX;
    int IQ_MIN;
    int mass;
};

vector<int> dodajVektory(vector<int> pierwszy, vector<int> drugi){
    vector<int> v = drugi;
    for (int i = 0; i < pierwszy.size(); i++)
    {
        v.push_back(pierwszy[i]);
    }
    return v;
}

vector<Kolonia> Kolonie;
Bakteria Bakterie[1000000];

int main(){
    
    int wolny = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> Bakterie[i].mass >> Bakterie[i].IQ;
    }
    string operacja;
    int ktora;
    while (cin >> operacja >> ktora)
    {
        ktora--;
        if(operacja == "JOIN"){
            int druga;
            cin >> druga;
            druga--;
            if(Bakterie[ktora].DoJakiejKoloniNalezy == -1 && Bakterie[druga].DoJakiejKoloniNalezy == -1){
                Kolonia temp;
                if(Bakterie[ktora].IQ > Bakterie[druga].IQ){
                    temp.IQ_MAX = Bakterie[ktora].IQ;
                    temp.IQ_MIN = Bakterie[druga].IQ;
                }else{
                    temp.IQ_MIN = Bakterie[ktora].IQ;
                    temp.IQ_MAX = Bakterie[druga].IQ;
                }
                temp.mass = Bakterie[ktora].mass + Bakterie[druga].mass;
                temp.NalezaceBakterie.push_back(ktora);
                temp.NalezaceBakterie.push_back(druga);
                Bakterie[ktora].DoJakiejKoloniNalezy = wolny;
                Bakterie[druga].DoJakiejKoloniNalezy = wolny;
                Kolonie.push_back(temp);
                wolny++;
            }else if(Bakterie[ktora].DoJakiejKoloniNalezy == -1){
                if(Bakterie[ktora].IQ > Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX){
                    Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX = Bakterie[ktora].IQ;
                }else if(Bakterie[ktora].IQ < Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN){
                    Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN = Bakterie[ktora].IQ;
                }
                Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].mass += Bakterie[ktora].mass;
                Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].NalezaceBakterie.push_back(ktora);
                Bakterie[ktora].DoJakiejKoloniNalezy = Bakterie[druga].DoJakiejKoloniNalezy;
            }else if(Bakterie[druga].DoJakiejKoloniNalezy == -1){
                if(Bakterie[druga].IQ > Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX){
                    Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX = Bakterie[druga].IQ;
                }else if(Bakterie[druga].IQ < Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN){
                    Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN = Bakterie[druga].IQ;
                }
                Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].mass += Bakterie[druga].mass;
                Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie.push_back(druga);
                Bakterie[druga].DoJakiejKoloniNalezy = Bakterie[ktora].DoJakiejKoloniNalezy;
            }else if(Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie.size() > Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].NalezaceBakterie.size()){
                if(Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX > Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX){
                    Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX = Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX;
                }else{
                    Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX = Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX;
                }
                if(Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN < Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN){
                    Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN = Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN;
                }else{
                    Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN = Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN;
                }
                Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].mass += Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].mass;
                for (int i = 0; i < Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].NalezaceBakterie.size(); i++)
                {
                    Bakterie[Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].NalezaceBakterie[i]].DoJakiejKoloniNalezy = Bakterie[ktora].DoJakiejKoloniNalezy;
                }
                
                Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie = dodajVektory(Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].NalezaceBakterie, Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie);
            }else{
                if(Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX > Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX){
                    Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX = Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX;
                }else{
                    Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX = Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MAX;
                }
                if(Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN < Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN){
                    Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN = Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN;
                }else{
                    Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN = Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].IQ_MIN;
                }
                Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].mass += Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].mass;
                for (int i = 0; i < Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie.size(); i++)
                {
                    Bakterie[Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie[i]].DoJakiejKoloniNalezy = Bakterie[druga].DoJakiejKoloniNalezy;
                }
                
                Kolonie[Bakterie[druga].DoJakiejKoloniNalezy].NalezaceBakterie = dodajVektory(Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie, Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].NalezaceBakterie);
            }
        }else if(operacja == "IQ_MAX"){
            if(Bakterie[ktora].DoJakiejKoloniNalezy == -1){
                cout << Bakterie[ktora].IQ << endl;
            }else{
                cout <<  Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MAX << endl;
            }
        }else if(operacja == "IQ_MIN"){
            if(Bakterie[ktora].DoJakiejKoloniNalezy == -1){
                cout << Bakterie[ktora].IQ << endl;
            }else{
                cout <<  Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].IQ_MIN << endl;
            }
        }else if(operacja == "MASA"){
            if(Bakterie[ktora].DoJakiejKoloniNalezy == -1){
                cout << Bakterie[ktora].mass << endl;
            }else{
                cout <<  Kolonie[Bakterie[ktora].DoJakiejKoloniNalezy].mass << endl;
            }
        }
        
    }

    

}