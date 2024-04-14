class Solution {
    public String solution(String s, int n) {
        String answer = "";
        for (int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if (Character.isUpperCase(letter)) {
                letter = (char) ((letter - 'A' + n) % 26 + 'A');
            } else if (Character.isLowerCase(letter)) {
                letter = (char) ((letter - 'a' + n) % 26 + 'a');
            }
            answer += letter;
        }
        
        return answer;
    }
}