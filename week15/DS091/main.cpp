#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input;

    while (true) {
        stack<char> leftStack, rightStack;
        
        getline(cin, input); // 사용자로부터 한 줄 입력을 받음

        if (input == "q") {
            break; // 'q'를 입력하면 프로그램 종료
        }

        for (char ch : input) {
            if (ch == '<') {
                if (!leftStack.empty()) {
                    rightStack.push(leftStack.top());
                    leftStack.pop();
                }
            } else if (ch == '>') {
                if (!rightStack.empty()) {
                    leftStack.push(rightStack.top());
                    rightStack.pop();
                }
            } else {
                leftStack.push(ch); // 알파벳 또는 숫자를 왼쪽 스택에 추가
            }
        }

        // 결과 출력
        string result;
        stack<char> temp = leftStack;
        while (!temp.empty()) {
            result += temp.top();
            temp.pop();
        }
        reverse(result.begin(), result.end());

        temp = rightStack;
        while (!temp.empty()) {
            result += temp.top();
            temp.pop();
        }

        cout << "=> " << result << endl;
    }

    cout << "Bye!" << endl;
    return 0;
}
