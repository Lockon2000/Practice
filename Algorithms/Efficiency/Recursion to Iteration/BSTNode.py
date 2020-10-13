#!/usr/bin/env python

# This is an exercise relating to the post http://blog.moertel.com/posts/2013-05-11-recursive-to-iterative.html
# Note: it was adapted to python 3

"""Recursion-to-Iteration Exercise 1
There are two recursive calls in find_val_or_next_smaller.
Can you create an equivalent function in which one of the
calls has been replaced by iteration?  (Hint:  Tail calls
are easier to replace.)
Can you create an equivalent function in which *both* of the
calls have been replaced by iteration?
For more information, see:
http://blog.moertel.com/tags/recursion-to-iteration%20series.html
Tom Moertel <tom@moertel.com>
"""

class BSTNode(object):
    """Binary search tree node."""

    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return '(%s, %r, %r)' % (self.val, self.left, self.right)

def find_val_or_next_smaller(bst, x):
    """Get the greatest value <= x in a binary search tree.
    Returns None if no such value can be found.
    """
    if bst is None:
        return None
    elif bst.val == x:
        return x
    elif bst.val > x:
        return find_val_or_next_smaller(bst.left, x)
    else:
        right_best = find_val_or_next_smaller(bst.right, x)
        if right_best is None:
            return bst.val
        return right_best

def find_val_or_next_smaller_iter(bst, x, d=None):
    """Get the greatest value <= x in a binary search tree.
    Returns None if no such value can be found.
    """
    while True:
        if bst is None:
            return d
        elif bst.val == x:
            return x
        elif bst.val > x:
            (bst, x, d) = (bst.left, x, d)
        else:
            (bst, x, d) = (bst.right, x, bst.val)


# tests

import bisect

tree0 = None
tree1 = BSTNode(5)
tree2 = BSTNode(5, BSTNode(3))
tree3 = BSTNode(5, BSTNode(3), BSTNode(9))
tree4 = BSTNode(5, BSTNode(3, BSTNode(1)), BSTNode(9))
tree5 = BSTNode(10, BSTNode(5, BSTNode(3, BSTNode(1, BSTNode(2)))), BSTNode(15, BSTNode(13, BSTNode(11, BSTNode(12)))))

trees = [tree0, tree1, tree2, tree3, tree4, tree5]
tree_vals = [[], [5], [3, 5], [3, 5, 9], [1, 3, 5, 9], [1, 2, 3, 5, 10, 11, 12, 13, 15]]

def test(func):
    for vals, bst in zip(tree_vals, trees):
        for x in range(20):
            y = func(bst, x)
            if y is None:
                assert all(x < z for z in vals)
            else:
                assert y <= x
                if y != x:
                    i = bisect.bisect_right(vals, x)
                    assert all(x < z for z in vals[i:])


test(find_val_or_next_smaller)
test(find_val_or_next_smaller_iter)

list(print(func(tree5, 14)) for func in [find_val_or_next_smaller, find_val_or_next_smaller_iter])


# time measurement

import timeit

def recursive():
    find_val_or_next_smaller(tree5, 12)

def iteretive():
    find_val_or_next_smaller_iter(tree5, 12)

list(print(func.__name__, timeit.timeit(func, number=1_000_000)) for func in [recursive, iteretive])

