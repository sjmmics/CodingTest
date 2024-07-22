#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> indegree, result;
vector<vector<int>> grp;

void solution() {
    queue<int> que;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (que.empty()) return;
        int crr = que.front();  que.pop();
        result[i] = crr;
        
        for (int nxt : grp[crr]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                que.push(nxt);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    grp.assign(N + 1, vector<int>(0, 0));
    indegree.assign(N + 1, 0);
    result.assign(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int A, B;  cin >> A >> B;
        grp[A].push_back(B);
        indegree[B]++;
    }
    solution();
    for (int num : result) {
        cout << num << " ";
    }
}