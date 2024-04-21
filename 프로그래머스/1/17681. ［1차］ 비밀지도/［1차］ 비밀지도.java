class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for (int i = 0; i < n; i++) {
            String bin1 = toBinary(arr1[i], n);
            String bin2 = toBinary(arr2[i], n);
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                Character digit1 = bin1.charAt(j);
                Character digit2 = bin2.charAt(j);                
                if (digit1.equals('1') || digit2.equals('1')) {
                    sb.append("#");              
                } else {
                    sb.append(" ");
                }            
            }
            answer[i] = sb.toString();            
        }
        
        return answer;
    }
    
    static String toBinary(int x, int span) {
        StringBuilder sb = new StringBuilder();
        while (x > 0) {
            
            int div;
            if (x % 2 == 0) {
                div = 0;
            } else {
                div = 1;
            }
            x /= 2;
            sb.append("" + div);
            
            if (x == 1) {
                sb.append("" + x);
                break;
            }
        }
        while (sb.length() < span) {
            sb.append("0");
        }
        sb.reverse();
        String res = sb.toString();
        return res;
        
    }
    
}