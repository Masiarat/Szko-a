#include<iostream>
#include<vector>
using namespace std;

int n,m,maks;
int arr[10000];
vector<int> zmieniony;

bool czyJestTakiZmieniony(int input){
    for (int i = 0; i < zmieniony.size(); i++)
    {
        if(zmieniony[i] == input){
            return true;
        }
    }
    return false;
}

int main(){

cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;

        if(input == n + 1){
            //specjalny
            
        }else{
            //dodaj
            arr[input - 1]++;
            //jezeli jeszcze nie zanotowales, zanotuj ze zmieniony
            if(!czyJestTakiZmieniony(input)){
                zmieniony.push_back(input - 1);
            }
        }

    }
    

    
}