#include <iostream>
#include <vector>
#include <map>

using namespace std;

int Test(int *array, int target, int n) {
    int start = 0;
    int finish = 1;
    
    while (finish < n && array[finish] - array[start] != target) {
        if (array[finish] - array[start] < target) {
            finish++;
        } else {
            start++;
        }
    }
    
    if (array[finish] - array[start] == target) {
        return array[finish];
    } else {
        return 0;
    }
}

int main () {
    
    int l, n, x, y;
    bool p=false, q=false;
    scanf("%d %d %d %d", &n, &l, &x, &y);
    int array[n];
    map<int,int> map;
    
    for (int i = 0; i <= n; i++) {
        int v;
        cin>>v;
//        cin>>array[i];
        array[i] = v;
        map[v] = 1;
        if (map.count(v-x)) {
            p = true;
        }
        if (map.count(v-y)) {
            q = true;
        }
    }
    
    vector<int> output;
    
    if (!p && !q) {
//        cout<<"!HERE"<<endl;
//        cout<<n<<endl;
        int j;
        for (int i = 0; i <= n; i++) {
            j = i;
            int v;
            if (array[i] - x >= 0) {
                v = array[i]-x;
                if(map.count(v-y)) {
                    output.push_back(v);
//                    cout<<"@HERE"<<endl;
                    break;
                }
                if (map.count(v+y)) {
                    output.push_back(v);
//                    cout<<"#HERE"<<endl;
                    break;
                }
            }
            if (array[i]+x <= l) {
                v=array[i]+x;
                if(map.count(v-y)) {
                    output.push_back(v);
//                    cout<<"$HERE"<<endl;
                    break;
                }
                if (map.count(v+y)) {
                    output.push_back(v);
//                    cout<<"%HERE"<<endl;
                    break;
                }
            }
        }
//        cout<<j<<endl;
        if (j>=n) {
            output.push_back(x);
            output.push_back(y);
        }
    } else if (!p) {
        output.push_back(x);
    } else if (!q) {
        output.push_back(y);
    }
    
    cout<<output.size()<<endl;
    
    for (int i = 0; i < output.size(); i++) {
        cout<<output[i]<< " ";
    }
    
    cout<<endl;
    
    return 0;
}