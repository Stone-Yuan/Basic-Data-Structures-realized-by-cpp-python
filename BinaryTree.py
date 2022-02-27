class Node(object):
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.val)  # 打印node类时会打印 __str__的返回值


class Tree(object):
    def __init__(self):
        self.root = None

    def add(self, item):
        cur = Node(item)
        if self.root is None:
            self.root = cur
        else:
            q = [self.root]
            while q:
                temp = q.pop()
                if temp.left is None:
                    temp.left = cur
                    return
                elif temp.right is None:
                    temp.right = cur
                    return
                else:
                    q.append(temp.right)
                    q.append(temp.left)

    def getParent(self, item):
        if self.root.val == item:
            return None
        q = [self.root]
        while q:
            temp = q.pop()
            if temp.left and temp.left.val == item:
                return temp
            elif temp.right and temp.right.val == item:
                return temp
            if temp.right:
                q.append(temp.right)
            if temp.left:
                q.append(temp.left)
        return None

    def delete(self, item):
        if self.root is None:
            return False
        parent = self.getParent(item)
        if parent:
            node = parent.left if parent.left.val == item else parent.right  # 待删除节点
            if node.left is None:  # 左子树为空
                if parent.left.val == item:
                    parent.left = node.right
                else:
                    parent.right = node.left
                del node
                return True
            elif node.right is None:  # 右子树为空
                if parent.left.val == item:
                    parent.left = node.left
                else:
                    parent.right = node.right
                del node
                return True
            else:
                tempPre = node
                tempNext = node.right
                if tempNext.left is None:
                    tempPre.right = tempNext.right
                    tempNext.left = node.left
                    tempNext.right = node.right
                else:
                    while tempNext.left:  # 指向右子树最后一个叶子
                        tempPre = tempNext
                        tempNext = tempNext.left
                    tempPre.left = tempNext.right
                    tempNext.left = node.left
                    tempNext.right = node.right
                if parent.left.val == item:
                    parent.left = tempNext
                else:
                    parent.right = tempNext
                del node
                return True
        else:
            return False

    def preOrder(self, node):  # 前序遍历
        if node is None:
            return []
        result = [node.val]
        leftNode = self.preOrder(node.left)
        rightNode = self.preOrder(node.right)
        return result + leftNode + rightNode

    def inOrder(self, node):  # 前序遍历
        if node is None:
            return []
        result = [node.val]
        leftNode = self.inOrder(node.left)
        rightNode = self.inOrder(node.right)
        return leftNode + result + rightNode


# test
T = Tree()
for i in range(2, 10):
    T.add(i)

print(T.preOrder(T.root))
