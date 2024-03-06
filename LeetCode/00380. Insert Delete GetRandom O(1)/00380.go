// https://leetcode.com/problems/insert-delete-getrandom-o1

type RandomizedSet struct {
    slice []int
    m map[int]bool
}

func Constructor() RandomizedSet {
    return RandomizedSet{
        slice: make([]int, 0, 0),
        m: make(map[int]bool),
    }
}

func (this *RandomizedSet) Insert(val int) bool {
    present := this.m[val]
    this.m[val] = true
    if !present {
        this.slice = append(this.slice, val)
        return true
    }
    return false
}

func (this *RandomizedSet) Remove(val int) bool {
    if present := this.m[val]; present {
        for idx, v := range this.slice {
            if v == val {
                this.m[val] = false
                this.slice = append(this.slice[:idx], this.slice[idx+1:]...)
                return true
            }
        }
    }
    return false
}

func (this *RandomizedSet) GetRandom() int {
    return this.slice[rand.Intn(len(this.slice))]
}
