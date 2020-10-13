import collections


Node = collections.namedtuple('Node', 'val left right')

# some sample trees having various node counts
tree0 = None  # empty tree
tree1 = Node(5, None, None)
tree2 = Node(7, tree1, None)
tree3 = Node(7, tree1, Node(9, None, None))
tree4 = Node(2, None, tree3)
tree5 = Node(2, Node(1, None, None), tree3)
tree6 = Node(2, Node(1, Node(1, tree5, Node(2, None, tree3)), tree4), Node(2, None, tree3))
tree7 = Node(2, Node(1, Node(1, tree5, Node(2, tree6, tree3)), tree4), Node(2, tree6, tree3))

def flatten(bst):
    # empty case
    if bst is None:
        return []
    # node case
    return flatten(bst.left) + [bst.val] + flatten(bst.right)

def flatten_iter(bst):
    left = []
    parents = []
    def descend_left(bst):
        while bst is not None:
            parents.append(bst)
            bst = bst.left
    descend_left(bst)
    while parents:
        bst = parents.pop()
        left.append(bst.val)
        descend_left(bst.right)
    return left


# tests

def check_flattener(f):
    assert f(tree0) == []
    assert f(tree1) == [5]
    assert f(tree2) == [5, 7]
    assert f(tree3) == [5, 7, 9]
    assert f(tree4) == [2, 5, 7, 9]
    assert f(tree5) == [1, 2, 5, 7, 9]
    print('ok')

# check_flattener(flatten)


# time measurement

import timeit

def recursive():
    flatten(tree7)

def iteretive():
    flatten_iter(tree7)

list(print(func.__name__, timeit.timeit(func, number=1_000_000)) for func in [recursive, iteretive])