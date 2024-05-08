import java.util.HashMap;

class Solution {
    public int solution(int[] topping) {
        return getPairWayToCut(topping);
    }
    static int getPairWayToCut(int[] topping) {
        HashMap<Integer, Integer> mapLeft = new HashMap<>();
        HashMap<Integer, Integer> mapRight = new HashMap<>();
        for (int i = 0; i < topping.length; i++) {
            mapRight.put(topping[i], mapRight.getOrDefault(topping[i], 0) + 1);
        }
        int answer = 0;
        for (int i = 0; i < topping.length - 1; i++) {
            mapLeft.put(topping[i], mapLeft.getOrDefault(topping[i], 0) + 1);
            mapRight.put(topping[i], mapRight.get(topping[i]) - 1);
            if (mapRight.get(topping[i]) == 0) {
                mapRight.remove(topping[i]);
            }
            if (mapLeft.size() == mapRight.size()) {
                answer++;
            }
        }
        return answer;
    }
}