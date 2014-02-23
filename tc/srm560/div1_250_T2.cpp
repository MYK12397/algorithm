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
const int INF = 999999999;

class TomekPhone {
    public:
        int minKeystrokes(vector <int> frequencies, vector <int> keySizes) {

        
        
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    TomekPhone *obj;
    int answer;
    obj = new TomekPhone();
    clock_t startTime = clock();
    answer = obj->minKeystrokes(p0, p1);
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
    vector <int> p1;
    int p2;

    {
        // ----- test 0 -----
        int t0[] = {7,3,4,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {2,2};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 19;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {13,7,4,20};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {2,1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = -1;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {11,23,4,50,1000,7,18};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {3,1,4};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1164;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {100,1000,1,10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {50};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1234;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {10,10,10,10,10,10,10,10};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 3353;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
