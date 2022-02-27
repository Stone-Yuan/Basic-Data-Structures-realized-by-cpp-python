class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


# 指针实现
class Queue(object):
    def __init__(self):
        self.head = None  # 头节点
        self.rear = None  # 尾节点

    def isEmpty(self):
        return self.head is None

    def enqueue(self, elem):  # 进队列
        cur = Node(elem)
        if self.isEmpty():
            self.head = cur
            self.rear = cur
        else:
            self.rear.next = cur
            self.rear = self.rear.next

    def dequeue(self):  # 出队列
        if self.isEmpty():
            print("失败！队列为空！")
        else:
            result = self.head.data
            self.head = self.head.next
            return result

    def peek(self):  # 队列最前值
        if self.isEmpty():
            print("失败！队列为空！")
        else:
            return self.head.data

    def printQueue(self):
        myQueue = []
        cur = self.head
        while cur:
            myQueue.append(cur.data)
            cur = cur.next
        print(myQueue)


# test
que = Queue()
que.enqueue(1)
que.enqueue(4)
que.enqueue(5)
que.enqueue(3)
que.dequeue()
que.printQueue()


# 数组实现
class Queue2(object):
    def __init__(self):
        self.entries = []
        self.length = 0
        self.front = 0

    def isEmpty(self):
        return self.length == 0

    def enqueue(self, elem):
        self.entries.append(elem)
        self.length += 1

    def dequeue(self):
        if self.isEmpty():
            print("失败！队列为空！")
        else:
            result = self.entries[self.front]
            self.entries = self.entries[(self.front + 1):]
            self.length -= 1
            return result

    def peek(self):
        if self.isEmpty():
            print("失败！队列为空！")
        else:
            return self.entries[self.front]

    def printQueue(self):
        print(self.entries)


# test
que2 = Queue2()
que2.enqueue(1)
que2.enqueue(4)
que2.enqueue(5)
que2.enqueue(3)
que2.dequeue()
que2.printQueue()