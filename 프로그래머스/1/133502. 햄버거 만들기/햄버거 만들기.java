import java.util.ArrayList;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        ArrayList<Integer> list = new ArrayList<>();
        
        for (int num : ingredient) {
            list.add(num);
            if (canMakeHamburger(list)) {
                answer++;
                for (int i = 0; i < 4; i++) {
                    list.remove(list.size() - 1);
                }
            }
        }
        
        return answer;
    }
    public boolean canMakeHamburger(ArrayList<Integer> list) {
        if (list.size() < 4) {
            return false;
        }
        // 1, 2, 3, 1
        int lastIndex = list.size() - 1;
        if (list.get(lastIndex) != 1 || list.get(lastIndex - 3) != 1) {
            return false;
        }
        if (list.get(lastIndex - 1) != 3 || list.get(lastIndex - 2) != 2) {
            return false;
        }
        return true;
    }
}