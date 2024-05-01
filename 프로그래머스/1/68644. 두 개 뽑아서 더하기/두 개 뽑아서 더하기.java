import java.util.HashSet;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        HashSet<Integer> set = new HashSet<>();
        
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                set.add(numbers[i] + numbers[j]);
            }
        }
        Integer[] arr = set.toArray(new Integer[0]);
        Arrays.sort(arr);
        
        int[] answer = Arrays.stream(arr).mapToInt(i -> i).toArray();
        
        return answer;
    }
}