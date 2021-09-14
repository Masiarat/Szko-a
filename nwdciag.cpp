#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
int zakresLiczb = 100000;
vector<int> ciagi[100000];
int liczba;
vector<int> liczbyPierwsze;

void obliczLiczbyPierwsze(int a){

    int usunieteIndeksy = 0;

	for(int i = 0; i <= a ; i++){
        liczbyPierwsze.push_back(i);
    }
	
	
	for(int i = 2; i <= sqrt(a); i++){
		for(int j = 1;j <= a/i; j++){
            
        }
	}
    // for(int i=2; i<=sqrt(a); i++)
	// {
	// 	for(int j = i * i; j <= a; j += i){
    //         liczbyPierwsze.erase(liczbyPierwsze.begin() + i - usunieteIndeksy);
    //         usunieteIndeksy++;
    //     } 
	// }

    for (int i = 0; i < liczbyPierwsze.size(); i++){
        cout << liczbyPierwsze[i];
    }   
    

}

void rozkladNaCzynnikiPierwsze(int liczbaRozk, int temp1){
    
}

int main(){

    cin >> n;
    obliczLiczbyPierwsze(zakresLiczb);
    
    // for (int i = 0; i < n; i++){
    // }
    

}