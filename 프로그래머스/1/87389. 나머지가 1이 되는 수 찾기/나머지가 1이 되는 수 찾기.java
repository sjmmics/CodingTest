class Solution {
    public int solution(int n) {
        int answer = 0;
        for (int numDiv = 2; numDiv <= n; numDiv++) {
            if (n % numDiv == 1) {
                answer = numDiv;
                break;
            }
        }
        return answer;
    }
}