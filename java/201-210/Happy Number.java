public class Solution {
    
    public int convert(String str) {
        int val = 0;
        for (int i = 0, n = str.length(); i < n; i++) {
            int c = str.charAt(i) - '0';
            val += c*c;
        }
        return val;
    }
    
    public boolean isHappy(int n) {
        Map m1 = new HashMap();
        
        while(n != 1) {
            m1.put(n, true);
            n = convert(Integer.toString(n));
            if(m1.containsKey(n)) return false;
        }
        return true;
    }
}