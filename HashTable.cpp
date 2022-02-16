#include <iostream>
using namespace std;

#define NULL_KEY -327168

//哈希表的简单实现，
//key使用int类型

template <typename T>
class HashTable {
public:
    HashTable(): _elem(nullptr), _count(0){};
    ~HashTable()= default;
    int init(int tableSize);
    int Hash(int key);
    int searchElem(int key);
    void insertElem(int key);
private:
    T* _elem;    //元素指针数组
    int _count;  //元素个数
};

template <typename T>
int HashTable<T>::init(int tableSize) {
    _count = tableSize;
    _elem = new T[tableSize];
    if (_elem == nullptr) {
        cout << "空间分配失败";
        return -1;
    }
    for (int i = 0; i < tableSize; i++) {
        _elem[i] = NULL_KEY;
    }
    return 1;
}

template <typename T>
int HashTable<T>::Hash(int key) {
    return key % _count;
}

template <typename T>
int HashTable<T>::searchElem(int key) {
    int addr = NULL_KEY;
    addr = Hash(key);
    while (_elem[addr] != key) {
        addr = Hash(addr + 1);
        if (addr == NULL_KEY || addr == Hash(key)) { //地址为空或回到原点
            cout << "元素不在哈希表中";
            return -1;
        }
    }
    return addr;
}

template <typename T>
void HashTable<T>::insertElem(int key) {
    int addr;
    addr = Hash(key);
    while (_elem[addr] != NULL_KEY) {
        addr = Hash(addr + 1);
    }
    _elem[addr] = key;
}


int main() {
    HashTable<int> hashTable;
    int size = 12;
    hashTable.init(size);
    for (int i = 0; i < size; i++) {
        int key = i * 3 + 5;
        hashTable.insertElem(key);
        cout << key << " ";
    }
    cout << endl;

    int addr = hashTable.searchElem(17);
    if (addr == -1) {
        cout << "找不到元素";
    }else {
        cout << "元素位置在" << addr;
    }
    return 0;
}
