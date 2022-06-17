#define THREE   0   // camera top
#define TWO     2   // camera
#define ONE     1   // camera bottom

static inline int getType(int val) {
    return (val != 0) ? val % 3 : 0;
}

static inline int getCamera(int val) {
    return (val + 1) / 3;
}

int _minCameraCover(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left, right, lType, rType;
        
        left    = _minCameraCover(root->left);
        right   = _minCameraCover(root->right);
        
        lType = getType(left);
        rType = getType(right);
        
        if (lType == ONE || rType == ONE) {
            root->val = (getCamera(left) + getCamera(right)) * 3 + TWO;
        } else if (lType == TWO || rType == TWO) {
            root->val = (getCamera(left) + getCamera(right)) * 3 + THREE;
        } else {
            root->val = (getCamera(left) + getCamera(right)) * 3 + ONE;
        }
    }
    
    return root->val;
}

int minCameraCover(struct TreeNode* root) {
    int rootVal = _minCameraCover(root);
    return (getType(rootVal) == ONE) ? getCamera(rootVal)+1 : getCamera(rootVal);
}
