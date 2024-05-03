import java.util.HashSet;

class Solution {
    public int solution(int order) {
        int answer = 0;
        HashSet<Character> haveToClap = new HashSet<>();
        haveToClap.add('3');
        haveToClap.add('6');
        haveToClap.add('9');
        
        String str = Integer.toString(order);
        for (int i = 0; i < str.length(); i++) {
            Character crr = str.charAt(i);
            if (haveToClap.contains(crr)) {
                answer++;
            } 
        }
        return answer;
    }
}