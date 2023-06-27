// 二元樹+中序排列.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

// 定義二元樹的節點
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// 插入節點
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// 搜尋節點
Node* searchNode(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// 刪除節點
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // 找到要刪除的節點
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 有兩個子節點的情況
        Node* minValueNode = root->right;
        while (minValueNode->left != nullptr) {
            minValueNode = minValueNode->left;
        }

        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }

    return root;
}

// 中序遍歷（左->根->右）
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// 前序遍歷（根->左->右）
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 後序遍歷（左->右->根）
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int times,i = 0;
    // 先輸入字串大小，不然會Runtime error
    cin >> times;
    vector<int> num(times);
    
    
    while (times--)
    {
        cin >> num[i];
        root = insertNode(root, num[i]);
        i++;
    }
    
    
    /* 這是字串測試輸入的內容
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);*/

    cout << "中序遍歷結果：";
    inorderTraversal(root);
    cout << endl;

    int data = 60;
    Node* searchResult = searchNode(root, data);
    if (searchResult != nullptr) {
        cout << data << " 存在於二元樹中。" << endl;
    }
    else {
        cout << data << " 不存在於二元樹中。" << endl;
    }

    data = 30;
    root = deleteNode(root, data);
    cout << "刪除節點 " << data << " 後的中序遍歷結果：";
    inorderTraversal(root);
    cout << endl;

    cout << "前序遍歷結果：";
    preorderTraversal(root);
    cout << endl;

    cout << "後序遍歷結果：";
    postorderTraversal(root);
    cout << endl;

    return 0;
}



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
