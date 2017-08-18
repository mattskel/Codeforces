#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main () {
    
//    cout<<"#HERE"<<endl;
//    
//    vector<vector<*int> > myVector;
//    vector<*int> tmpVector;
//    
//    for (int i = 0; i < 5; i++) {
//        
//        cout<<"%HERE"<<endl;
//        
//        for (int j = 0; j < i + 1; j++) {
//            cout<<i<<endl;
//            tmpVector.push_back(i);
//        }
//        
//        cout<<"!HERE"<<endl;
//        
//        for (int j = 0; j < i + 1; j++) {
//            cout<<*tmpVector[j]<<endl;
//        }
//        
//        myVector.push_back(tmpVector);
//    }
//    
//    cout<<"***"<<endl;
//    
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < i + 1; j++) {
//            cout<<*myVector[i][j]<<endl;
//        }
//    }
    
    
    vector<vector<int> > stuff;
    string line;
    
    int n, m, q, tmp;
    vector<vector<int> > V;
    vector<int> vec;
    
    int M[100][100];
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            M[i][j] = 1;
        }
    }
    
    cin>>n>>m>>q;
    
    for (int i = 0; i < q; i++) {
        int n;
        vector<int> tmp;
        getline(cin,line);
        
        istringstream is(line);
        
        while (is>>n) {
            tmp.push_back(n);
        }
        
        stuff.push_back(tmp);
    }
    
    
    for (int i = 0; i < q; i++) {
        
        for (int j = 0; j < stuff[i].size(); j++) {
            cout<<stuff[i][j]<<endl;
        }
    }
    
    return 0;
}