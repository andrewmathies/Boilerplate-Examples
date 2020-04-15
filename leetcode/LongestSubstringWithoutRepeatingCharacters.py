# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxVal = 0
        cur = ''
        
        for char in s:
            if char  in cur:
                index = 0
                for letter in cur:
                    index += 1
                    if char == letter:
                        break
                cur = cur[index:]
            cur += char
            
            if len(cur) > maxVal:
                maxVal = len(cur)
        
        return maxVal