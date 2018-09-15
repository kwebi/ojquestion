n, k = (int(x) for x in input().strip().split(" "))


class Node:
    def __init__(self, item):
        self.item = item
        self.open = False
        self.child1 = None
        self.child2 = None


def add(node: Node) -> object:
    node.child1 = Node(node.item * 2)
    node.child2 = Node(node.item * 2 + 1)
    return node


def create_tree(n, node):
    if n == 1:
        return
    else:
        node = add(node)
        create_tree(n-1, node.child1)
        create_tree(n-1, node.child2)


def close_open_node(node):
    if node.open == False:
        node.open = True
    else:
        node.open = False
    return node


def change_status(node):
    if node.child1 == None:
        return node.item
    else:
        if node.open == False:
            res = change_status(node.child1)
            node.child1 = close_open_node(node.child1)
            return res
        else:
            res = change_status(node.child2)
            node.child2 = close_open_node(node.child2)
            return res


root = Node(1)
i = 1

create_tree(n, root)
for i in range(k):
    res = change_status(root)
    root = close_open_node(root)
print(res)


