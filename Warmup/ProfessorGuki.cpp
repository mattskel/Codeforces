#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    
    int x1, y1, x2, y2, xDist, yDist;
    
    cin>>x1>>y1;
    cin>>x2>>y2;
    
    if (x1 > x2) {
        xDist = x1 - x2;
    }
    else {
        xDist = x2 - x1;
    }
    
    if (y1 > y2) {
        yDist = y1 - y2;
    }
    else {
        yDist = y2 - y1;
    }
    
    if (xDist > yDist) {
        cout<<xDist<<endl;
    }
    else {
        cout<<yDist<<endl;
    }
    
    return 0;
}