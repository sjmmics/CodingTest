import java.util.HashSet;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int numZero = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int num : lottos) {
            if (num == 0) {
                numZero++;
            } else {
                set.add(num);    
            }
            
        }
        
        int min = 0;
        for (int num : win_nums) {
            if (set.contains(num)) {
                min++;
            }
        }
        int max = Math.min(6, min + numZero);
        int[] answer = new int[2];
        answer[0] = getGrade(max);
        answer[1] = getGrade(min);
        return answer;
    }
    public int getGrade(int m) {
        if (m >= 6) {
            return 1;
        }
        if (m >= 5) {
            return 2;
        }
        if (m >= 4) {
            return 3;
        }
        if (m >= 3) {
            return 4;
        }
        if (m >= 2) {
            return 5;
        }
        return 6;
    }
}