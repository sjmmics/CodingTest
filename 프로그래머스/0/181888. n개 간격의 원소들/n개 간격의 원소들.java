class Solution {
    public int[] solution(int[] num_list, int n) {
        
        int span = num_list.length / n;
        if (num_list.length % n != 0) {
            span++;
        }
        int[] answer = new int[span];
        for (int i = 0; i < span; i++) {
            int j = i * n;
            answer[i] = num_list[j];
        }
        return answer;
    }
}