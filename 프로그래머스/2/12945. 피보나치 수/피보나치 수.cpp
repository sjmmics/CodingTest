#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dpt[n + 1];
    dpt[0] = 0;
    dpt[1] = 1;
    for (int i = 2; i <= n; i++) {
        dpt[i] = (dpt[i - 1] + dpt[i - 2]) % 1234567;
    }
    return dpt[n];
}