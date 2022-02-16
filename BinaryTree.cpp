#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;


template <typename T>
struct TreeNode {
    T val;
    TreeNode<T> *left, *right;
    explicit TreeNode(T x, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr) : val(x), left(l), right(r){};
};

template <typename T>
class BinaryTree {
public:
    BinaryTree(): root(nullptr){};
    ~BinaryTree(){
        destroy(root);
    }
    //按照节点有序性插入节点，左<中<右
    void insertNode(TreeNode<T>* node, T value) {
        auto* temp = new TreeNode<T>(value, nullptr, nullptr);
        if (node == nullptr) {
            node = temp;
            return;
        }
        TreeNode<T>* pre = node;
        while (true) {
            if (pre -> val >= value) {
                if (pre -> left == nullptr) {
                    pre -> left = temp;
                    return;
                }
                pre = pre -> left;
            }else {
                if (pre -> right == nullptr) {
                    pre -> right = temp;
                    return;
                }
                pre = pre -> right;
            }
        }
    }
    //使用前序和中序遍历得到二叉树
    void creatBTree_by_Pre_In(TreeNode<T>* cur, const char* pre, const char* in, int n) {
        if (n <= 0) {
            cur = nullptr;
            return;
        }
        int k = 0;
        while (pre[0] != in[k]) { //在中序中找到根结点
            k++;
        }
        cur = new TreeNode<T>(in[k]);
        creatBTree_by_Pre_In(cur -> left, pre + 1, in, k);
        creatBTree_by_Pre_In(cur -> right, pre + k + 1, in + k + 1, n - k - 1);
    }
    //使用后序和中序遍历得到二叉树
    void creatBTree_by_Post_In(TreeNode<T>* cur, const char* post, const char* in, int n) {
        if (n <= 0) {
            cur = nullptr;
            return;
        }
        char r = *(post + n - 1); //根节点值
        cur = new TreeNode<T>(r); //构造当前节点
        int k = 0;
        const char* p = in;
        while (*p != r){
            k++;
            p++;
        }
        creatBTree_by_Post_In(cur -> left, post, in, k);
        creatBTree_by_Post_In(cur -> left, post + k, p + 1, n - k - 1);
    }
    //递归前序遍历
    void preOrder(TreeNode<T>* node){
        if (node != nullptr) {
            cout << node -> val << " ";
            preOrder(node -> left);
            preOrder(node -> right);
        }
    }
    //递归中序遍历
    void inOrder(TreeNode<T>* node){
        if (node != nullptr) {
            preOrder(node -> left);
            cout << node -> val << " ";
            preOrder(node -> right);
        }
    }
    //递归后序遍历
    void postOrder(TreeNode<T>* node){
        if (node != nullptr) {
            preOrder(node -> left);
            preOrder(node -> right);
            cout << node -> val << " ";
        }
    }
    //迭代前序遍历
    void preOrder_nonRecurse(TreeNode<T>* node) {
        if (node == nullptr) return;
        stack<TreeNode<T>*> stk;
        stk.push(node);
        while (!stk.empty()) {
            TreeNode<T>* cur = stk.top();
            if (cur != nullptr) {
                stk.pop();
                if (cur -> right) stk.push(cur -> right);
                if (cur -> left) stk.push(cur -> left);
                stk.push(cur);
                stk.push(nullptr);
            }else {
                stk.pop();
                node = stk.top();
                stk.pop();
                cout << cur -> val << " ";
            }
        }
        cout << endl;
    }
    //迭代中续遍历
    void inOrder_nonRecurse(TreeNode<T>* node) {
        if (node == nullptr) return;
        stack<TreeNode<T>*> stk;
        stk.push(node);
        while (!stk.empty()) {
            TreeNode<T>* cur = stk.top();
            if (cur != nullptr) {
                stk.pop();
                if (cur -> right) stk.push(cur -> right);
                stk.push(cur);
                stk.push(nullptr);
                if (cur -> left) stk.push(cur -> left);
            }else {
                stk.pop();
                cur = stk.top();
                stk.pop();
                cout << cur -> val << " ";
            }
        }
    }
    //迭代后续遍历
    void postOrder_nonRecurse(TreeNode<T>* node) {
        if (node == nullptr) return;
        stack<TreeNode<T>*> stk;
        stk.push(node);
        while (!stk.empty()) {
            TreeNode<T>* cur = stk.top();
            if (cur != nullptr) {
                stk.pop();
                stk.push(cur);
                stk.push(nullptr);
                if (cur -> right) stk.push(cur -> right);
                if (cur -> left) stk.push(cur -> left);
            }else {
                stk.pop();
                cur = stk.top();
                stk.pop();
                cout << cur -> val << " ";
            }
        }
    }
    //层序遍历
    void levelOrder(TreeNode<T>* node) {
        if (node == nullptr) return;
        queue<TreeNode<T>*> que;
        que.push(node);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode<T>* cur = que.front();
                que.pop();
                cout << node -> val << " ";
                if (cur -> left) que.push(cur -> left);
                if (cur -> right) que.push(cur -> left);
            }
        }
        cout << endl;
    }
    //二叉树节点个数
    int nodeNum(TreeNode<T>* node) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + nodeNum(node -> left) + nodeNum(node -> left);
    }
    //二叉树高度
    int treeHeight(TreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        int i = treeHeight(node -> left);
        int j = treeHeight(node -> right);
        return i < j ? j + 1 : i + 1;
    }
    //寻找当前节点的父节点，返回父节点的地址
    TreeNode<T> findParent(TreeNode<T>* node, TreeNode<T>* cur) {
        if (node == nullptr) return nullptr;
        if (node -> left == cur || node -> right == cur) {
            return node;
        }
        if (findParent(node -> left, cur) != nullptr) {
            return findParent(node -> left, cur);
        }else{
            return findParent(node -> right, cur);
        }
    }
    //判断两颗二叉树是否相等
    bool isEqual(TreeNode<T>* a, TreeNode<T>* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a != nullptr && b != nullptr && a -> val == b -> val && isEqual(a -> left, b -> left) && isEqual(a -> right, b -> right)) {
            return true;
        }
        return false;
    }
    void destroy(TreeNode<T>* node){
        if (node != nullptr) {
            destroy(node -> left);
            destroy(node -> right);
            delete node;
        }
    }
private:
    TreeNode<T>* root;
};

int main() {
    int test[] = {18, 7, 24, 2, 15, 12, 43, 26};
    TreeNode<int>* root = nullptr;
    auto* node = new TreeNode<int>(test[0], nullptr, nullptr);
    BinaryTree<int> bTree;
    bTree.insertNode(root, node -> val);
    for (int i = 1; i < sizeof(test) / sizeof(test[0]); i++) {
        node -> val = test[i];
        bTree.insertNode(root, node -> val);
    }

    bTree.preOrder(root);

    return 0;
}