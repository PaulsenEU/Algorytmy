#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    ifstream we;
    ofstream wy;
    we.open("In0204.txt");
    wy.open("Out0204.txt");

    we >> a >> b;
    if(a <= 0 || b <= 0) {
        wy << "Podaj prawidlowe liczby";
        return -1;
    } 
    wy << gcd(a, b);
}