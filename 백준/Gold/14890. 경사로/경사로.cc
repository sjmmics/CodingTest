#include <iostream>
#include <vector>

using namespace std;

int N, L, res;
vector<vector<int>> board1, board2;
vector<vector<bool>> install;

bool can_put(vector<vector<int>> &vt, int row, int col) {
    if (vt[row][col] > vt[row][col + 1]) {
        if (col + L >= N) return false;
        for (int j = col + 1; j <= col + L; j++) {
            if (vt[row][col + 1] != vt[row][j]) {
                return false;
            }
            install[row][j] = true;
        }
    } else {
        if (col - L + 1 < 0) return false;
        for (int j = col; j >= col - L + 1; j--) {
            if (install[row][j]) return false;
            if (vt[row][col] != vt[row][j]) {
                return false;
            }
            install[row][j] = true;
        }
    }
    return true;
}

void solution(vector<vector<int>> &vt) {
    for (int i = 0; i < N; i++) {
        bool flag = true;
        int j = 0;
        while (j < N - 1) {
            if (vt[i][j] == vt[i][j + 1]) {
                j++;
                continue;
            }
            if (abs(vt[i][j] - vt[i][j + 1]) > 1) {
                flag = false;
                break;
            }
            if (!can_put(vt, i, j)) {
                flag = false;
                break;
            } else {
                if (vt[i][j] > vt[i][j + 1]) {
                    j += L;
                } else {
                    j++;
                }
            }
            
        }
        if (flag) res++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    board1.assign(N, vector<int>(N, 0));
    board2.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board1[i][j];
            board2[j][i] = board1[i][j];
        }
    }
    install.assign(N, vector<bool>(N, false));
    solution(board1);
    install.assign(N, vector<bool>(N, false));
    solution(board2);
    cout << res << "\n";
}