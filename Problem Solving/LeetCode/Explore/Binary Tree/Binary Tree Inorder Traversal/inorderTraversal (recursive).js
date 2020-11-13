/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    const result = [];

    function recurse(node) {
        if (node.left) recurse(node.left);
        result.push(node.val);
        if (node.right) recurse(node.right);
    }

    if (root) recurse(root);
    return result;
};