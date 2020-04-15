// https://leetcode.com/problems/longest-palindromic-substring/

func longestPalindrome(s string) string {
    n := len(s)
    
    if n == 0 {
        return ""
    }
    
    runes := []rune(s)
    
    evens := make([]int, 0)
    odds := make([]int, 0)
    
    for i := 0; i < n - 2; i++ {
        if runes[i] == runes[i + 2] {
            odds = append(odds, i)
        }
    }
    
    for i := 0; i < n - 1; i++ {
        if runes[i] == runes[i + 1] {
            evens = append(evens, i)
        }
    }
    
    max := 0
    maxStr := s[0:1]
    
    for _, start := range evens {
        low := start
        high := start + 1
        
        for true {
            if runes[low] != runes[high] {
                low++
                high--
                break
            }
            
            low--
            high++
            
            if low < 0 || high > n - 1 {
                low++
                high--
                break
            }
        }
        
        if high - low > max {
            max = high - low
            maxStr = s[low:high+1]
        }
    }
    
    for _, start := range odds {
        low := start
        high := start + 2
        
        for true {
            if runes[low] != runes[high] {
                low++
                high--
                break
            }
            
            low--
            high++
                        
            if low < 0 || high > n - 1 {
                low++
                high--
                break
            }
        }
        
        if high - low > max {
            max = high - low
            maxStr = s[low:high+1]
        }
    }
    
    return maxStr
}