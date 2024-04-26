import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        HashMap<String, Integer> wishMap = new HashMap<>();
        for (int i = 0; i < want.length; i++) {
            wishMap.put(want[i], number[i]);
        }
        HashMap<String, Integer> tenDaysDc = new HashMap<>();
        for (int i = 0; i < discount.length; i++) {
                        
            if (i < 10) {
                tenDaysDc.put(discount[i], tenDaysDc.getOrDefault(discount[i], 0) + 1);
                if (i == 9) {
                    if (isGetAll(wishMap, tenDaysDc)) {
                        answer++;
                    }
                }
            } else {
                tenDaysDc.put(discount[i - 10], tenDaysDc.get(discount[i - 10]) - 1);
                tenDaysDc.put(discount[i], tenDaysDc.getOrDefault(discount[i], 0) + 1);
                if (isGetAll(wishMap, tenDaysDc)) {
                    answer++;
                }
            }
        }
        return answer;
    }
    static Boolean isGetAll(HashMap<String, Integer> goal, HashMap<String, Integer> target) {
        Boolean answer = true;
        for (String productToWant : goal.keySet()) {
            if (goal.getOrDefault(productToWant, 0) != target.getOrDefault(productToWant, 0)) {
                answer = false;
                break;
            }
        }
        return answer;
    } 
}