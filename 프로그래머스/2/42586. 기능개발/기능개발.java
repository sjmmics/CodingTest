import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;


class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<>();
        Deque<Integer> que = new LinkedList<>();
        
        for (int i = 0; i < speeds.length; i++) {
            que.addLast(getDiffLaunch(progresses[i], speeds[i]));
        }
        
        while (que.size() > 0) {
            int sum = 1;
            int outValue = que.pollFirst();
            while (que.size() > 0) {
                if (outValue >= que.getFirst()) {
                    que.pollFirst();
                    sum++;
                } else {
                    break;
                }
            }
            answer.add(sum);
        }
        int[] ans = new int[answer.size()];
        int idx = 0;
        for (Integer num : answer) {
            ans[idx++] = num;
        }
        
        return ans;
        
    }
    
    static int getDiffLaunch(int progress, int speed) {
        int answer;
        if ((100 - progress) % speed == 0) {
            answer = (100 - progress) / speed;
        } else {
            answer = (100 - progress) / speed + 1;
        }
        return answer;
        
    }
}