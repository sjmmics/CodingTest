import java.util.HashMap;

class Solution {
    public int solution(String before, String after) {
        return isPosb(before, after);
    }
    static int isPosb(String a, String b) {
        HashMap<Character, Integer> mapA = new HashMap<>();
        HashMap<Character, Integer> mapB = new HashMap<>();
        for (int i = 0; i < a.length(); i++) {
            mapA.put(a.charAt(i), mapA.getOrDefault(a.charAt(i), 0) + 1);
            mapB.put(b.charAt(i), mapB.getOrDefault(b.charAt(i), 0) + 1);
        }
        int answer = 0;
        if (mapA.equals(mapB)) {
            answer = 1;
        }
        return answer;
        
    }
}