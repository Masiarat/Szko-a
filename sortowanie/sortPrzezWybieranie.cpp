#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n,0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    

    for (size_t i = n - 1; i > 0; i--)
    {
        int *max = &v[i];
        for (size_t j = 0; j < i; j++)
        {
            if(v[j] > *max) max = &v[j];
        }
        swap(*max,v[i]);
        
    }

    cout << "arr: ";

    for (size_t i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    
    cout << endl;
    





}