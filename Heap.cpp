#include <iostream>
#include <vector>
using namespace std;

enum heapType {
    MAXHEAP,
    MINHEAP,
};

template <typename T>
class myHeap {
public:
    myHeap(T data[], int len, heapType type);
    myHeap(int capacity, heapType type);  //空堆
    virtual ~myHeap();
    bool push(T data);
    bool pop(int index);
    void print();
    bool isFull(){
        if (_size >= _capacity) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        return _size == 0;
    }
private:
    void _swap(int i , int j);
    void _sink(int index);  //元素下沉
    void _float(int index); //元素上浮
private:
    vector<T> _data;
    int _size;      //元素数量
    int _capacity;  //堆的大小
    heapType _type;
};

template <typename T>
myHeap<T>::myHeap(T data[], int len, heapType type) : _size(0), _capacity(len), _type(type){
    _data.resize(_capacity);
    for (int i = 0; i < len; i++) {
        push(data[i]);
    }
}
//创建空堆
template <typename T>
myHeap<T>::myHeap(int capacity, heapType type) : _size(0), _capacity(capacity), _type(type){
    _data.resize(_capacity);
}

template <typename T>
myHeap<T>::~myHeap() {
    //vector自动析构
}

template <typename T>
bool myHeap<T>::push(T data) {
    if (isFull()) {
        throw ("the heap is full /n");
    }else {
        _data[_size] = data;
        _size++;
        _float(_size);
        //为了更方便计算左节点和右节点的位置
        //将当前位置的数据进行判断上浮（位置从1开始计算）
        //当前节点i,左节点2*i，右节点2*i+1
        return true;
    }
}

template <typename T>
bool myHeap<T>::pop(int index) {
    if (isEmpty()) {
        throw("the heap is empty /n");
    }
    _data[index] = _data[_size - 1];
    _size--;
    _sink(index + 1);
    return true;
}

template <typename T>
void myHeap<T>::print() {
    for (int i = 0; i < _size; i++) {
        cout << _data[i] << " ";
    }
    cout << endl;
}

template <typename T>
void myHeap<T>::_swap(int i, int j) {
    T temp = _data[i];
    _data[i] = _data[j];
    _data[j] = temp;
}

template <typename T>
void myHeap<T>::_sink(int index) {
    int i = index;
    if (_type == MINHEAP) {
        while (i * 2 <= _size) {
            //与左节点比较
            if (_data[i - 1] > _data[i * 2 - 1]) {
                _swap(i - 1, i * 2 - 1);
                //交换后，index位置的节点与右节点比较
                if (i * 2 + 1 <= _size && _data[i - 1] > _data[i * 2]) {
                    _swap(i - 1, i * 2);
                }
                i = i * 2;
            }else if (i * 2 + 1 <= _size && _data[i - 1] > _data[i * 2]) {
                _swap(i - 1, 2 * i);
                i = i * 2 + 1;
            }else {
                break;
            }
        }
    }else if (_type == MAXHEAP) {
        while (i * 2 <= _size) {
            //与左节点比较
            if (_data[i - 1] < _data[i * 2 - 1]) {
                _swap(i - 1, i * 2 - 1);
                //交换后与右节点比较
                if (i * 2 + 1 <= _size && _data[i - 1] < _data[i * 2]) {
                    _swap(i - 1, i * 2);
                }
                i = i * 2;
            }else if (i * 2 + 1 <= _size && _data[i - 1] < _data[i * 2]) {
                _swap(i - 1, i * 2);
                i = i * 2 + 1;
            }else {
                break;
            }
        }
    }
}


template <typename T>
void myHeap<T>::_float(int index) {
    if (_size == 1) return;
    if (_type == MINHEAP) {
        for (int i = index; i > 0; i *= 0.5) {
            //小顶堆的上浮
            if (_data[i - 1] < _data[i * 0.5 - 1]) {
                _swap(i - 1, i * 0.5 - 1);
            }else {
                break;
            }
        }
    }else if (_type == MAXHEAP) {
        for (int i = index; i > 0; i *= 0.5) {
            if (_data[i - 1] > _data[i * 0.5 - 1]){
                _swap(i - 1, i * 0.5 - 1);
            }else {
                break;
            }
        }
    }
}


int main() {
    int minHeapBuffer[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int maxHeapBuffer[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    myHeap<int> minHeap(minHeapBuffer, 10, MINHEAP);
    myHeap<int> maxHeap(maxHeapBuffer, 10, MAXHEAP);
    //小顶堆
    minHeap.print();
    minHeap.pop(2);
    minHeap.print();
    minHeap.push(1);
    minHeap.print();
    //大顶堆
    maxHeap.print();
    maxHeap.pop(0);
    maxHeap.print();
    maxHeap.push(10);
    maxHeap.print();

    return 0;
}
