import java.util.HashMap;

class Solution {
    public String solution(int[] numLog) {
        HashMap<Integer, String> map = new HashMap<>();
        map.put(1, "w");
        map.put(-1, "s");
        map.put(10, "d");
        map.put(-10, "a");
        
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < numLog.length - 1; i++) {
            int diff = numLog[i + 1] - numLog[i];
            sb.append(map.get(diff));
        }
        return sb.toString();
    }
}