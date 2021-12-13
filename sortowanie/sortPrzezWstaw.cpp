#include<iostream>
#include<vector>
using namespace std;

int binSearch(vector<int> v,int l,int r,int liczba){
    

    if(l >= r){
        return l;
    }

    int mid;
    mid = (l + r) / 2;

    if(liczba >= v[mid]){
        return binSearch(v,mid + 1,r,liczba);
    }else{
        return binSearch(v,l,mid,liczba);
    }

}


int main(){
    
int n;
cin >> n;
vector<int> v(n,0);

for (size_t i = 0; i < n; i++)
{
    cin >> v[i];
}

int liczba;
int pozycja;

for (size_t i = 1; i < n; i++)
{
    liczba = v[i];
    pozycja = binSearch(v,0,i,liczba);
    for (size_t j = i; j > pozycja; j--)
    {
        v[j] = v[j - 1];
    }
    v[pozycja] = liczba;
    
}

cout << "arr: ";

for (size_t i = 0; i < v.size(); i++)
{
    cout << v[i] << ", ";
}

cout << endl;


}