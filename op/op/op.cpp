#include <iostream>
#include <stack>
#include <string>

using namespace std;
void fun2(void);

// �ж��Ƿ�Ϊ������
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// ��ȡ���������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// ִ������
int applyOp(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

// ���ʽ��ֵ������
int evaluateExpression(const string& expression) {
    stack<int> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        }
        else if (isOperator(expression[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOp(val1, val2, op));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

void fun2(void) {
    string expression;
    cout << "��������ʽ: ";
    cin >> expression;
    int result = evaluateExpression(expression);
    cout << "���ʽ����ֵ���Ϊ: " << result << endl;
    return;
}

int main()
{
    int choice = 2;
    printf("Enter a number (1 for fun1, 2 for fun2, 3for fun3): ");
    cin >> choice;

    switch (choice) {
    case 1:
        break;
    case 2:
        fun2();
        break;
    case 3:
        break;

    default:
        printf("Invalid choice.\n");
    }
}
