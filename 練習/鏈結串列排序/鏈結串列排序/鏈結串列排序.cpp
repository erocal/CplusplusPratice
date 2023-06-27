// 鏈結串列排序.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

// 鏈結串列的節點結構
struct Node {
    int data;
    Node* next;
};

// 函數：插入新節點到排序的鏈結串列
void insert(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // 空串列或新節點值小於頭節點
    if (*head == nullptr || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* curr = *head;

        // 尋找正確插入位置
        while (curr->next != nullptr && curr->next->data < value) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// 函數：印出鏈結串列內容
void printList(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}

int main() {
    Node* head = nullptr;
    int num;

    cout << "請輸入數字 (-1 結束輸入): ";

    while (cin >> num && num != -1) {
        insert(&head, num);
        printList(head);
        cout << "請輸入數字 (-1 結束輸入): ";
    }

    // 釋放動態配置的記憶體
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

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
