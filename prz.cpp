#include<iostream>
#include<vector>
using namespace std;

int n,m,maks,ostatniMaks;
int arr[10000];
vector<int> zmieniony;

bool czyJestTakiZmieniony(int input){
    for (int i = 0; i < zmieniony.size(); i++)
    {
        //cout << "dupa " << input << endl;
        if(zmieniony[i] == input){
            return true;
        }
    }
    return false;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        input--;

        if(input == n){
            for (int a = 0; a < zmieniony.size(); a++)
            {
                arr[zmieniony[a]] = 0;
            }
            zmieniony.clear();
            ostatniMaks = maks;
        }else{
            //dodaj
            arr[input]++;
            //jezeli jeszcze nie zanotowales, zanotuj ze zmieniony
            if(!czyJestTakiZmieniony(input)){
                //cout << "dupa2 " << input << endl;
                zmieniony.push_back(input);
            }
            if(arr[input] + ostatniMaks > maks){
                maks = arr[input] + ostatniMaks;
            }

        }

    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            cout << ostatniMaks << " ";
        }else{
            cout << ostatniMaks + arr[i] << " ";
        }
    }
    
    

    
}