class Solution {
    public int solution(int[][] board, int k) {
        return getSumArr(board, k);
    }
    int getSumArr(int[][] arr, int k) {
        int answer = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (i + j <= k) {
                    answer += arr[i][j];
                }
            }
        }
        return answer;
    }
}