class Solution {
    public String solution(String[] my_strings, int[][] parts) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < parts.length; i++) {
            StringBuilder temp = new StringBuilder(my_strings[i]);
            sb.append(temp.substring(parts[i][0], parts[i][1] + 1));
        }
        return sb.toString();
    }
}