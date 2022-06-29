type Item struct {
    isLeaf bool
}

type Trie struct {
    item interface{}
    children map[rune]*Trie
}

func NewTrie() *Trie {
    return &Trie{
        item: Item{ false },
        children: map[rune]*Trie{},
    }
}

func Constructor() Trie {
    trie := *NewTrie()
    trie.item = Item{ isLeaf: true }
    return trie
}

func (this *Trie) Print() {
    for c, child := range this.children {
        fmt.Printf("c: %c, isLeaf: %v\n", c, child.item.(Item).isLeaf)
        child.Print()
    }
}

func (this *Trie) Insert(word string) {
    node := this
    
    for _, c := range word {
        child, _ := node.children[c]
        
        if child == nil {
            node.children[c] = NewTrie()
        }
        
        node = node.children[c]
    }
    
    node.item = Item{ isLeaf: true }
    /*
    fmt.Printf("\n")
    this.Print()
    */
}

func (this *Trie) Search(word string) bool {
    node := this
    
    for _, c := range word {
        if node == nil {
            return false
        }
        
        node = node.children[c]
    }

    return node != nil && node.item.(Item).isLeaf
}

func (this *Trie) StartsWith(prefix string) bool {
    node := this
    
    for _, c := range prefix {
        if node == nil {
            return false
        }
        
        node = node.children[c]
    }
    
    return node != nil
}
