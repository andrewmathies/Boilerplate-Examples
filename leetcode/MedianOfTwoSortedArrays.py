# https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        fullList, fullLen = self.combine(nums1, nums2)
        
        middle = fullLen / 2.0
        realMiddle = fullLen // 2
        
        if middle.is_integer():
            return (fullList[realMiddle] + fullList[realMiddle - 1]) / 2
        else:
            return fullList[realMiddle]
        
    def combine(self, l1, l2):
        out = []
        len1 = len(l1)
        len2 = len(l2)
        m = 0
        n = 0
        
        while m < len1 and n < len2:
            if l1[m] <= l2[n]:
                out.append(l1[m])
                m += 1
            else:
                out.append(l2[n])
                n += 1
        
        while m < len1:
            out.append(l1[m])
            m += 1
            
        while n < len2:
            out.append(l2[n])
            n += 1
            
        return out, len1 + len2