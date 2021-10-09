#include<iostream>
#include<vector>
using namespace std;

class Bakteria {
    public:
    int IQ;
    int mass;
    int DoJakiejKoloniNalezy;
};

class Kolonia {
    public:
    vector<int> NalezaceBakterie;
    int IQ_MAX;
    int IQ_MIN;
    int mass;
};


vector<Kolonia> Kolonie;
Bakteria Bakterie[1000000];

int main(){
    
}