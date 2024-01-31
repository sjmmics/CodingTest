class Solution {
    public int[] solution(int[] arr) {
        if (arr.length == 1) {
            int[] answer = { -1 };
            return answer;
        }
        
        int[] answer = new int[arr.length - 1];
        
        int smst = Integer.MAX_VALUE;
        for (int num : arr) {
            smst = Math.min(smst, num);
        }
        int idx = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != smst) {
                answer[idx++] = arr[i];
            }
        }
        
        return answer;
    }
}