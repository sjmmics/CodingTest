class Solution {
    public int[] solution(int n, long left, long right) {
        int span = (int) (right - left + 1);
        int[] answer = new int[span];
        int idx = 0;
        for (long i = left; i < right + 1; i++) {
            long row = i / n;
            long col = i % n;
            answer[idx++] = Math.max((int) row + 1, (int) col + 1);
        }
        
        return answer;
    }
}