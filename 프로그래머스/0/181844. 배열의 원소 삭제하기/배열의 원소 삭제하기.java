import java.util.HashSet;
import java.util.ArrayList;

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        ArrayList<Integer> list = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();
        for (int num : delete_list) {
            set.add(num);
        }
        for (int num : arr) {
            if (!set.contains(num)) {
                list.add(num);
            }
        }
        int[] answer = new int[list.size()];
        int idx = 0;
        for (int num : list) {
            answer[idx] = num;
            idx++;
        }

        return answer;
    }
}