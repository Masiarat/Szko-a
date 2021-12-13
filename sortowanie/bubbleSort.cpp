#include<iostream>
#include<vector>
using namespace std;



int main(){

int n;
// cout << "abc";
cin >> n;
// cout << "n= " << n;
vector<int> v(n,0);
for(size_t i = 0; i < n; i++)
{
    cin >> v[i];
}

int count = n - 1;
bool zmiana = true;

for(size_t i = 0; i < n && zmiana; i++)
{
    zmiana = false;
    for (size_t j = 0; j < count; j++)
    {
        if(v[j] > v[j + 1]){
            swap(v[j],v[j + 1]);
            zmiana = true;
        }
    }
    count--;
    
}

cout << "arr: ";

for(size_t i = 0; i < n; i++)
{
    cout << v[i] << ", ";
}
cout << endl;

}