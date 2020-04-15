// https://leetcode.com/problems/valid-parentheses/

func isValid(s string) bool {
    stack := make([]rune, 0)
    
    for _, char := range s {
        if char == '(' || char == '{' || char == '[' {
            stack = append([]rune{char}, stack...)
        } else {
            if len(stack) == 0 {
                return false
            }
            
            first := stack[0]
            //fmt.Println(string(char), string(first))
            
            stack = stack[1:]
            
            if char == ']' && first != '[' {
                return false
            } else if char == ')' && first != '(' {
                return false
            } else if char == '}' && first != '{' {
                return false
            }
        }
    }
    
    return len(stack) == 0
}