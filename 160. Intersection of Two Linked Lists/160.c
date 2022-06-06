struct hash_entry {
    void *key;
    UT_hash_handle hh;
};

struct hash_entry *hash = NULL;

void add_node(struct hash_entry *entry) {
    HASH_ADD_PTR(hash, key, entry);
}

struct hash_entry *find_node(struct ListNode *node) {
    struct hash_entry *ret;
    HASH_FIND_PTR(hash, &node, ret);
    return ret;
}

void delete_all() {
    struct hash_entry *current, *tmp;

    HASH_ITER(hh, hash, current, tmp) {
        HASH_DEL(hash, current);
        free(current);
    }
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    while (headA != NULL) {
        struct hash_entry *entry = (struct hash_entry *) malloc(sizeof(struct hash_entry));
        entry->key = headA;
        add_node(entry);
        headA = headA->next;
    }
    
    while (headB != NULL) {
        if (find_node(headB) != NULL) {
            delete_all();
            return headB;
        }
        headB = headB->next;
    }

    delete_all();
    return NULL;
}
