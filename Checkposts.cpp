#include <iostream>
#include <vector>

using namespace std;

vector<int> cost;

int dfs(vector<vector<int> > &g, vector<int> &v, vector<int> &l, vector<int> &p, int n) {
    
    cout<<"!HERE"<<endl;
    cout<<"n="<<n<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<< " ";
    }
    cout<<endl;
    for (int i = 0; i < l.size(); i++) {
        cout<<l[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < p.size(); i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    
    if (v[n] == -1) {
//        cout<<"NEW"<<endl;
        v[n] = l.size();
        l.push_back(n);
    } else {
//        cout<<"VISITED"<<endl;
        cout<<"v[n] = "<<v[n]<<endl;
        int count = 1;
        int i = l.size() - 1;
        int min = l[i];
        v[l[i]] = v[n];
        l.pop_back();
        i--;
//        cout<<"v[n] = "<<v[n]<<endl;
        while (i >= v[n]) {
            /*
            cout<<"i = "<<i<<endl;
            cout<<"l = ";
            for (int j = 0; j < l.size(); j++) {
                cout<<l[j]<<" ";
            }
            cout<<endl;
            cout<<"min = "<<min<<endl;
            */
            // Made changes here...
            cout<<"v[l[i]] = "<<v[l[i]]<<endl;
            v[l[i]] = v[n];
//            cout<<"COMPARE"<<endl;
//            cout<<cost[l[i]]<<" "<<cost[min]<<endl;
            if (cost[l[i]] < cost[min]) {
                min = l[i];
                count = 1;
            } else if (cost[l[i]] == cost[min]) {
                count++;
            }
            /*
            cout<<"l = ";
            for (int j = 0; j < l.size(); j++) {
                cout<<l[j]<<" ";
            }
            */
            l.pop_back();
            i--;
        }
        l.push_back(min);
        p.push_back(count);
        /*
        cout<<"#HERE"<<endl;
        cout<<"l = ";
        for (int i = 0; i < l.size(); i++) {
            cout<<l[i]<<" ";
        }
        cout<<endl;
         */
    }
    while (g[n].size() > 0) {
//        cout<<"@HERE"<<endl;
        int next = g[n][0];
        g[n].erase(g[n].begin());
        dfs(g,v,l,p,next);
    }
    
    return 0;
}

int main() {
    
    int n, m;
    vector<vector<int> > graph;
    vector<int> visited;
    
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        cost.push_back(c);
        graph.push_back(vector<int>());
        visited.push_back(-1);
    }
    
    scanf("%d",&m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1].push_back(v-1);
    }
    
    int min_price = 0;
    int variations = 1;
    // do the first one to get an init value
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            vector<int> list;
            vector<int> p;
            dfs(graph, visited, list, p, i);
            cout<<"!!!!!!"<<endl;
            for (int j = 0; j < list.size(); j++) {
//                cout<<list[j]<<endl;
                min_price += cost[list[j]];
//                cout<<min_price<<endl;
            }
            for (int j = 0; j < p.size(); j++) {
                variations *= p[j];
            }
        }
    }
    
    cout<<min_price<<" "<<variations<<endl;
    
    return 0;
}