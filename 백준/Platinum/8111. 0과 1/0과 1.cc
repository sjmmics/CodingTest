#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int T, N;
bool vstd[20'001];

void bfs() {
    queue<pair<int, string>> que;
    que.push({ 1, "1" });
    vstd[1] = true;

    while (!que.empty()) {
        int crr_mod = que.front().first;
        string num_str = que.front().second;
        que.pop();

        if (crr_mod == 0) {
            cout << num_str << "\n";
            return;
        }

        pair<int, string> nxt[2];
        nxt[0] = { (crr_mod * 10) % N, num_str + "0" };
        nxt[1] = { (crr_mod * 10 + 1) % N, num_str + "1" };
        
        for (auto [nxt_mod, nxt_num_str] : nxt) {
            if (vstd[nxt_mod]) continue;
            vstd[nxt_mod] = true;
            que.push({ nxt_mod, nxt_num_str });
        }
    }
    cout << "BRAK" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N;
        if (N == 1) {
            cout << "1" << "\n";
        } else {
            memset(vstd, false, sizeof(vstd));
            bfs();
        }
    }
}