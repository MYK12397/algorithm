#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MAXN = 51;
bool seen[MAXN][1025];
typedef pair<int, int> pii;

class XorTravelingSalesman {
public:
    int maxProfit(vector <int> cityValues, vector <string> roads) {
        memset(seen, 0, sizeof(seen));

        int N = cityValues.size();
        seen[0][cityValues[0]] = 1;
        queue< pii > Q;

        Q.push( pii(0, cityValues[0]));
        int ans = cityValues[0];
        while(!Q.empty()){
            pii cur = Q.front();
            Q.pop();
            for(int i=0; i<N; i++){
                if(roads[cur.first][i]=='Y'){
                    int after_xor = cur.second^cityValues[i];

                    if(seen[i][after_xor] == 0){
                        pii next(i, after_xor);
                        seen[i][after_xor] = 1;
                        Q.push(next);
                        if(after_xor > ans){
                            ans = after_xor;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <string> p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    XorTravelingSalesman *obj;
    int answer;
    obj = new XorTravelingSalesman();
    clock_t startTime = clock();
    answer = obj->maxProfit(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;
    
    vector <int> p0;
    vector <string> p1;
    int p2;
    
    {
    // ----- test 0 -----
    int t0[] = {0,7,11,5,2};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    string t1[] = {"NYNYY","YNYNN","NYNNN","YNNNN","YNNNN"};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 14;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
    }
    {
    // ----- test 1 -----
    int t0[] = {556};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    string t1[] = {"N"};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 556;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 2 -----
    int t0[] = {0,4,8,32,512};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    string t1[] = {"NYYYY","YNNNN","YNNNN","YNNNN","YNNNN"};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 556;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    int t0[] = {37,1,19,64,42,41,64,64,54,16,256,36,64,2,4,2,62,29,58,64,1,32,16,256,17,2,17,4,1,64,21,8,256,63,3,1,43,15,8,39,41,8,16,8,16,256,64,512,45,64};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    string t1[] = {"NNNNNNYYYYNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNYYNNNYYNN","NNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNYNNYNYNNNNNNYNNNNNNNNNNYNNNNNNNNNNN","NNYNNNYNNNNNNNNYNNYNNNYYNNNYNYNNNNYNNNNNNNNYNNNNNN","YNYNNYNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNYNNYNN","YNNYNNYNYNYYNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNN","YNNNNNNYNNNNNNNNNNNNNNYNYNNNNNNNNNNYYYNNNNNNNYNNNY","YNNNNNNNNNNNNNNNNYNYNYNYYNNNYNNNNYNNNNNNNNNNNNNNNY","NNNNNNNYNNNNYNNNNNNNNYYNNNYYNNNNYNYYNNNNNNNNNNNNNN","NNNNNNNYNNNNNNYNNNNYYNNNYNNYYNNNNNNNNNNNNNYNYNNNNN","NNNNNNNNNNYNNNNNYNNNNYNNNNNNNNNNYNYNNYNYNNNYNYNNNN","NNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNNYNN","NNNNNNNNNNNYNNNNNYNYNNYYNNNNNYNNNNNNNNNYNNYNNYNNNN","NNNNYYYNNNNNNYNNNYYNNYNNNYNYYNNNNNNNNNYYYNNYNNYNYN","NYNNNNNNNNNNYNNNNNNNYNNNYYNNNYNNNNYNNNNNNNNNNNNNNN","NNNNNNNNNYNNNNYYNNNNNNYNNNYNNNNNYNNYNYYNNNNYNNNYNN","NNNYYYNNNNNNNNNYNNNNNYNYNYNNNNNNNNYNNNNNNNNNNN"
            "NNNN","NNNNNNNNNYNYNNYNNNNNNYNYYYNNNNNNNNNNNYNNYNNNNNYNNN","NNNNYNNNNNNYNNNNYNNNNYNNNYYNNNYNNNYNNNNNNNNNNYNYNY","NNNNNNNNNYYNYNNYNNYYYNYNNNNNNNNYNYNNNNNNNNNNYNNNNN","NNNNNYNNYNYNNNYNNYNNNYNNNNNNNNNNNYNNYNYNNYNNNNNNNN","NNNNNYNNNYNNNNYNNNYYNNNNNNNNNNNNNNNNNNNNNNYNNNYNNN","NYNNNNNNYYNYNNNNYNNYNNNNNNNNNNYNNNNNNYNNNYNNYNNNNN","NNNNNNNNNNNNNYNYYNYYYNNNNNNYNNNNNNNNNNNYYNNNNNNNYN","NNNNNNNNNNYNNNNNNYNNYNNNNNNNNYNNNNYNNNNNNYYNNNNYNN","NNNNYYNNNNYYNNNYNNNNNNNNNYNNNYYNYNNNNNNNNNNNNNNNNN","NNNNNNNNNYNYNNNYNNNNNNNNNNNNNYNNNNYNNNNNNNNYNNYNYN","NNNNNYNNNNNNNNYNYNNNNNNNNNYYYNNNNNNNNYNNNNYNNNNNNN","NNNNNNNNNNNNNNNNNNNNYNNNYNNYNNNNNYNNNNNNNNNNNNNNNY","NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNYNNNNNNN","NNNNNNNNNNYNYNNNNYNNNNNNNNNYNNNYNNNYYNNNNNYNNNYNNN","NNNNNNNNNYNNNNNNNNNNNYYNNNNNNNYNNNNNNNYNNYNNNNNNNN","NNNNNYNYNNYNYNNNYNYNYNNNNNYNYNNNNNNYYNYNYNYNNNNNYN","YNNNNNYNYNYNNNNNNYNNNNNNNNNNNNNNYNYNNNNNYNNYNNNYNN","NNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNYNYNNNNNNYNNNNNNYN","NNNNNNNYYNNNYNNNNYNYNNNNYNNNNYNNNNNNNNNN"
            "NYNNNNYNNN","NNNNYNNNNNNNNYNYNYNNNNYNNNNNNNNNNYYNNNNYNNNNNNNNNY","NNNNNNNNNNNNYNYYNNNNNNNNNYNNNNNNNNNNNNYNNNNNYNYYNN","NNNNNNNNNNNNNNNYNNNYNNNNNYNNNNNNNNYYNNNNNNNNNNNNNN","NYNNNNNNNNNNNNNNNNNNNNYNYNYNNNNNNYNNYYNNNNNNNNNNNN","NYNNNNNNNNNYNNYNNNNNNNNYNNYNNYNYYNYNNNNNNNNNYNNNNN","NNNNNYNNNNNNYNNYNYNNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNY","NNNNNNYNNNNYNNNNNNNNNYNNYNNNNNNNNNNNNNNYNNYNNYNNNY","NNNNNNNNYNNNYNYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNNN","NYNNNNNNNNNNNNNYNNNYNNNYNNNNYNNNYNNNNYNYNNNNNNNNNN","NYNNNNYNNNNNNYNNNYNNYNNNNNYNNNNNNNNYNNNYNNNNNNNNNN","NNNNNNNNNNNNNNNYNNNNNNNNNYNNYNNNNNYNYNNNNNNNNNNNNN","NNNNNNNNYYNNNNNNNNNNYNNNNNNNNNYNNNNNNNYNNNNYYNNNNN"};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 895;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
