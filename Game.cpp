#include <iostream>
#include <string>

using namespace std;

int main () {
    
    int n1, n2, k1, k2;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    
    //whoever has the most will win becuase we can just take away one at a time
    
    if (n1 > n2) {
        cout<<"First"<<endl;
    }
    else if (n2 > n1) {
        cout<<"Second"<<endl;
    }
    else if (n1 == n2) {
        cout<<"Second"<<endl;
    }
    
    return 0;
    
}