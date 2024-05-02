import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> pMap = new HashMap<>();
        HashMap<String, Integer> cMap = new HashMap<>();
        for (String p : participant) {
            pMap.put(p, pMap.getOrDefault(p, 0) + 1);
        }
        for (String c : completion) {
            cMap.put(c, cMap.getOrDefault(c, 0) + 1);
        }
        for (String key : pMap.keySet()) {
            pMap.put(key, pMap.getOrDefault(key, 0) -  cMap.getOrDefault(key, 0));
        }
        String answer = "";
        for (String notCmplt : pMap.keySet()) {
            if (pMap.get(notCmplt) != 0) {
                answer = notCmplt;        
            }
        }
        return answer;
    }
}