class Heap(object):
    def __init__(self):
        self.dataList = []  # 使用数组储存堆元素

    def getParent(self, index):
        if index <= 0 or index > len(self.dataList) - 1:
            return None
        else:
            return (index - 1) >> 1

    def swap(self, indexA, indexB):
        self.dataList[indexA], self.dataList[indexB] = self.dataList[indexB], self.dataList[indexA]

    def insert(self, data):
        # 大顶堆
        # 先把元素放在最后，从后到前依次堆化
        self.dataList.append(data)
        index = len(self.dataList) - 1
        parent = self.getParent(index)
        # 循环，直到该元素成为堆顶或小于父节点
        while parent is not None and self.dataList[parent] < self.dataList[index]:
            # 交换
            self.swap(parent, index)
            index = parent
            parent = self.getParent(parent)

    def removeMax(self):
        # 删除堆顶元素，将最后一个元素置于堆顶，从上到下堆化
        removed = self.dataList[0]
        self.dataList[0] = self.dataList[-1]
        del self.dataList[-1]
        # 堆化
        self.heapify(0)
        return removed

    def heapify(self, index):
        # 从上向下堆化，大定堆
        total = len(self.dataList) - 1
        while True:
            maxValueIndex = index
            if 2 * index + 1 <= total and self.dataList[2 * index + 1] > self.dataList[maxValueIndex]:
                maxValueIndex = 2 * index + 1
            if 2 * index + 2 <= total and self.dataList[2 * index + 2] > self.dataList[maxValueIndex]:
                maxValueIndex = 2 * index + 2
            if maxValueIndex == index:
                break
            self.swap(maxValueIndex, index)
            index = maxValueIndex


# test
myHeap = Heap()
for i in range(1, 11):
    myHeap.insert(i)
print(myHeap.dataList)
print([myHeap.removeMax() for _ in range(10)])
