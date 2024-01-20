class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int rowspanOne = arr1.length;
        int colspanOne = arr1[0].length;
        int rowspanTwo = arr2.length;
        int colspanTwo = arr2[0].length;
        int[][] answer = new int[rowspanOne][colspanTwo];
        for (int i = 0; i < rowspanOne; i++) {
            for (int j = 0; j < colspanTwo; j++) {
                answer[i][j] = 0;
            }
        }
        for (int i = 0; i < rowspanOne; i++) {
            for (int j = 0; j < colspanTwo; j++) {
                for (int k = 0; k < rowspanTwo; k++) {
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        
        return answer;
    }
}