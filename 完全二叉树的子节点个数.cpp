int ret = 0;
void traversal(TreeNode* cur)
{
    if (!cur)
        return;
    ret++;
    traversal(cur->left);
    traversal(cur->right);
}

int countNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;
    traversal(root);
    return ret;
}