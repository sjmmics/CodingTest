import java.util.HashMap;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < name.length; i++) {
            map.put(name[i], yearning[i]);
        }
        for (int i = 0; i < photo.length; i++) {
            int sumScore = 0;
            for (String nameInPhoto : photo[i]) {
                sumScore += map.getOrDefault(nameInPhoto, 0);
            }
            answer[i] = sumScore;
        }
        return answer;
    }
}