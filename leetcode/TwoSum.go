// https://leetcode.com/problems/two-sum/

func twoSum(nums []int, target int) []int {
    ht := make(map[int]int)
    
    for i, val := range nums {
        goal := target - val
        
        if _, ok := ht[goal]; ok {
            return []int{ht[goal], i}
        }
        
        ht[val] = i
    }
    
    return []int{-1, -1}
}