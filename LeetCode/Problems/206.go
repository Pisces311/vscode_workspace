package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	var prev *ListNode = nil
	for head.Next != nil {
		tmp := head
		head = head.Next
		tmp.Next = prev
		prev = tmp
	}
	head.Next = prev
	return head
}
