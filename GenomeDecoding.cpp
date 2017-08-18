/*
 * Mammoth's Genome Decoding
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool mySort(pair<int,char> i, pair<int,char> j);

int main () {
    int n;
//    int count [5] = {0,0,0,0,0};
    int max, index, blanks;
//    pair <int, char> count [4];
    vector<pair <int, char> > count;
    
    string s;
    
    cin>>n;
    cin>>s;
    
    // Init the pair array
    count.push_back(make_pair(0,'A'));
    count.push_back(make_pair(0,'C'));
    count.push_back(make_pair(0,'G'));
    count.push_back(make_pair(0,'T'));
    blanks = 0;
    
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'A':
                count[0].first++;
                break;
            case 'C':
                count[1].first++;
                break;
            case 'G':
                count[2].first++;
                index = 2;
                break;
            case 'T':
                count[3].first++;
                break;
            case '?':
                blanks++;
                break;
            default:
                break;
        }
    }
    
    sort(count.begin(), count.end(), mySort);
    
    max = count[0].first;
    index = 1;
    
    int i = 0;
    while (i < n && index < 4) {
        if (count[index].first == max) {
            index++;
        } else if (s[i] != '?') {
            i++;
        } else {
            s[i] = count[index].second;
            count[index].first++;
            i++;
        }
    }
    
    index = 0;
    while (i < n) {
        if (s[i] != '?') {
            i++;
        } else {
            s[i] = count[index%4].second;
            index++;
            i++;
        }
    }
    
    if (count[3].first == max && index%4 == 0) {
        cout<<s<<endl;
    } else {
        cout<<"==="<<endl;
    }
    
    
    
    return 0;
}

bool mySort(pair<int,char> i, pair<int,char> j) {return (i.first > j.first);}