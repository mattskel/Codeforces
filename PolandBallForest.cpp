/*
 * PolandBall and Forest
 */

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int DFS(vector<vector<int> > &forrestIn, int index);

int main () {
    int n, treeCount;
    string line;
    
    cin>>n;
    cin.ignore(256, '\n');
    
    // Create an array of vectors
    vector<vector<int> > forrest(n);
    
    int v;
    getline(cin,line);
    istringstream is(line);
    
    int i = 1;
    
    while (is>>v) {
        if (find(forrest[i-1].begin(), forrest[i-1].end(), v) == forrest[i-1].end()) {
            forrest[i-1].push_back(v);
            if (v != i) {
                forrest[v-1].push_back(i);
            }
        }
        i++;
    }
    
//    for  (int i = 0; i < n; i++) {
//        
//        for (int j = 0; j < forrest[i].size(); j++) {
//            cout<<forrest[i][j];
//        }
//        cout<<"\n";
//    }
    
    int treeTotal = 0;
    
    for (int i = 0; i < n; i++) {
        if (forrest[i][0] != -1) {
            treeTotal++;
            DFS(forrest, i);
        }
    }
    
    cout<<treeTotal<<endl;
    
    return 0;
}

int DFS(vector<vector<int> > &forrestIn, int index) {
    
    if (forrestIn[index][0] != -1) {
        vector<int> edges = forrestIn[index];
        forrestIn[index].clear();
        forrestIn[index].push_back(-1);
        for (int i = 0; i < edges.size(); i++) {
            DFS(forrestIn, edges[i] - 1);
        }
    }
    
    return 0;
}