#include<iostream>
using namespace std;

int a,b;

int main(){

    cin >> a >> b;

    if(a == 0 && b == 0){
        cout << "NIE";
    }
    else if(a == 1 && b == 1){
        cout << "1+1=2";
    }
    else if(a == 1 && b == 2){
        cout << "1+2=3";
    }
    else if(a == 2 && b == 1){
        cout << "2+1=3";
    }
    else if(a == 2 && b == 2){
        cout << "NIE";
    }
    else if(a < 0 && b == 1){
        if(a + b > 0){
            cout << "(" << a << ")" << "+" << b << "=" << a + b;
        }else{
            cout << "(" << a << ")" << "+" << b << "=" << "(" << a + b << ")";
        }  
    }
    else if(a > 0 && b == 1){
        cout << a << "+" << b << "=" << a + b;
    }
    else if(a < 0 && b < 0){
        cout << "(" << a << ")" << "*" << "(" << b << ")" << "=" << a*b;
    }
    else if(a > 0 && b < 0){
        cout << a << "-" << "(" << b << ")" << "=" << a-b;
    }
    else if(a < 0 && b > 0){
        if(a+b > 0){
            cout << "(" << a << ")" << "+" << b << "=" << a+b;
        }else{
            cout << "(" << a << ")" << "+" << b << "=" << "(" << a+b << ")";
        }
    }
    else if(a > 0 && b > 0){
        cout << a << "*" << b << "=" << a*b;
    }
    else if(a == 0 && b > 0){
        cout << a << "+" << b << "=" << a+b;
    }
    else if(a == 0 && b < 0){
        cout << a << "-" << b << "=" << a-b;
    }
    else if(b == 0){
        cout << "NIE";
    }


}