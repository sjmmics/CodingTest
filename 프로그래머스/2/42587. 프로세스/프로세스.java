import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public int solution(int[] priorities, int location) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int answer = 0;
        for (int num : priorities) {
            pq.offer(num);
        }
        boolean flag = false;
        while (!pq.isEmpty()) {
            if (flag) break;
            for (int idx = 0; idx < priorities.length; idx++) {
                if (pq.peek() == priorities[idx]) {
                    pq.poll();
                    answer++;
                    if (location == idx) {
                        flag = true;
                        break;
                    }
                } 
            }
        }
        return answer;
    }
}