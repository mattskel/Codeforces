#include <iostream>

using namespace std;

int main () {
    
    int n;
    
    cin>>n;
    
    if (n == 1) {
        cout<<1<<endl;
    }
    else if (n == 2) {
        cout<<1<<endl;
    }
    else if (n % 3 == 0) {
        cout<<(n/3) * 2<<endl;
    }
    else if (n % 3 == 1) {
        cout<<((n - 1)/3) * 2 + 1<<endl;
    }
    else if (n % 3 == 2) {
        cout<<((n - 2)/3)*2 + 1<<endl;
    }
    
    return 0;
}