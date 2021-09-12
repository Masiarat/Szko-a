#include <iostream>
#include <vector>

using namespace std;

int iloscOperacji;
int baza;
int size = 101;
int n, nom, ilosc;
vector<int> v(size, 0);
//vector<int> vr(size,0);
//vector<int> vl(size,0);

int search(int nomMin, int b, int l, int p, int node)
{

    int x = 0, y = 0;
    int mid = (l + p) / 2;

    if (nomMin <= l && p <= b)
    {
        return v[node];
    }

    if (nomMin <= mid)
    {
        x = search(nomMin, b, l, mid, 2 * node);
    }
    if (b > mid)
    {
        y = search(nomMin, b, mid + 1, p, 2 * node + 1);
    }

    return x + y;
}

// void build(int currV, int l, int r)
// {

//     //vl[currV] = l;
//     //vr[currV] = r;
//     //cout << "dupa" << currV;
//     if (l == r)
//     {
//         return;
//     }

//     int mid = (l + r) / 2;

//     build(currV * 2, l, mid);
//     build(currV * 2 + 1, mid + 1, r);

//     return;
// }

bool update()
{

    int i = 0;
    char temp;
    cin >> temp;
    cin >> nom;
    cin >> ilosc;
    switch (temp)
    {
    case '+':
        i = nom + baza;
        while (i > 1)
        {
            v[i] += ilosc;
            //cout << "dupa" << v[i];
            i = i / 2;
        }
        return true;
    case '-':
        i = nom + baza;
        while (i > 1)
        {
            v[i] -= ilosc;
            i = i / 2;
        }
        return true;
    case '#':
        cout << search(nom, ilosc, 1, baza, 1);
        return true;
    case 'x':
        return false;
    }
    

    
    return true;
}

int main()
{

    bool bool1;
    cin >> n;
    baza = n - 1;
    v[1] = 1;
    //vl[1] = 1;
    //vr[1] = n;
    //build(v[1], 1, n);
    //cin >> iloscOperacji;
    string sprawdzanie;
    
    while(update()){}

    //for (int i = 0; i < iloscOperacji; i++)
    //{
    //    update();
    //cout << v[2];
    //}
}