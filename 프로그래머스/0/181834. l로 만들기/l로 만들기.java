class Solution {
    public String solution(String myString) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < myString.length(); i++) {
            if ((int) 'l' > myString.charAt(i)) {
                sb.append("l");
            } else {
                sb.append(Character.toString(myString.charAt(i)));
            }
        }
        return sb.toString();
    }
}