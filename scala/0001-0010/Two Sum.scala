import scala.collection._

object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val map = mutable.Map[Int, Int]()
    for (i <- 0 until nums.length) {
      val num = target - nums(i)
      if (map.contains(num)) {
        return Array(map(num), i)
      }
      map.put(nums(i), i)
    }
    
      return Array(0, 0)
  }
}
