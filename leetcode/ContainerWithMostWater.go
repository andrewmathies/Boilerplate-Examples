// https://leetcode.com/problems/container-with-most-water/

func maxArea(height []int) int {
    li := 0
    ri := len(height) - 1
    maxArea := 0
    
    for li != ri {
        curArea := (ri - li) * min(height[ri], height[li])
        if curArea > maxArea {
            maxArea = curArea
        }
        
        if height[ri] < height[li] {
            ri--
        } else {
            li++
        }
    }
    
    return maxArea
}

func min(x, y int) int {
    if x < y {
        return x
    }
    
    return y
}

/*
func maxArea(height []int) int {
    numHeights := len(height)
    curArea := 0
    maxArea := 0
    
    for i, val := range height {
        for j := numHeights - 1; j > 0; j-- {
            curArea = min(height[j], val) * (j - i)
            if curArea > maxArea {
                maxArea = curArea
            }
        }
    }
    
    return maxArea
}


*/