// https://leetcode.com/problems/happy-number/

func isHappy(n int) bool {
    seen := make(map[int]bool)
    
    for {
        digits := strconv.Itoa(n)
        sum := 0
        
        //fmt.Println(n, seen)
        
        if _, in := seen[n]; in {
            return false
        }
        
        seen[n] = true
        
        for _, digit := range digits {
            realDigit, _ := strconv.Atoi(string(digit)) 
            sum += realDigit * realDigit
        }
    
        if sum == 1 {
            return true
        }
        
        n = sum
    }
    
    return false
}