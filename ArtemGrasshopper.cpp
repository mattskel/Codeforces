#include <iostream>

using namespace std;

int main () {
    
    int n;
    int pos;
    int shift;
    string cells;
    int dist[100000];
    bool visited[100000] = {false};
    
    cin>>n;
    
    cin>>cells;
    
    for (int i = 0; i < n; i++) {
        cin>>dist[i];
    }
    
    pos = 0;
    
    while (pos > -1 && pos < n && visited[pos] == false) {
        shift = dist[pos];
        visited[pos] = true;
        if (cells[pos] == '>') {
            pos = pos + shift;
        }
        else {
            pos = pos - shift;
        }
    }
    
    if (pos <= -1 || pos >= n) {
        cout<<"FINITE"<<endl;
        
    }
    else {
        cout<<"INFINITE"<<endl;
    }
    
    return 0;
}