import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        return getSmstTime(bridge_length, weight, truck_weights);
    }
    static int getSmstTime(int span, int loadLimit, int[] trucks) {
        Queue<Integer> que = new LinkedList<>();
        for (int i = 0; i < span; i++) {
            que.add(0);
        }
        int answer = 1;
        int load = 0;
        int idx = 0;
        while (true) {
            if (!que.isEmpty()) {
                load -= que.poll();
            }
            if (idx >= trucks.length) {
                que.add(0);
                if (load == 0) {
                    break;
                }
            } else if (load + trucks[idx] > loadLimit) {
                que.add(0);
            } else {
                que.add(trucks[idx]);
                load += trucks[idx++];
            }
            answer++;
        }
        return answer;
    }
}