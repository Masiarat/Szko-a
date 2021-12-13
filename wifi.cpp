#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>
using namespace std;


    
bool sprawdz(vector<double> klasy,double lokalizacja, double zasieg,double l){
    // cout << "klasy: " << klasy[0] << ", " << klasy[1] << ", " << klasy[2] << endl;
    // cout << "lokalizacja: " << lokalizacja << endl;
    // cout << "zasieg: " << zasieg << endl;
    // cout << "l" << l << endl;
    int j = 0;
    while(j < klasy.size()){
        if(klasy[j] > lokalizacja + zasieg){
            if(l > 0){
                lokalizacja = klasy[j] + zasieg;
                l--;
            }else{
                return false;
            }
            
        }
    j++;
    }
    return true;
}   


int n,m;
int k;
vector<double> klasy;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    for (int j = 0; j < k; j++)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            double temp;
            cin >> temp;
            // temp = temp;
            klasy.push_back(temp);
        }
        double ostatniaKlasa = klasy[klasy.size() - 1];
        //cout << "ostatnia: " << ostatniaKlasa << endl;
        double poprzednizasieg = 0.0;
        double zasieg = (ostatniaKlasa - (klasy[0])) / 2;
        //int zasieg = 5;
        double l = klasy[0];
        double r = ostatniaKlasa;
        while(abs(poprzednizasieg - zasieg) > 0.01){
            if(sprawdz(klasy,klasy[0] + zasieg,zasieg,n - 1)){
                poprzednizasieg = zasieg;
                //cout << "dziele: " << zasieg << endl;
                r = zasieg;
                zasieg = zasieg/2;
            }else{
                poprzednizasieg = zasieg;
                //cout << "mnoze: " << zasieg << endl;
                zasieg = zasieg + (r - zasieg)/2;
            }
        }
        printf("%.1f \n", zasieg);
        // double wynik = static_cast<double>(round(zasieg * 10)) / 10;
        // cout << wynik;
        klasy.clear();


    }
    
    
    

}