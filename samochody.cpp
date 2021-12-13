#include<iostream>
using namespace std;


long long n;
long long liczba;
long long wPrawo;
long long wynik;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> liczba;
        if(liczba == 0){
            wPrawo++;
        }else{
            wynik += wPrawo;
        }
        
    }
    cout << wynik;
}