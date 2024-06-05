class Solution {
    public String solution(String new_id) {
        StringBuilder one = stepOne(new_id);
        StringBuilder two = stepTwo(one);
        StringBuilder three = stepThree(two);
        StringBuilder four = stepFour(three);
        StringBuilder five = stepFive(four);
        StringBuilder six = stepSix(five);
        StringBuilder seven = stepSeven(six);
        return seven.toString();
    }
    
    public StringBuilder stepOne(String str) {
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (Character.isUpperCase(c)) {
                answer.append(Character.toLowerCase(c));
            } else {
                answer.append(c);
            }
        }
        return answer;
    }
    
    public StringBuilder stepTwo(StringBuilder sb) {
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c == '.' || c == '-' || c == '_') {
                answer.append(c);
            } else if (Character.isDigit(c) || Character.isAlphabetic(c)) {
                answer.append(c);
            }
        }
        return answer;
    }
    
    public StringBuilder stepThree(StringBuilder sb) {
        String answer = sb.toString();
        while (true) {
            if (!answer.contains("..")) {
                break;
            }
            answer = answer.replace("..", ".");
        }
        return new StringBuilder(answer);
    }
    
    public StringBuilder stepFour(StringBuilder sb) {
        while (true) {
            if (sb.length() == 0) {
                break;
            } else if (sb.charAt(0) != '.') {
                break;
            } else {
                sb.deleteCharAt(0);
            }
        }
        while (true) {
            if (sb.length() == 0) {
                break;
            } else if (sb.charAt(sb.length() - 1) != '.') {
                break;
            } else {
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        return sb;
    }
    
    public StringBuilder stepFive(StringBuilder sb) {
        if (sb.length() == 0) {
            sb.append("a");
        }
        return sb;
    }
    
    public StringBuilder stepSix(StringBuilder sb) {
        while (sb.length() > 15) {
            sb.deleteCharAt(sb.length() - 1);
        }
        while (true) {
            if (sb.length() == 0) {
                break;
            } else if (sb.charAt(sb.length() - 1) != '.') {
                break;
            } else {
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        return sb;
    }
    public StringBuilder stepSeven(StringBuilder sb) {
        while (sb.length() < 3) {
            sb.append(sb.charAt(sb.length() - 1));
        }
        return sb;
    }
    
    
}