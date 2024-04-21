class Solution
{
    public int solution(int n, int a, int b) {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int cnt = 1;
        while (true) {
            if (a % 2 == 1 && b % 2 == 0 && b - a == 1) {
                break;
            }
            if (a % 2 == 1) {
                a = (a + 1) / 2;
            } else {
                a /= 2;
            }
            if (b % 2 == 1) {
                b = (b + 1) / 2;
            } else {
                b /= 2;
            }
            cnt++;
        }

        return cnt;
    }
}

// 1, 2, 3, 4, 5, 6, 7, 8

// 1, 2, 3, 4