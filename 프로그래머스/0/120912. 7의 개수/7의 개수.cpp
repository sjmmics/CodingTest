#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int res = 0;
    for (int num : array) {
        string str = to_string(num);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '7') {
                res++;
            }
        }
    }
    return res;
    
}