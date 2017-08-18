#include <iostream>

using namespace std;

int main() {
    
    string inputString;
    int n;
    int jumpSize;
    int jumps;
    bool good = false;
    
    cin>>n;
    cin>>inputString;
    
    int i = 0;
    while (i < n && !good) {
        if (inputString[i] == '*') {
            jumpSize = 1;
            while (i + jumpSize * 4 < n && !good) {
                if (inputString[i + jumpSize] == '*' &&
                    inputString[i + 2 * jumpSize] == '*' &&
                    inputString[i + 3 * jumpSize] == '*' &&
                    inputString[i + 4 * jumpSize] == '*') {
                    good = true;
                }
                jumpSize++;
            }
            
        }
        i++;
    }
    
    if (good) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    
    return 0;
}