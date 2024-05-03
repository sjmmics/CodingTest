import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public long solution(int n, int[] works) {
        
        return getLeastFatigue(n, works);
    }
    
    static long getLeastFatigue(int n, int[] works) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (Integer work : works) {
            pq.add(work);
        }
        for (int i = 0; i < n; i++) {
            if (pq.peek() == 0) {
                return 0L;
            }
            pq.add((Integer) pq.poll() - 1);
        }
        long answer = 0L;
        while (pq.size() > 0) {
            answer = answer + (long) Math.pow(pq.poll(), 2);
        }
        return answer;
    }
    
}