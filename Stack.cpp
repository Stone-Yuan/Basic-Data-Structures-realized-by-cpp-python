#include <iostream>
using namespace std;

#define MaxSize 128

//typedef struct Stack{
//    int* base; //栈底指针
//    int* top;  //栈顶指针
//}Stack;
template <typename T>
class Stack {
public:
    Stack(){
        base = new T[MaxSize]; //分配最大容量为maxsize的空间
        if (!base) {
            return;
        }
        top = base;  //top和base指向同一地址，空栈
    }
    ~Stack(){
        if (base) {
            delete base;
            base = nullptr;
            top = nullptr;
        }
    }
    //入栈
    bool pushStack(T elem){
        if (top - base == MaxSize) {
            return false;
        }
        *(top++) = elem;  //元素压入栈顶，指针+1
        return true;
    }
    //出栈
    T popStack(){
        if (top == base) return false;
        return *(--top);
    }
    //判断栈是否为空
    bool isEmpty(){
        if (top == base){
            return true;
        }else {
            return false;
        }
    }
    //栈的大小
    int getSize() {
        return top - base;
    }

private:
    T* base;  //栈底指针
    T* top;  //栈顶指针
};


int main() {
    Stack<int> stk;
    int n, temp;
    cout << "请输入入栈的元素个数:"  << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个元素个数" << endl;
        cin >> temp;
        stk.pushStack(temp);
    }
    int elem = stk.popStack();
    cout << "出栈元素为：" << elem << endl;
    cout << "当前栈中元素有： " << stk.getSize() << endl;
    stk.isEmpty()? cout << "当前栈为空" : cout << "当前栈不为空";

    return 0;
}
