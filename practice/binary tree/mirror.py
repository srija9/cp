class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def createNode(val):
    newNode = Node(0)
    newNode.val = val
    newNode.left = None
    newNode.right = None
    return newNode

def inorder(root):
    if(root == None):
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)

def mirrorify(root, mirror):

    if(root == None):
        mirror = None
        return mirror

    mirror = createNode(root.val)
    mirror.right = mirrorify(root.left, ((mirror).right))
    mirror.left = mirrorify(root.right, ((mirror).left))
    return mirror

def mirror(root):
    if root is None:
        return
    mirror(root.left)
    mirror(root.right)
    root.left, root.right = root.right, root.left

if __name__ == '__main__':

    tree = createNode(5)
    tree.left = createNode(3)
    tree.right = createNode(6)
    tree.left.left = createNode(2)
    tree.left.right = createNode(4)

    print("Inorder of original tree: ")
    inorder(tree)
    mirror = None
    mirror = mirrorify(tree, mirror)
    print("\nInorder of mirror tree: ")
    inorder(mirror)