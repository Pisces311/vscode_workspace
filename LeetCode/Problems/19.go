package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	cur := head
	cnt := 0
	for cur != nil {
		cnt += 1
		cur = cur.Next
	}
	if cnt == n {
		return head.Next
	}
	target := cnt - n + 1
	cur = head
	now := 1
	for now != target-1 {
		cur = cur.Next
		now += 1
	}
	cur.Next = cur.Next.Next
	return head
}
