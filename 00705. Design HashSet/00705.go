// https://leetcode.com/problems/design-hashset

type MyHashSet struct {
    set map[int]bool
}

func Constructor() MyHashSet {
    return MyHashSet{
        set: make(map[int]bool),
    }
}

func (this *MyHashSet) Add(key int)  {
    this.set[key] = true
}

func (this *MyHashSet) Remove(key int)  {
    this.set[key] = false
}

func (this *MyHashSet) Contains(key int) bool {
    return this.set[key]
}
