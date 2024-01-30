class Solution {
    public String solution(String my_string, int n) {
        int span = my_string.length();
        String answer = my_string.substring(span - n, span);
        return answer;
    }
}