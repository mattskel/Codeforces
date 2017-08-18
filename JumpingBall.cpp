#include <iostream>

using namespace std;

int main () {
    
    string inputString;
    int n;
    int total = 0;
    
    // Get the user input
    cin>>n;
    cin>>inputString;
    
    int i = 0;
    while (i < n && inputString[i] == '<') {
        total++;
        i++;
    }
    
    int j = n-1;
    while (j >= 0 && inputString[j] == '>') {
        total++;
        j--;
    }
    
    cout<<total<<endl;
    
    return 0;
}