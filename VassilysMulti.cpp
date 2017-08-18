#include <iostream>
#include <string>
#include <vector>

using namespace std;

int BinSearch(vector<int> * AIn, int n);

int main() {
    
    int q;
    vector<int> A;
    
    cin>>q;
    
    // Init A
    A.push_back(0);
    
    for (int i = 0; i < q; i++) {
        string op;
        int v;
        cin>>op;
        cin>>v;
        
        if (op == "+") {
            int j = 0;
            while (A[j] < v && j < A.size()) {
                j++;
            }
            A.insert(A.begin()+j, v);
        } else if (op == "-") {
            
        }
//        cout<<op<<endl;
    }
    
    for (int i = 0; i < A.size(); i++) {
        cout<<A[i]<<endl;
    }
    
    return 0;
}

int BinSearch(vector<int> & AIn, int n) {
    
    int start = 0;
    int end = AIn.size();
//    int mid = AIn.size()/2;
    int mid;
    
    while (start <= end) {
        mid = (start + end)/2;
        
        if (n > AIn[mid]) {
            start = mid;
            end = AIn.size() - 1;
        } else {
            start = 0;
            end = mid - 1;
        }
    }
    
    return mid;
}