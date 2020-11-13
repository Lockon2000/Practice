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
var preorderTraversal = function (root) {
    const result = [];

    function recurse(node) {
        result.push(node.val);
        if (node.left) recurse(node.left);
        if (node.right) recurse(node.right);
    }

    if (root) recurse(root);
    return result;
};

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

const tree = new TreeNode(1, null, new TreeNode(2, new TreeNode(3)))

console.log(preorderTraversal(tree));