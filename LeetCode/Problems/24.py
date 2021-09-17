from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head):
        dummy = ListNode(0, head)
        cur = dummy
        while cur.next and cur.next.next:
            prev, next = cur.next, cur.next.next
            cur.next = next
            prev.next = next.next
            next.next = prev
            cur = prev
        return dummy.next


sol = Solution()
sol.swapPairs(ListNode(1, ListNode(2, ListNode(3, ListNode(4)))))
