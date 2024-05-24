int traversal(TreeNode* cur, int depth)
{
    if (!cur)
        return depth;
    int left_depth = traversal(cur->left, depth + 1);
    int right_depth = traversal(cur->right, depth + 1);
    if (left_depth == -1 || right_depth == -1)
        return -1;
    if (left_depth > right_depth + 1 || left_depth < right_depth - 1)
        return -1;
    return max(left_depth, right_depth);
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;
    int result = traversal(root, 1);
    return result == -1 ? false : true;
}