import java.util.Arrays;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] arrStr = new String[numbers.length];
        
        for (int i = 0; i < numbers.length; i++) {
            arrStr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(arrStr, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        StringBuilder sb = new StringBuilder();
        
        for (String letter : arrStr) {
            sb.append(letter);
        }
        
        answer = sb.toString();
        
        if (answer.charAt(0) == '0') {
            return "0";
        }
        
        return answer;
    }
}