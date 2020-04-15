# https://leetcode.com/problems/license-key-formatting/

class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        initParts = S.split('-')
        intermediate = []
        
        for part in initParts:
            for char in part:
                if char.islower():
                    char = char.capitalize()
                intermediate.append(char)
        
        interLen = len(intermediate)
        firstK = interLen % K
        if not firstK:
            firstK = K
        
        counter = 0
        
        origIndexes = []
        for i in range(firstK, interLen, K):
            origIndexes.append(i)
        
        for i in origIndexes:
            intermediate.insert(i + counter, '-')
            counter += 1
        
        return ''.join(intermediate)
        
        