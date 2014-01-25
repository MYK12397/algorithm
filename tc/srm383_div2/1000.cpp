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




int dir[4][2] = {
    {1,0},{-1,0},{0,1},{0,-1}
};
int INF = 99999999;
const int MAXN = 651;
typedef pair<int, int> pii;


int row_sz, col_sz;
int mapping[MAXN][MAXN];
int get_value(char c){
    if(c>='A' && c<='Z'){
        return c-'A';
    }else{
        return c-'a' + 26;
    }
}
int dp[MAXN][MAXN], g[MAXN][MAXN];

void floyd(){
    int sz = row_sz*col_sz;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            dp[i][j] = g[i][j];
        }
    }

    for(int k=0; k<sz; k++){
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
}


void build_graph(vector<string> &landscape, int threshold){
    row_sz = landscape.size();
    col_sz = landscape[0].size();
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
        g[i][j] = INF;
    }

    for(int i=0; i<row_sz; i++){
        for(int j=0; j<col_sz; j++){
            int num = i*col_sz + j;
            mapping[i][j] = get_value(landscape[i][j]);
            for(int k=0; k<4; k++){
                int x = i+dir[k][0];
                int y = j+dir[k][1];
                if(x>=0 && x<row_sz && y>=0 && y<col_sz){
                    int next_num = x*col_sz + y;
                    int cur_value = get_value(landscape[i][j]);
                    int next_value = get_value(landscape[x][y]);

                    
                    int distance = INF;
                    int dif = abs(next_value-cur_value);
                    if(dif<=threshold){
                        if(cur_value < next_value ){
                            distance = next_value - cur_value;
                            distance*=distance;
                            g[num][next_num] = distance;
                        }else if(cur_value >= next_value ){
                            distance = 1;
                            g[num][next_num] = distance;
                        }
                    }
                }
            }
        }
    }
}



class HillWalker {
    public:
        int highestPoint(vector <string> landscape, int threshold, int timeToDark) {
            build_graph(landscape, threshold);

            floyd();
            int ans = mapping[0][0];

            for(int i=0; i<row_sz; i++){
                for(int j=0; j<col_sz; j++){
                    int num = i*col_sz+j;
                    if(dp[0][num]!=INF && dp[num][0]!=INF && dp[0][num] + dp[num][0] <= timeToDark){
                        ans = max(mapping[i][j], ans);
                    }
                }
            }
            return ans;

        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << p1 << "," << p2;
    cout << "]" << endl;
    HillWalker *obj;
    int answer;
    obj = new HillWalker();
    clock_t startTime = clock();
    answer = obj->highestPoint(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
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

    vector <string> p0;
    int p1;
    int p2;
    int p3;
    {
        // ----- test 0 -----
        string t0[] = {"S", "l", "b", "c", "Q", "O"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        p2 = 281;
        p3 = 18;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
return 0;
    {
        // ----- test 1 -----
        string t0[] = {"AD","JG"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        p2 = 29;
        p3 = 6;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        string t0[] = {"AABCDE","GJIHGF","MKLMNO","STSRQP","YUVWXY","edcbaZ"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 6;
        p2 = 36;
        p3 = 30;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"BCDE","AJKF","AIHG","AAAA","AOMK","AQSI","ACEG"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 5;
        p2 = 14;
        p3 = 10;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"BCDE","AJKF","AIHG","AAAA","AOMK","AQSI","ACEG"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 5;
        p2 = 57;
        p3 = 18;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 5 -----
        string t0[] = {"ABCDEFK"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        p2 = 1000;
        p3 = 5;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 6 -----
        string t0[] = {"TRRVUXefk","bSNMOWcff","bRPNNQZip","XSRUTVcfj","WbZQPXZbV","XdYSRWVOP","feedVVcZR","XhfdZZefg"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4;
        p2 = 50;
        p3 = 28;
        all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
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