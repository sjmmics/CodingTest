#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int arr[10][10];
vector<int> vt;

int getSum(int left, int right) {
    int ret = 0;
    for (int i = left; i < right; i++) {
        ret += vt[i];
    }
    return ret;
}

bool isRight(int x, int rightIdx) {
    for (int i = 0; i <= rightIdx; i++) {
        int sum = x + getSum(i, rightIdx);
        if (sum > 0) {
            sum = 1;
        } else if (sum < 0) {
            sum = -1;
        } else {
            sum = 0;
        }
        if (sum != arr[i][rightIdx]) {
            return false;
        }
    }
    return true;
}

void solution(int span) {
    if (span == N) {
        for (int num : vt) {
            cout << num << " ";
        }
        cout << "\n";
        exit(0);
    }
    for (int i = -10; i <= 10; i++) {
        if (isRight(i, span)) {
            vt.push_back(i);
            solution(span + 1);
            vt.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string line;  cin >> line;
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (line[idx] == '+') {
                arr[i][j] = 1;
            } else if (line[idx] == '-') {
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
            }
            idx++;
        }
    }
    solution(0);

}