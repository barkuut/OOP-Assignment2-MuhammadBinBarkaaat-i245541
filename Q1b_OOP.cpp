#include <iostream>
using namespace std;

void PrintPattern(int &n) {
   
    if (n == 1) {
        cout << "1 1 1 1" << endl;
        return;
    }

   
    if (n == 4)
        cout << "2 2" << endl;
    else if (n == 3)
        cout << "1 3" << endl;
    else if (n == 2)
        cout << "1 1 2" << endl;

    int next = n - 1;    
    PrintPattern(next);   
}

int main() {
    int n;
    cout << "Enter any number = ";
    cin >> n;

    cout << n << endl;  
    PrintPattern(n);   
    return 0;
}


