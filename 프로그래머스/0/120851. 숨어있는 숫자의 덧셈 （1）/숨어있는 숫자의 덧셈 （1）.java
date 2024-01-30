class Solution {
    public int solution(String my_string) {
        int answer = 0;
        for (int i = 0; i < my_string.length(); i++) {
            if (my_string.charAt(i) >= 48 && my_string.charAt(i) <= 57) {
                answer += Character.getNumericValue(my_string.charAt(i));
            }
        }
        
        return answer;
    }
}