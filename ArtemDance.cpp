#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main () {
    
    int n, q;
    string line;
    
    cin>>n>>q;
    cin.ignore(256, '\n');
    
    vector<int> myArr;
    
    for (int i = 1; i <= n; i++) {
        myArr.push_back(i);
    }
    
    for (int i = 0; i < q; i++) {
        int v;
        vector<int> inVector;
        
        getline(cin,line);
        istringstream is(line);
        while (is>>v) {
            inVector.push_back(v);
        }
        
        if (inVector[0] == 1) {
            vector<int> tmpVector(n);
            for (int j = 0; j < n; j++) {
                if ((j + inVector[1]) < 0) {
                    tmpVector[n + j + inVector[1]] = myArr[j];
                }
                else {
                    tmpVector[(j + inVector[1]) % n] = myArr[j];
                }
            }
            
            myArr = tmpVector;
        }
        else if (inVector[0] == 2) {
            for (int j = 0; j < n/2; j++) {
                int tmp;
                tmp = myArr[2*j];
                myArr[2*j] = myArr[2*j + 1];
                myArr[2*j + 1] = tmp;
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        cout<<myArr[i]<<" ";
    }
    cout<<myArr[n - 1]<<endl;
    
    return 0;
    
}