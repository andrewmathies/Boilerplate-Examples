# https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        answer = self.convert(l1, 0) + self.convert(l2, 0)
        return self.revert(answer)
        
    def convert(self, listnode, order):
        if not listnode:
            return 0
        
        return (listnode.val * pow(10, order)) + self.convert(listnode.next, order + 1)
    
    def revert(self, num):
        root = None
        
        if num == 0:
            return ListNode(0)
        
        while num > 0:
            val = int(num % 10)
            num = int(num // 10)
            temp = ListNode(val)
            
            if root == None:
                root = temp
            else:
                cur = root
                while cur.next:
                    cur = cur.next
                cur.next = temp
            
        return root
        