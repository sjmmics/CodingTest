
class Solution {
    public int[] solution(int[] arr) {
        int firstIdx = 0;
        int lastIdx = 0;
        boolean flag = false;
        for (int i = 0; i < arr.length; i++) {
            if (!flag && arr[i] == 2) {
                firstIdx = i;
                flag = true;
            }
            if (flag && arr[i] == 2) {
                lastIdx = i;
            }
        }
        int[] answer;
        if (!flag) {
            answer = new int[1];
            answer[0] = -1;
        } else {
            answer = new int[lastIdx - firstIdx + 1];
            int idx = 0;
            for (int i = firstIdx; i <= lastIdx; i++) {
                answer[idx++] = arr[i];
            }       
        }
        return answer;
    }
}