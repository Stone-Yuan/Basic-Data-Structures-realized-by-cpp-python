class Node:
    def __init__(self, data):
        self.data = data  # 元素值
        self.next = None  # 下一个节点


class LinkedList:
    def __init__(self):
        self.head = None

    def initList(self, dataList):
        self.head = Node(dataList[0])  # 头节点
        temp = self.head
        for i in dataList[1:]:
            node = Node(i)  # 逐个为dataList内的元素创建节点
            temp.next = node
            temp = temp.next

    def isEmpty(self):
        return self.head is None

    def insert(self, index, value):
        if index < 0 or index > self.getLength() - 1:
            print("插入失败")
        dummyNode = Node(None)  # 虚构一个dummyNode处理在头节点插入节点的情况
        dummyNode.next = self.head
        cur = dummyNode  # 从dummyNode开始
        i = 0
        while i < index:  # 找到插入点index前一个位置
            cur = cur.next
            i += 1
        node = Node(value)
        node.next = cur.next
        cur.next = node
        self.head = dummyNode.next  #

    def getLength(self):
        temp = self.head
        length = 0
        while temp is not None:
            temp = temp.next
            length += 1
        return length

    def remove(self, index):
        if index < 0 or index > self.getLength() - 1:
            print("移除失败")
        dummyNode = Node(None)
        dummyNode.next = self.head
        cur = dummyNode
        i = 0
        while i < index:
            cur = cur.next
            i += 1
        cur.next = cur.next.next
        self.head = dummyNode.next

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data)
            temp = temp.next

    def reverse(self):
        pre = None
        cur = self.head
        while cur:
            nextNode = cur.next
            cur.next = pre
            pre = cur
            cur = nextNode
        self.head = pre

# test
# List = LinkedList()
# data_List = [1, 3, 4, 5, 7]
# List.initList(data_List)
# List.reverse()
# List.insert(1, 2)
# List.remove(3)
# List.printList()
