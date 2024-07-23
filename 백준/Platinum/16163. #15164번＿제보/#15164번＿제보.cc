#include <iostream>
#include <string>
#include <vector>

using namespace std;

string line, str;
vector<int> dpt;

long long solution() {
    dpt.assign(str.size(), 0);
    int r = 0, p = 0;
    for (int i = 0; i < str.size(); i++) {
        if (i <= r) {
            dpt[i] = min(dpt[2 * p - i], r - i);
        } else {
            dpt[i] = 0;
        }
        while (i - dpt[i] - 1 >= 0 && i + dpt[i] + 1 < str.size() && 
                str[i - dpt[i] - 1] == str[i + dpt[i] + 1]) {
            
            dpt[i]++;
        }
        
        if (r < i + dpt[i]) {
            r = i + dpt[i];
            p = i;
        }
    }

    long long ans = 0;
    for (int i = 0; i < dpt.size(); i++) {
        ans += (long long) (dpt[i] + 1) / 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> line;
    str = "#";
    for (int i = 0; i < line.size(); i++) {
        str += line[i];
        str += "#";
    }
    cout << solution() << "\n";
}