#include <iostream>
#include <string>

using namespace std;

template <typename T>
class LinearList
{
public:
    LinearList(){};
    LinearList(int size) {
        m_size = size;
        elems = new T[size];
        m_length = 0;
    };
    ~LinearList(){
        delete []elems;
    };
    int length();  //获取长度
    int size();  //获取容量
    void pushBack(T x);  //尾部插入
    T& operator [](int x);  //重载【】，使可以访问赋值
    void insertElem(int num, T x);  //特定位置插入元素
    void deleteElem(int num);  //删除元素
    void destroyLinearList();  //销毁顺序表

private:
    T* elems;       //顺序表的基地址
    int m_length;     //长度
    int m_size;   //总空间大小
};

template <typename T>
int LinearList<T>::length() {
    return m_length;
}

template <typename T>
int LinearList<T> :: size() {
    return m_size;
}

template <typename T>
void LinearList<T>::pushBack(T x) {
    if (m_length != m_size) {
        elems[m_length] = x;
        m_length++;
    }
}

template<typename T>
T& LinearList<T>::operator[](int x) {
    if (x >= m_length) {
        throw -1;
    }else {
        return elems[x];
    }

}

template<typename T>
void LinearList<T>::insertElem(int num, T x) {
    if (num >= m_length) {
        throw -1;
    }else {
        m_length++;
        for (int i = m_length - 1; i > num; i--) {
            elems[i] = elems[i - 1];
        }
        elems[num] = x;
    }
}

template<typename T>
void LinearList<T>::deleteElem(int num) {
    if (num > m_length) throw -1;
    if (num == m_length) {
        m_length--;
    }else {
        for (int i = num; i < m_length - 1; i++) {
            elems[i] = elems[i + 1];
        }
        m_length--;
    }
}

template<typename T>
void LinearList<T>::destroyLinearList() {
    delete []elems;
    m_size = 0;
    m_length = 0;
}


int main() {
    LinearList<string> s(20);
    s.pushBack("x");
    s.pushBack("y");
    s.pushBack("z");
    cout << s.size() << " " << s[0] << " " << s.length() << endl;
    s.insertElem(1, "a");
    cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << endl;
    s.deleteElem(1);
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}
