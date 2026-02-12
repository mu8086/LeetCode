// https://leetcode.com/problems/lru-cache

type Node struct {
    Key  int
    Val  int
    Prev *Node
    Next *Node
}

// LRUCache combines a Hash Map and a Doubly Linked List to achieve O(1) operations.
type LRUCache struct {
    capacity int
    cache    map[int]*Node
	
    // Dummy head and tail nodes to simplify boundary operations.
    // head.Next points to the most recently used node.
    // tail.Prev points to the least recently used node.
    head *Node
    tail *Node
}

// Constructor initializes the LRU Cache with a specific capacity.
func Constructor(capacity int) LRUCache {
    lru := LRUCache{
        capacity: capacity,
        cache:    make(map[int]*Node),
        head:     &Node{},
        tail:     &Node{},
    }

    // Connect dummy head and tail.
    lru.head.Next = lru.tail
    lru.tail.Prev = lru.head

    return lru
}

// Get returns the value of the key if it exists, otherwise -1.
// If the key exists, it is moved to the head (most recently used).
func (this *LRUCache) Get(key int) int {
    node, exists := this.cache[key]
    if !exists {
        return -1
    }

    // Move the accessed node to the head of the list.
    this.moveToHead(node)

    return node.Val
}

// Put updates the value if the key exists or inserts a new key-value pair.
// If the capacity is exceeded, the least recently used item is evicted.
func (this *LRUCache) Put(key int, value int) {
    if node, exists := this.cache[key]; exists {
        // Update value and mark as recently used.
        node.Val = value
        this.moveToHead(node)
        return
    }

    // Create a new node.
    newNode := &Node{
        Key: key,
        Val: value,
    }

    this.cache[key] = newNode
    this.addToHead(newNode)

    // Check capacity constraints.
    if len(this.cache) > this.capacity {
        this.removeLRUItem()
    }
}

// moveToHead moves an existing node to the front of the list.
func (this *LRUCache) moveToHead(node *Node) {
    this.removeNode(node)
    this.addToHead(node)
}

// addToHead inserts a node right after the dummy head.
func (this *LRUCache) addToHead(node *Node) {
    node.Prev = this.head
    node.Next = this.head.Next

    this.head.Next.Prev = node
    this.head.Next = node
}

// removeNode unlinks a node from the doubly linked list.
func (this *LRUCache) removeNode(node *Node) {
    prev := node.Prev
    next := node.Next

    prev.Next = next
    next.Prev = prev
}

// removeLRUItem removes the element at the tail (least recently used) from both the list and the map.
func (this *LRUCache) removeLRUItem() {
    // tail.Prev is the actual last element.
    res := this.tail.Prev
    this.removeNode(res)
    delete(this.cache, res.Key)
}
