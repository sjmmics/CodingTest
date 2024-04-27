import java.util.ArrayList;

class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        
        for (int num : arr ) {
            for (int i = 0; i < num; i++) {
                list.add(num);
            }
        }
        
        int[] answer = new int[list.size()];
        int idx = 0;
        for (int num : list) {
            answer[idx++] = num;
        }
        return answer;
    }
}