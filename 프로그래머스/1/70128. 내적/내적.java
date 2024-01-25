class Solution {
    public int solution(int[] a, int[] b) {
        int answer = 0;
        for (int idx = 0; idx < a.length; idx++) {
            answer += (a[idx] * b[idx]);
        }
        return answer;
            
    }
}