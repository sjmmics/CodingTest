#include <iostream>
#include <stack>

using namespace std;

int n;
long long res;
stack<long long> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int bgst = 0;
    for (int i = 0; i < n; i++) {
        int x;  cin >> x;
        bgst = max(x, bgst);
        while (!stk.empty() && stk.top() < x) {
            long long top = stk.top();
            stk.pop();
            if (!stk.empty()) {
                res += min(x - top, stk.top() - top);
            } else {
                res += x - top;
            }
        }
        stk.push(x);
    }
    while (!stk.empty() && stk.top() < bgst) {
        long long top = stk.top();
        stk.pop();
        if (!stk.empty()) {
            res += min(bgst - top, stk.top() - top);
        } else {
            res += bgst - top;
        }
    }
    cout << res << "\n";
}