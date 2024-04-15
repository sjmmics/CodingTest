import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings);
        Arrays.sort(strings, (o1, o2) -> 
            (o1.substring(n, n + 1)).compareTo(o2.substring(n, n + 1)));
        return strings;
    }
}