// https://leetcode.com/problems/trapping-rain-water/
// optimal solution

func trap(height []int) int {
    total := 0
    length := len(height)
    
    left := 0
    right := length - 1
    
    lMax := 0
    rMax := 0
    
    for left < right {
        if height[left] < height[right] {
            if height[left] >= lMax {
                lMax = height[left]
            } else {
                total += lMax - height[left]
            }
            
            left++
        } else {
            if height[right] >= rMax {
                rMax = height[right]
            } else {
                total += rMax - height[right]
            }
            
            right--
        }
    }
    
    return total
}