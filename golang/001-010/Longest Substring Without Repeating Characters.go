func lengthOfLongestSubstring(s string) int {
    var i, maximum_len int = 0, 0
    mymap := make(map[byte]int)
    
    for j := 0; j < len(s); j++ {
        mymap[s[j]]++
        for mymap[s[j]] == 2 && i < j {
            mymap[s[i]]--
            i++
        }
        
        if maximum_len < j - i + 1 {
            maximum_len = j - i + 1
        }
    }
    
    return maximum_len
}
