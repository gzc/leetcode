import scala.collection._

object Solution {
    def lengthOfLongestSubstring(s: String): Int = {
        val mymap = mutable.Map[Int, Int]()
        var start = 0
        var ans = 0
        
        for (i <- 0 until s.length()) {
            val ch = s(i)
            if (mymap.contains(ch)) {
                start = Math.max(start, mymap(ch) + 1)
            }
            
            mymap(ch) = i
            ans = Math.max(ans, i - start + 1)
        }
        
        ans
    }
}
