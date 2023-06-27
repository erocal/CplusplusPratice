// 最小公倍數.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//求兩個數的最小公倍數，就可以先求出它們的最大公約數
//然後用上述公式求出它們的最小公倍數。
//例如，求[18，20]，即得[18，20] = 18×20÷（18，20） = 18×20÷2 = 180。

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b != 0)
    {
        return gcd(b, a % b);
    }
        
    return a;
}

int main()
{
    int num1, num2, num3;
    int max,ans;
    cout << "輸入多個數，求最小公倍數 : ";
    cin >>  num1 >> num2 >> num3;
    
    ans = num1*num2/gcd(num1, num2);
    cout << gcd(num1, num2) << endl;
    ans = ans * num3 / gcd(ans, num3);
    

    cout << ans;
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
