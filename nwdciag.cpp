#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
int zakresLiczb = 1000;
int liczba;

vector<int> liczbyPierwsze;


void obliczLiczbyPierwsze(int a){

    int poprawka;
    bool *tablica=new bool[a+1];
	
	for(int i = 0; i <= a; i++){
        tablica[i] = true;
    } 
	
	for(int i = 2; i <= sqrt(a); i++)
	{
		if(tablica[i] == true){
			for(int j = i * i; j <= a; j += i){
                tablica[j] = false;
            } 
        }
	}
	
	for(int i = 2; i <= a; i++)
	{
		if(tablica[i] == true) liczbyPierwsze.push_back(i);
	}
    
    delete [] tablica;
    
}

int znajdzNajwieksza(vector<int> liczby){
    int najw;
    najw = liczby[0];
    if(liczby.size() > 1){
        for (int i = 1; i < liczby.size(); i++)
        {
            if(najw < liczby[i]){
                najw = liczby[i];
            }
        }
    }
    return najw;
    
}

bool czyMajaWspolna(vector<int> liczby){

    int j = 0;
    int count = 0;
    //if(liczby.size() > 1){ 
        //cout << liczby.size();
        for(int i = 0;liczbyPierwsze[i] <= znajdzNajwieksza(liczby); i++){
            while(j < liczby.size()){
                cout << " " << liczbyPierwsze[i];
                if(liczby[j] % liczbyPierwsze[i] == 0){
                    count++;
                }else{
                    break;
                }
                j++;
            }
            j = 0;
            if(count == liczby.size()){
                return true;
            }
            count = 0;
        }
    return false;
    
}

int main(){

    vector<int> liczby;
    int temp;
    int temp2;
    int obecna;
    int najwieksza = 0;
    cin >> n;
    obliczLiczbyPierwsze(zakresLiczb);
    
    if(n > 2){
        cin >> temp;
        cin >> temp2;
        liczby.push_back(temp);
        liczby.push_back(temp2);
        int ostatnia = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if(czyMajaWspolna(liczby)){
                cout << "wszed";
                if(liczby.size() > najwieksza){
                    najwieksza = liczby.size();
                }
            }else{
                cout << "niewszed";
                ostatnia = liczby[liczby.size() - 1];
                liczby.clear();
                liczby.push_back(ostatnia);
            }
            cin >> obecna;
            liczby.push_back(obecna);
            
        }
        if(czyMajaWspolna(liczby)){
            if(liczby.size() > najwieksza){
                najwieksza = liczby.size();
            }
        }
        
        cout << "Najwiekszy ciag ma: " << najwieksza << endl;
    
    }
}