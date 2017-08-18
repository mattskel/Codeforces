#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    int array[m];
    
    int lights[n];
    fill_n(lights,n,-1);
    
    for (int i = 0; i < m; i++) {
        cin>>array[i];
    }
    
    for (int i = 0; i < m; i++) {
        
        int button = array[i];
        int j = button - 1;
        
        while (j < n && lights[j] == -1) {
            lights[j] = button;
            j++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout<<lights[i]<<" ";
    }
    
    return 0;
}