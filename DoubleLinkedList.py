class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # 后继指针
        self.pre = None  # 前驱指针


class DLinkedList:
    def __init__(self):
        self.head = None

    def initList(self, dataList):  # 初始化
        self.head = Node(dataList[0])
        cur = self.head
        preNode = None
        for i in dataList[1:]:
            node = Node(i)
            cur.next = node
            cur.pre = preNode
            preNode = cur
            cur = cur.next
        cur.pre = preNode  # 处理尾节点
        cur.next = None

    def isEmpty(self):
        return self.head is None

    def getLength(self):
        cur = self.head
        length = 0
        while cur:
            length += 1
            cur = cur.next
        return length

    def printList(self):
        cur = self.head
        while cur and cur.data:
            print(cur.data)
            cur = cur.next

    def add(self, value):  # 头部插入元素
        node = Node(value)
        if self.isEmpty():
            self.head = node
        else:
            node.next = self.head
            self.head.pre = node  # 头节点的pre指向node
            self.head = node

    def append(self, value):  # 尾部插入节点
        node = Node(value)
        if self.isEmpty():
            self.head = node
        else:
            cur = self.head
            while cur.next:  # 找到最后一个元素
                cur = cur.next
            cur.next = node
            node.pre = cur

    def search(self, value):
        cur = self.head
        while cur:
            if cur.data == value:
                return True
            cur = cur.next
        return False

    def insert(self, index, value):
        if index <= 0:
            self.add(value)
        elif index >= self.getLength() - 1:
            self.append(value)
        else:
            node = Node(value)
            i = 1
            cur = self.head
            while i < index:
                i += 1
                cur = cur.next
            cur.next.pre = node
            node.next = cur.next
            cur.next = node
            node.pre = cur

    def remove(self, index):
        if self.isEmpty():
            return
        dummyHead = Node(None)  # 处理移除头节点的情况
        dummyHead.next = self.head
        self.head.pre = dummyHead
        cur = dummyHead
        i = 0
        while i < index:
            cur = cur.next
            i += 1
        cur.next.next.pre = cur  # 移除节点
        cur.next = cur.next.next
        self.head = dummyHead.next

    def reverse(self):
        if self.head is None or self.head.next is None:
            return self.head
        cur = self.head
        preNode = None
        while cur:
            nextNode = cur.next
            preNode = cur
            cur.pre, cur.next = cur.next, cur.pre  # 前后指针交换
            cur = nextNode
        self.head = preNode  # 跳过空节点


# test
List = DLinkedList()
data_List = [1, 3, 4, 5, 7]
List.initList(data_List)
List.insert(1, 2)
List.remove(3)
List.reverse()
List.printList()
