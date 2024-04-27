import java.util.*;

class Solution {
    public Integer[] solution(int[] numlist, int n) {
        Integer[] answer = new Integer[numlist.length];
        for (int i = 0; i < numlist.length; i++) {
            answer[i] = (Integer) numlist[i];
        }
        Arrays.sort(answer, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (Math.abs(n - o1) == Math.abs(n - o2)) {
                    return o2 - o1;
                } else {
                    return Math.abs(n - o1) - Math.abs(n - o2);
                }
            }
        });
        return answer;
    }
}