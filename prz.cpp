#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int n,m,maks,ostatniMaks;
int arr[1000000];
unordered_set<int> zmienione;


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
            zmienione.clear();
            ostatniMaks = maks;

        }else{
            if(zmienione.find(input) == zmienione.end()){
                zmienione.insert(input);
                arr[input] = ostatniMaks + 1;
            }else{
                arr[input]++;
            }
            
            if(arr[input] > maks){
                maks = arr[input];
            }

        }

    }

    for (int i = 0; i < n; i++)
    {
        if(zmienione.find(i) != zmienione.end()){
            cout << arr[i] << " ";
        }else{
            cout << ostatniMaks << " ";
        }
    }
    
    

    
}