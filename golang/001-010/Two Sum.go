func twoSum(nums []int, target int) []int {
    mymap := make(map[int]int)
    for i := 0; i < len(nums); i++ {
        j, ok := mymap[target-nums[i]]
        if ok {
            result := []int{j, i}
            return result
        }
        mymap[nums[i]] = i
    }
    result := []int{-1, -1}
    return result
}
