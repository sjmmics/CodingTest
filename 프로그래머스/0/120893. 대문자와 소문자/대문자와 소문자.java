class Solution {
    public String solution(String my_string) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < my_string.length(); i++) {
            char s = my_string.charAt(i);
            if (Character.isUpperCase(s)) {
                sb.append(Character.toString(s).toLowerCase());
            } else {
                sb.append(Character.toString(s).toUpperCase());
            }
        }
        
        String answer = sb.toString();
        return answer;
    }
}