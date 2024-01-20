class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        int temp;
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        for (long i = a; i <= b; i++) {
            answer += i;
        }
        return answer;
    }
}