#include <iostream>
using namespace std;

#define MaxSize 128

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty();  //判断队列是否为空
    bool isFull();  //判断队列是否已满
    void pushElem(T data);  //入队
    T popElem();  //出队
    T getHead();  //队首元素
    int length();  //对列长度
private:
    T* front; //队首指针
    T* rear;  //队尾指针
};

template <typename T>
Queue<T>::Queue() {
    front = new T[MaxSize];
    if (front == nullptr) return;
    rear = front;
}

template <typename T>
Queue<T>::~Queue() {
    if (front) {
        delete front;
        front = nullptr;
        rear = nullptr;
    }
}

template <typename T>
bool Queue<T>::isEmpty() {
    if (front == rear) {
        return true;
    }else {
        return false;
    }
}

template <typename T>
bool Queue<T>::isFull() {
    if (rear - front == MaxSize) {
        return true;
    }else {
        return false;
    }
}

template <typename T>
void Queue<T>::pushElem(T data){
    if (isFull()) {
        cout << "队列已满无法插入元素";
        return;
    }
    *rear = data;
    rear++;
}

template <typename T>
T Queue<T>::popElem() {
    if (isEmpty()) {
        cout << "队列中无元素";
        throw -1;
    }
    T elem = *front;
    for (auto i = front; i < rear - 1; i++) {
        *front = *(front + 1);
    }
    rear--;
    return elem;
}

template <typename T>
T Queue<T>::getHead() {
    if (isEmpty()) {
        cout << "队列中无元素";
        throw -1;
    }
    T elem = *front;
    return elem;
}

template <typename T>
int Queue<T>::length() {
    return rear - front;
}



int main() {
    Queue<int> que;
    int n, temp;
    cout << "请输入入栈的元素个数:"  << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个元素个数" << endl;
        cin >> temp;
        que.pushElem(temp);
    }
    int elem = que.getHead();
    cout << "队首元素为：" << elem << endl;
    elem = que.popElem();
    cout << "出栈元素" << elem << endl;
    elem = que.popElem();
    cout << "出栈元素" << elem << endl;
    cout << "当前栈中元素有： " << que.length() << "个" << endl;
    que.isEmpty()? cout << "当前队列为空" : cout << "当前队列不为空";


    return 0;
}
