#include <iostream>
#include <string>
#include <deque>

using namespace std;

int T;
string bgn_str;
string end_str;
deque<char> temp;   
const string PASS = "Yes";
const string FAIL = "No";

bool dfs(bool is_forward) {
    if (temp.size() <= end_str.size()) {
        string str = "";
        if (is_forward) {
            deque<char>::iterator iter;
            for (iter = temp.begin(); iter != temp.end(); iter++) {
                str += *iter;
            }
        } else {
            deque<char>::reverse_iterator riter;   
            for (riter = temp.rbegin(); riter != temp.rend(); riter++) {
                str += *riter;
            }
        }
        if (str.compare(end_str) == 0) {
            return true;
        } else {
            return false;
        }
    }
    if (is_forward) {
        if (temp.back() == 'X') {
            temp.pop_back();
            if (dfs(is_forward)) return true;
            temp.push_back('X');
        } 
        if (temp.back() == 'Y') {
            temp.pop_back();
            if (dfs(!is_forward)) return true;
            temp.push_back('Y');
        }
    } else {
        if (temp.front() == 'X') {
            temp.pop_front();
            if (dfs(is_forward)) return true;
            temp.push_front('X');
        }
        if (temp.front() == 'Y') {
            temp.pop_front();
            if (dfs(!is_forward)) return true;
            temp.push_front('Y');
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> end_str;
        cin >> bgn_str;
        for (int i = 0; i < bgn_str.size(); i++) {
            temp.push_back(bgn_str[i]);
        }
        if (dfs(true)) {
            cout << '#' << t << " " << PASS << "\n";
        } else {
            cout << '#' << t << " " << FAIL << "\n";
        }
        temp.clear();
    }
    return 0;
}  