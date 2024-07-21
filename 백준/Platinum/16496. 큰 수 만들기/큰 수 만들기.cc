#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string x, string y) {
    string xy = x + y;
    string yx = y + x;
    return xy > yx;
}

int N;
vector<string> vt;
string res;
bool is_all_zero;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    is_all_zero = true;
    for (int i = 0; i < N; i++) {
        string str;  cin >> str;
        if (str != "0") {
            is_all_zero = false;
        }
        vt.push_back(str);
    }
    if (is_all_zero) {
        cout << "0" << "\n";
        return 0;
    }
    sort(vt.begin(), vt.end(), comp);
    for (string str : vt) {
        res += str;
    }
    cout << res << "\n";
}