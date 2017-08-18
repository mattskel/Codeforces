#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {
    string n;
    cin>>n;
    
    
    int asciiZero = 48;
    int count = 0;
    
    while (n.length() > 1) {
//        cout<<n<<endl;
        count++;
        int sum = 0;
//        cout<<"SUMLOOP"<<endl;
        for (int i = 0; i < n.length(); i++) {
//            cout<<sum<<endl;
            sum += (int)n[i] - asciiZero;
        }
//        cout<<"END"<<endl;
        ostringstream ss;
        ss << sum;
    
        n = ss.str();
    }
    cout<<count<<endl;
    return 0;
}