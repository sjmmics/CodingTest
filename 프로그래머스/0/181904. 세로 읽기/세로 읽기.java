class Solution {
    public String solution(String my_string, int m, int c) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < my_string.length(); i++) {
            int rowIdx = i / m;
            int colIdx = i % m;
            if (colIdx + 1 == c) {
                sb.append(Character.toString(my_string.charAt(i)));
            }
            
        }
        
        
        String answer = sb.toString();
        return answer;
    }
}