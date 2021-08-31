package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	addBit := 0
	head := &ListNode{0, nil}
	var tail *ListNode
	for l1 != nil || l2 != nil {
		if tail == nil {
			tail = head
		} else {
			tmp := &ListNode{0, nil}
			tail.Next = tmp
			tail = tmp
		}
		if l1 != nil {
			tail.Val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			tail.Val += l2.Val
			l2 = l2.Next
		}
		tail.Val += addBit
		addBit = 0
		if tail.Val >= 10 {
			tail.Val -= 10
			addBit = 1
		}
	}
	if addBit != 0 {
		tail.Next = &ListNode{1, nil}
	}
	return head
}

func main() {
	l1 := &ListNode{2, &ListNode{4, &ListNode{3, nil}}}
	l2 := &ListNode{5, &ListNode{6, &ListNode{4, nil}}}
	fmt.Println(addTwoNumbers(l1, l2))
}
