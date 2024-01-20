class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        for (int idx = 0; idx < n; idx++) {
            answer[idx] = x + (long) x * idx;
        }
        return answer;
    }
}