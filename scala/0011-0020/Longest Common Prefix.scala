import scala.util.control.Breaks._

object Solution {
    def longestCommonPrefix(strs: Array[String]): String = {
        if (strs.isEmpty) {
            return ""
        }
        
        var prefix = strs(0)
        
        for (i <- 1 until strs.length) {
            val str = strs(i)
            
            var k = 0;
            
            breakable {
                while (k < math.min(prefix.length, str.length)) {
                    if (prefix(k) != str(k)) { 
                        break
                    }
                    k += 1
                }
            }
            
            prefix = prefix.substring(0, k)
        }
        
        return prefix;
    }
}
