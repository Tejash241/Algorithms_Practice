# PROBLEM DESCRIPTION: https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        pointer1 = head
        pointer2 = head
        for x in range(0, n):
            pointer2 = pointer2.next
    
        if pointer2 is None:
            return head.next
    
        while pointer2.next is not None:
            pointer1 = pointer1.next
            pointer2 = pointer2.next
        
        pointer1.next = pointer1.next.next
        return head
        