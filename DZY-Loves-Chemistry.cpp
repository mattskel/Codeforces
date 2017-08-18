#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



bool myCompare(pair<int,int> first, pair<int,int> second) {
    return first.second > second.second;
}

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    vector<vector<int> > graph;
    vector<pair<int,int> > count;
    int visited[n];
    
    for (int i = 0; i < n; i++) {
        graph.push_back(vector<int>());
        pair<int,int> tmpPair;
        tmpPair.first = i;
        tmpPair.second = 0;
        count.push_back(tmpPair);
        visited[i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
        count[x-1].second++;
        count[y-1].second++;
    }
    
    sort(count.begin(),count.end(),myCompare);
    
    long long explosive = 1;
    
    while(count.size() > 0) {
        
        int node;
        int i = 0;
        while (i < count.size() && visited[count[i].first] != 2) {
            i++;
        }
        if (i >= count.size()) {
            i = 0;
        }
        node = count[i].first;
        
        count.erase(count.begin() + i);
        
        explosive *= visited[node];
//        cout<<"NODE="<<node<<endl;
        for (int i = 0; i < graph[node].size(); i++) {
            visited[graph[node][i]] = 2;
//            cout<<"CHILD="<<graph[node][i]<<endl;
        }
    }
    
    cout<<explosive<<endl;
    
    return 0;
}