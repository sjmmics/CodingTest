#include <iostream>
#include <vector>

using namespace std;

int N;
int res;
vector<int> arr;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    for (int i = 0; i < N; i++) {
        if (arr[i + 1] > arr[i + 2]) {
            int smst = min(arr[i], arr[i + 1] - arr[i + 2]);
            res += 5 * smst;
            arr[i] -= smst;
            arr[i + 1] -= smst;

            smst = min(arr[i], min(arr[i + 1], arr[i + 2]));
            res += 7 * smst;

            arr[i] -= smst;
            arr[i + 1] -= smst;
            arr[i + 2] -= smst;
        } else {
            int smst = min(arr[i], min(arr[i + 1], arr[i + 2]));
            res += 7 * smst;

            arr[i] -= smst;
            arr[i + 1] -= smst;
            arr[i + 2] -= smst;

            smst = min(arr[i], arr[i + 1]);
            res += 5 * smst;

            arr[i] -= smst;
            arr[i + 1] -= smst;
        }
        res += 3 * arr[i];
        arr[i] = 0;
    }

    cout << res << "\n";
}