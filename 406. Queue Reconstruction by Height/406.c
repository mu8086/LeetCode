#define MAX_PEOPLE_SIZE 2000

typedef struct _Node {
    struct _Node *l;
    struct _Node *r;
    int h;
    int k;
} Node;

int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa, *b = *(int **)bb;
    
    if (a[1] == b[1]) {
        return a[0] - b[0];
    }
    return a[1] - b[1];
}

int * getReturnColumnSizes(int row, int colVal) {
    int *ret = (int *) malloc(sizeof(int) * row);
    
    for (int i = 0; i < row; ++i) {
        ret[i] = colVal;
    }
    
    return ret;
}

Node * newNode(int mode) {
    static int index, allocateSize = sizeof(Node) * MAX_PEOPLE_SIZE;
    static Node allocate[MAX_PEOPLE_SIZE] = {};
    
    if (mode == 1) {
        return &allocate[index++];
    } else {
        index = 0;
        memset(allocate, 0, allocateSize);
        return NULL;
    }
}

void freeNode(Node *root) {
    newNode(-1);
}

Node * insertNode(Node *root, int h, int k, int *counter) {
    Node *ret = NULL;
    
    if (root == NULL) {
        if (*counter == 0) {
            ret = newNode(1);
            *ret = (Node){ .l = NULL, .r = NULL, .h = h, .k = k};
            return ret;
        } else {
            return root;
        }
    }
    
    if (root->h < h) {
        root->r = insertNode(root->r, h, k, counter);
    } else {
        if (*counter == 0) { // normal case
            root->l = insertNode(root->l, h, k, counter);
        } else if (*counter > 0) { // inorderInsert
            root->l = insertNode(root->l, h, k, counter);
            if (*counter > 0) {
                --(*counter);
                root->r = insertNode(root->r, h, k, counter);
            }
        }
    }
    
    return root;
}

void inorderSet(Node *root, int **people, int *returnSize) {
    if (root != NULL) {
        if (root->l != NULL) {
            inorderSet(root->l, people, returnSize);
        }
        
        people[*returnSize][0] = root->h;
        people[*returnSize][1] = root->k;
        ++(*returnSize);
        
        if (root->r != NULL) {
            inorderSet(root->r, people, returnSize);
        }
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    qsort(people, peopleSize, sizeof(int *), compare);
    
    int i, counter;
    Node *root = NULL;
    
    for (i = 0; i < peopleSize; ++i) {
        counter = people[i][1];
        root = insertNode(root, people[i][0], people[i][1], &counter);
    }
    
    *returnSize = 0;
    inorderSet(root, people, returnSize);

    *returnColumnSizes = getReturnColumnSizes(peopleSize, 2);
    freeNode(root);
    return people;
}
