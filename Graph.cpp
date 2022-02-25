#include <iostream>
#include <queue>
using namespace std;

#define MaxSize 1024

//定义与节点连接的边
typedef struct EdgeNode {
    int adjVex;  //临接的定点
    struct EdgeNode* next;  //下一条边
}EdgeNode;

//定义节点
typedef struct VertexNode {
    char data;  //节点数据
    struct EdgeNode* first;  //指向节点临接的第一条边
}AdjList;

//定义图
typedef struct AdjListGraph {
    AdjList* adjList;
    int vex;  //顶点数
    int edge;  //边数
}AdjListGraph;

bool visited[MaxSize];  //全局数组，记录节点是否已访问

//图的初始化
void initGraph(AdjListGraph &G) {
    G.adjList = new AdjList[MaxSize];
    G.vex = 0;
    G.edge = 0;
    for (bool & i : visited) {
        i = false;
    }
}

//寻找顶点在图中的邻节点
int location(AdjListGraph &G, char c) {
    for (int i = 0; i < G.edge; i++) {
        if (G.adjList[i].data == c) {
            return i;
        }
    }
    return -1;
}

//创建图
void createGraph(AdjListGraph &G) {
    cout << "请输入图的顶点及边的个数: " <<endl;
    cin >> G.vex >> G.edge;
    cout << "请输入相关的顶点: " <<endl;
    for (int i = 0; i < G.vex; i++) {
        cin >> G.adjList[i].data;
        G.adjList[i].first = nullptr;
    }
    char v1, v2; //保存输入的顶点字符
    int i1, i2;  //保存顶点在数组中的坐标

    cout << "请输入相关联边的顶点: " << endl;
    for (int i = 0; i < G.edge; i++) {
        cin >> v1 >> v2;
        i1 = location(G, v1);
        i2 = location(G, v2);
        if (i1 != -1 && i2 != -1) {
            auto* temp = new EdgeNode;
            temp -> adjVex = i2;
            temp -> next = G.adjList[i1].first;
            G.adjList[i1].first = temp;
        }
    }
}

//对顶点进行深度优先遍历
void dfs(AdjListGraph &G, int v) {
    int next = -1;
    if (visited[v]) return;
    cout << G.adjList[v].data << " ";
    visited[v] = true;
    EdgeNode* temp = G.adjList[v].first;
    while (temp) {
        next = temp->adjVex;
        temp = temp->next;
        if (!visited[next]) {
            dfs(G, next);
        }
    }
}

//对所有节点进行深度优先遍历
void dfsAll(AdjListGraph &G) {
    for (int i = 0; i < G.vex; i++) {
        if (!visited[i]) {
            dfs(G, i);
        }
    }
    for (bool & i : visited) {
        i = false;
    }
}

//对顶点进行广度优先遍历
void bfs(AdjListGraph &G, int v) {
    queue<int> que;
    int cur = -1;
    int index;
    que.push(v);
    while (!que.empty()) {
        cur = que.front();
        if (!visited[cur]) {
            cout << G.adjList[cur].data << " ";
            visited[cur] = true;
        }
        que.pop();
        EdgeNode* temp = G.adjList[cur].first;
        while (temp != nullptr) {
            index = temp -> adjVex;
            temp = temp -> next;
            que.push(index);
        }
    }
}

//对所有节点进行广度优先遍历
void bfsAll(AdjListGraph &G) {
    for (int i = 0; i < G.edge; i++) {
        if (!visited[i]) {
            bfs(G, i);
        }
    }
    for (bool & i : visited) {
        i = false;
    }
}



int main() {
    AdjListGraph G;
    initGraph(G);
    createGraph(G);
    dfsAll(G);
    cout << endl;
    bfsAll(G);
    return 0;
}
