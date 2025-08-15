// inorder traversal for binary tree
class BSTIterator {
public:
    stack<TreeNode*>stk;
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        int val = stk.top()->val;
        TreeNode* node = stk.top()->right;
        stk.pop();
        while (node) {
            stk.push(node);
            node = node->left;
        }
        return val;
    }

    bool hasNext() {
        return stk.size();
    }
};