class Solution {
    public int solution(int n) {
        int answer = 0;
        for (int numDiv = 1; numDiv <= n; numDiv++) {
            if (n % numDiv == 0) {
                answer += numDiv;
            }
        }
        return answer;
    }
}