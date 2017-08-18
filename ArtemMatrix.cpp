#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main () {
    
    
    int n, m, q, tmp, r, c, x;
    string line;
    vector<vector<int> > V;
    vector<int> vec;
    
    int M[100][100];
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            M[i][j] = 0;
        }
    }
    
    cin>>n>>m>>q;
    cin.ignore(256, '\n');
    
    for (int i = 0; i < q; i++) {
        int v;
        vector<int> tmp;
        getline(cin,line);
        
        istringstream is(line);
        
        while (is>>v) {
            tmp.push_back(v);
        }
        
        V.push_back(tmp);
    }
    
    for (int i = q - 1; i >= 0; i--) {
        int t;
        t = V[i][0];
        
        if (t == 1) {
            int r;
            r = V[i][1];
            
            int tmp1, tmp2;
            tmp1 = M[r - 1][0];
            
            for (int j = 1; j < m + 1; j++) {
                tmp2 = M[r - 1][(j)%m];
                M[r - 1][(j)%m] = tmp1;
                tmp1 = tmp2;
            }
        }
        else if (t == 2) {
            int c;
            c = V[i][1];
            
            int tmp1, tmp2;
            tmp1 = M[0][c - 1];
            
            for (int j = 0; j < n + 1; j++) {
                tmp2 = M[(j)%n][c - 1];
                M[(j)%n][c - 1] = tmp1;
                tmp1 = tmp2;
            }
            
        }
        else if (t == 3) {
//            int r, c, x;
            
            r = V[i][1];
            c = V[i][2];
            x = V[i][3];
            
            M[r-1][c-1] = x;
            
        }
        
        // I am printing the values for my Matrix here.
        // It is only returning the initial values i put into the matrix. Why?
        // just above i changed and printed out the new values for the matrix
        // Remember that the rows and columns are starting at 1 and not 0
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<M[i][j];
            if (j != m-1) {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    
    return 0;
}


