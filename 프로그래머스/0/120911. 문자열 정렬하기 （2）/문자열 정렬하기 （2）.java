import java.util.Arrays;

class Solution {
    public String solution(String my_string) {
        String[] arr = my_string.split("");
        for (int i = 0; i  < arr.length; i++) {
            arr[i] = arr[i].toLowerCase();
        }
        Arrays.sort(arr);
        return String.join("", arr);
    }
}