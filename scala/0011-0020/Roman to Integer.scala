object Solution {
    def romanToInt(s: String): Int = {
        val table = Map(
            'I' -> 1,
            'V' -> 5,
            'X' -> 10,
            'L' -> 50,
            'C' -> 100,
            'D' -> 500,
            'M' -> 1000 
        )
        
        var result = 0
        
        for (i <- 0 until s.length()) {
            if (i < s.length()-1 && table(s(i)) < table(s(i+1)) ) {
                result -= table(s(i))
            } else {
                result += table(s(i))
            }
        }
        
        result
    }
}
