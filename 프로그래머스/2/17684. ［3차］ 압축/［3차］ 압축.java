import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public int[] solution(String msg) {
        
        return getIdx(msg);
    }
    
    int[] getIdx(String msg) {
        HashMap<String, Integer> map = new HashMap<>();
        int idx = 1;
        for (int i = (int) 'A'; i < (int) 'Z' + 1; i++) {
            map.put(Character.toString((char) i), idx++);
        }
        ArrayList<Integer> ansList = new ArrayList<>(); 
        idx = 0;
        int crrKey = 27;
        while (idx < msg.length()) {
            boolean allIn = true;
            for (int i = idx + 1; i <= msg.length(); i++) {
                if (!map.containsKey(msg.substring(idx, i))) {
                    ansList.add(map.get(msg.substring(idx, i - 1)));
                    map.put(msg.substring(idx, i), crrKey++);
                    idx = i - 1;
                    allIn = false;
                    break;
                }
            }
            if (allIn) {
                ansList.add(map.get(msg.substring(idx, msg.length())));
                idx = msg.length();
            }
            
        }
        int idxAns = 0;
        int[] answer = new int[ansList.size()];
        for (int num : ansList) {
            answer[idxAns++] = num;
        }
        return answer;
    }
}