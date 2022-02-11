#include <iostream>
using namespace std;

typedef struct LinkedNode {
    int data;
    struct LinkedNode* next;
}LinkedNode, LinkedList;

//初始化
bool initList(LinkedList* &L){
    L = new LinkedNode;
    if (!L) return false;
    L -> next = nullptr;
    return true;
}
//前插法
bool pushFront(LinkedList* &L, LinkedNode* node) {
    if (!L || !node) return false;
    node -> next = L -> next;
    L -> next = node;
    return true;
}
//后插法
bool pushBack(LinkedList* &L, LinkedNode* node) {
    if (!L || !node) return false;
    LinkedNode* last = L -> next;
    while (last -> next) {
        last = last -> next;
    }
    last -> next = node;
    node -> next = nullptr;
    return true;
}
//任意位置插入
template <typename T>
bool listInsert(LinkedList* &L, int target, T &val) {
    if (!L) return false;
    LinkedNode* cur = L;
    int i = 0;
    while (cur && i != target - 1) {
        cur = cur -> next;
        i++;
    }
    if (!cur || i > target - 1) return false;
    //生成新节点
    auto temp = new LinkedNode;
    temp -> data = val;
    temp -> next = cur -> next;
    cur -> next = temp;
    delete temp;
    return true;
}
//打印
void printList(LinkedList* &L) {
    LinkedNode* cur = L -> next;
    if (!L) {
        cout << "链表为空";
        return;
    }
    while (cur) {
        cout << cur -> data << "\t";
        cur = cur -> next;
    }
    cout << endl;
}
//取出位置为target的元素
template <typename T>
T getElem(LinkedList* &L, int target) {
    if (!L || !L->next) return false;
    int i = 1;
    LinkedNode* cur = L -> next;
    while (cur && i < target) {
        cur = cur -> next;
        i++;
    }
    if (!cur || i > target) return false;
    return cur -> data;
}
//查找元素
template <typename T>
bool findNode(LinkedList* &L, T val) {
    if (!L) return false;
    LinkedNode* cur = L -> next;
    while (cur && (cur -> data != val)) {
        cur = cur -> next;
    }
    if (!cur) return false;
    return true;
}
//删除元素
bool deleteNode(LinkedList* &L, int target) {
    if (!L) return false;
    int i = 0;
    LinkedNode* cur = L;
    while (cur && i < target - 1) {
        cur = cur -> next;
        i++;
    }
    if (!cur -> next || i > target - 1) return false;
    cur -> next = cur -> next -> next;
    return true;
}
//单链表销毁
void destroyLink(LinkedList* &L) {
    LinkedNode* cur = L;
    while (cur) {
        L = L -> next;
        delete cur;
        cur = L;
    }
}



int main() {
    LinkedList* L = nullptr;
    LinkedNode* s;
    //初始化
    initList(L);
    //头插法插入
    int n = 0;
    cout << "请输入要插入元素的个数" << endl;
    cin >> n;
    cout << "请依次输入" << n << "个元素"<< endl;
    while (n > 0) {
        s = new LinkedNode;
        cin >> s -> data;
        pushFront(L, s);
        n--;
    }
    printList(L);

    //尾插法插入
    cout << "请输入要插入元素的个数" << endl;
    cin >> n;
    cout << "请依次输入" << n << "个元素"<< endl;
    while (n > 0) {
        s = new LinkedNode;
        cin >> s -> data;
        pushBack(L, s);
        n--;
    }
    printList(L);

    //任意位置插入
    int value = 0;
    cout << "请输入要插入元素的位置" << endl;
    cin >> n;
    cout << "请输入要插入元素的值"<< endl;
    cin >> value;
    listInsert(L, n, value);
    printList(L);

    //取出元素
    cout << "请输入要取出元素的位置" << endl;
    cin >> n;
    int a = 0;
    a = getElem<int>(L, n);
    cout <<"第" << n << "个元素的值为"<< a << endl;

    //删除元素
    cout << "请输入要删除元素的位置" << endl;
    cin >> n;
    deleteNode(L, n);
    printList(L);

    //查找元素
    cout << "请输入要查找的元素" << endl;
    cin >> a;
    findNode(L, a) ? cout << "元素存在" << endl : cout << "元素不存在" << endl;


    //销毁链表
    destroyLink(L);


    return 0;
}
