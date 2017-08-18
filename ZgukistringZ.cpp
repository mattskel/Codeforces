
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    string a, b, c;
    // Initialise the counts to 0
    vector<int> aCount(26,0);
    vector<int> bCount(26,0);
    vector<int> cCount(26,0);
    
    vector<int> aTmp;
    
    vector<int> kCount(26,0);
    
    bool cond = true;
    
    int total, bTotal, cTotal;
    int bMax, cMax;
    
    cin>>a;
    cin>>b;
    cin>>c;
    
    for (int i = 0; i < a.size(); i++)
        aCount[a[i] - 'a']++;
    
    for (int i = 0; i < b.size(); i++)
        bCount[b[i] - 'a']++;
    
    for (int i = 0; i < c.size(); i++)
        cCount[c[i] - 'a']++;
    
    // Determine the number of times b can be represented
    int bMult = 100000 + 1;
    int cMult = 100000 + 1;
    for (int i = 0; i < 26; i++) {
        if (bCount[i] != 0) {
            bMult = min(bMult,aCount[i]/bCount[i]);
        }
//        if (cCount[i] != 0) {
//            cMult = min(cMult,(aCount[i] - bMult * bCount[i])/cCount[i]);
//        }
//        cout<<aCount[i]<<" "<<bCount[i]<<" "<<cCount[i]<<endl;
//        cout<<bMult<<" "<<cMult<<endl;
    }
    
    for (int i = 0; i < 26; i++) {
        if (cCount[i] != 0) {
            cMult = min(cMult,(aCount[i] - bMult * bCount[i])/cCount[i]);
        }
    }
    
//    cout<<bMult<<endl;
//    cout<<cMult<<endl;
    
    for (int i = 0; i < 26; i++) {
        aCount[i] -= bMult * bCount[i];
        aCount[i] -= cMult * cCount[i];
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < aCount[i]; j++) {
            //            cout<<itoa(i);
//            cout<<static_cast<char>('a' + i)<<endl;
        }
    }
    
    bMax = bMult;
    cMax = cMult;
    total = bMult + cMult;
    
    aTmp = aCount;
    
    do {
        if (bMult + cMult > total) {
            bMax = bMult;
            cMax = cMult;
            total = bMult + cMult;
            aCount = aTmp;
        }
        
        int cTmp = 10000 + 1;
        bMult -= 1;
        for (int i = 0; i < 26; i++) {
            if (bCount[i] != 0) {
                aTmp[i] += bCount[i];
            }
            if (cCount[i] != 0) {
                cTmp = min(cTmp,aTmp[i]/cCount[i]);
            }
        }
        cMult += cTmp;
        for (int i = 0; i < 26; i++) {
            aTmp[i] -= cTmp * cCount[i];
        }
        
    } while (bMult > 0);
    
    // FINAL CHECK
    if (bMult + cMult > total) {
        bMax = bMult;
        cMax = cMult;
        total = bMult + cMult;
        aCount = aTmp;
    }
    
    // PRINTING
    for (int i = 0; i < bMax; i++) {
        cout<<b;
    }
    for (int i = 0; i < cMax; i++) {
        cout<<c;
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < aCount[i]; j++) {
            //            cout<<itoa(i);
            cout<<static_cast<char>('a' + i);
        }
    }
    
    /*
    do {
        aCount = aTmp;
        bMult = bMax;
        cMult = cMax;
        total = bMult + cMult;
        if (bMax > 0) {
            int cTmp = 10000 + 1;
            bMax -= 1;
            for (int i = 0; i < 26; i++) {
                if (bCount[i] != 0) {
                    aTmp[i] += bCount[i];
                }
                if (cCount[i] != 0) {
                    cTmp = min(cTmp, aTmp[i]/cCount[i]);
                }
            }
            cMax += cTmp;
            for (int i = 0; i < 26; i++) {
                aTmp[i] -= cTmp * cCount[i];
            }
        }
    } while (bMax + cMax > total);
    
    
    // Print out the string
    for (int i = 0; i < bMult; i++) {
        cout<<b;
    }
    for (int i = 0; i < cMult; i++) {
        cout<<c;
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < aCount[i]; j++) {
//            cout<<itoa(i);
            cout<<static_cast<char>('a' + i);
        }
    }
     */
    
    return 0;
}