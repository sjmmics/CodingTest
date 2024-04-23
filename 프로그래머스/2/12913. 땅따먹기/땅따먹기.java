class Solution {
    int solution(int[][] land) {
        int answer = 0;
        int[][] dpt = new int[land.length][4];
        
        for (int j = 0; j < 4; j++) {
            dpt[1][j] = land[1][j] + getBgst(land[0], j);
        }
        for (int i = 2; i < land.length; i++) {
            for (int j = 0; j < 4; j++) {
                dpt[i][j] = land[i][j] + getBgst(dpt[i - 1], j);
            }
        }
        answer = getBgst(dpt[land.length - 1], 5);

        return answer;
    }
    
    static int getBgst(int[] arr, int excludeIdx) {
        int answer = Integer.MIN_VALUE;
        for (int i =0; i < arr.length; i++) {
            if (i != excludeIdx) { 
                answer = Math.max(arr[i], answer);
            }
        }
        return answer;
    }
}

// dpt = [[]]


//  [
//   [5 + ]
//
//