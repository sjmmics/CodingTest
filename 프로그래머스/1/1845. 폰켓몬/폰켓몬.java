import java.util.HashSet;

class Solution {
    public int solution(int[] nums) {
        HashSet<String> set = new HashSet<>();
        for (int pokemonNum : nums) {
            set.add("" + pokemonNum);
        }
        int answer;
        if (set.size() > nums.length / 2) {
            answer = nums.length / 2;
        } else {
            answer = set.size();
        }
        return answer;
    }
}