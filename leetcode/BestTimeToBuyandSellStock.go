// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
func maxProfit(prices []int) int {
    if len(prices) < 2 {
        return 0
    }
    
    max := 0
    
    for i := 1; i < len(prices); i++ {        
        for j := 0; j < i; j++ {   
            //fmt.Println(i, j, prices[i], "-", prices[j], "=", prices[i] - prices[j])
            
            if prices[i] - prices[j] > max {
                max = prices[i] - prices[j]
            }
        }
    }
    
    if max < 0 {
        return 0
    }
    
   return max
}
*/

func maxProfit(prices []int) int {
    min := int(^uint(0) >> 1)
    max := 0
    
    for i := 0; i < len(prices); i++ {
        if prices[i] < min {
            min = prices[i]
        }
        
        if prices[i] - min > max {
            max = prices[i] - min
        }
    }
    
    return max
}


//[3,3,5,0,0,3,1,4]