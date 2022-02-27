class Stack(object):
    def __init__(self, limit=10):
        self.stack = []  # 存放数据
        self.limit = limit  # 栈容量极限

    def push(self, data):
        if len(self.stack) > self.limit:
            print("栈溢出")
            pass
        self.stack.append(data)

    def pop(self):
        if self.stack:
            return self.stack.pop()
        else:
            raise IndexError("空栈不能弹出")

    def peek(self):
        if self.stack:
            return self.stack[-1]
        else:
            print("栈为空")

    def isEmpty(self):
        return not bool(self.stack)

    def size(self):
        return len(self.stack)
