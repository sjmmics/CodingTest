#include <iostream>

#define RL 10'000

using namespace std;

int T;
int arr[RL + 1];

pair<int, int> solution(int n) {
    int mid = n / 2;
    for (int i = mid; i > 1; i--) {
        int low = i;
        int high = n - low;
        if (arr[low] != 0 && arr[high] != 0) {
            return make_pair(low, high);
        }
    }
}

void set_array() {
    for (int i = 2; i <= RL; i++) {
        arr[i] = i;
    }
    for (int i = 2; i <= RL; i++) {
        if (arr[i] == 0) continue;
        for (int j = 2 * i; j <= RL; j += i) {
            arr[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set_array();
    cin >> T;
    while (T--) {
        int n;  cin >> n;
        pair<int, int> res = solution(n);
        cout << res.first << " " << res.second << "\n";
    }
}