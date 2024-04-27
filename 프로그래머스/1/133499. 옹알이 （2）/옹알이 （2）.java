import java.util.HashSet;
import java.util.ArrayList;

class Solution {
    
    public int solution(String[] babbling) {
        String[] canDo = {"aya", "ye", "woo", "ma"};
        int answer = 0;
        for (String bab : babbling) {
            if (canBab(canDo, bab)) {
                answer++;
            }
        }
        
        return answer;
    }
    static boolean canBab(String[] canDo, String bab) {
        boolean answer = true;
        int lastUsedIdx = 5;
        StringBuilder sb = new StringBuilder(bab);
        while (sb.length() > 0) {
            boolean flag = false;
            for (int i = 0; i < canDo.length; i++) {
                if (lastUsedIdx != i) {
                    int span = canDo[i].length();
                    if (sb.length() >= span) {
                        if (canDo[i].equals(sb.substring(0, span))) {
                            sb.delete(0, span);
                            lastUsedIdx = i;
                            flag = true;
                        }
                    }
                }
            }
            if (!flag) {
                answer = false;
                break;
            }
        }
        return answer;
        
    }
    
    
    
}