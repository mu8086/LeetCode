// https://leetcode.com/problems/reorder-list

func reorderList(head *ListNode)  {
    slice := make([]*ListNode, 0, 0)

    for h := head; h != nil; h = h.Next {
        slice = append(slice, h)
    }

    size := len(slice)
    half := (size >> 1)

    for i := 0; i < half; i++ {
        slice[i].Next = slice[size-i-1]
        slice[size-i-1].Next = slice[i+1]
    }
    slice[half].Next = nil
}
