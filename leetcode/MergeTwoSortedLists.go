/**
 * https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    root := &ListNode{}
    cur := root
    
    if l1 == nil && l2 == nil {
        return nil
    }
    
    //fmt.Println(cur.Next == nil)
    
    for {
        //fmt.Println(cur, l1, l2)
        
        if l1 == nil  {
            cur.Val = l2.Val
            l2 = l2.Next
        } else if l2 == nil {
            cur.Val = l1.Val
            l1 = l1.Next
        } else if l1.Val <= l2.Val {
            cur.Val = l1.Val
            l1 = l1.Next
        } else if l2.Val <= l1.Val {
            cur.Val = l2.Val
            l2 = l2.Next
        }
        
        if l1 == nil && l2 == nil {
            return root
        }
        
        cur.Next = &ListNode{}
        cur = cur.Next
    }   
}