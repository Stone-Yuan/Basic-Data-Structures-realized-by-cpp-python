# 无向图
class Graph(object):
    def __init__(self):
        self.nodes = []  # 图的点集
        self.edges = {}  # 图的边集

    def insert(self, a, b):
        if a not in self.nodes:  # 如果a不在图集里，添加a
            self.nodes.append(a)
            self.edges[a] = list()
        if b not in self.nodes:
            self.nodes.append(b)
            self.edges[b] = list()
        self.edges[a].append(b)  # a链接b
        self.edges[b].append(a)  # b链接a

    def linked(self, a):
        return self.edges[a]  # 返回与a链接的点

    def showNodes(self):
        return self.nodes

    def showEdges(self):
        return self.edges

