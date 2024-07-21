#include <iostream>
#include <vector>

using namespace std;

int N, res;
int arr[21][21], drop[21][21];

void solution() {
    for (int t = 0; t < N; t++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (t == i || t == j) continue;
                if (arr[i][j] > arr[i][t] + arr[t][j]) {
                    res = -1;
                    return;
                }
                if (arr[i][j] == arr[i][t] + arr[t][j]) {
                    drop[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            res += drop[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;  cin >> x;
            arr[i][j] = x;
            drop[i][j] = x;
        }
    }
    solution();
    cout << res << "\n";
}