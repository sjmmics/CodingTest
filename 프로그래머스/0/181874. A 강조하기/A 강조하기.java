class Solution {
    public String solution(String myString) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < myString.length(); i++) {
            char c = myString.charAt(i);
            if (c == 'a') {
                sb.append(Character.toString(c).toUpperCase());
            } else if (c != 'A' && Character.isUpperCase(c)) {
                sb.append(Character.toString(c).toLowerCase());
            } else {
                sb.append(Character.toString(c));
            }
        }
        answer = sb.toString();
        return answer;
    }
}