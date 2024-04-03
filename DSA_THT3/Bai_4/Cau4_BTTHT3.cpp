#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// Hàm kiểm tra mức ưu tiên của toán tử
int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == 'd') {
        return 3;
    }
    else {
        return 4;
    }
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
string infix_to_postfix(string expr) {
    stack<char> stk;
    string postfix = "";
    for (int i = 0; i < expr.length(); i++) {
        char token = expr[i];
        if (isdigit(token)) {
            postfix += token;
            while (isdigit(expr[i + 1])) {
                postfix += expr[i + 1];
                i++;
            }
            postfix += " ";
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == 'd') {
            while (!stk.empty() && priority(token) <= priority(stk.top())) {
                postfix += stk.top();
                postfix += " ";
                stk.pop();
            }
            stk.push(token);
        }
        else if (token == '(') {
            stk.push(token);
        }
        else if (token == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                postfix += " ";
                stk.pop();
            }
            stk.pop();
        }
        else if (token == 's' || token == 'c' || token == 't' || token == 'l' || token == 'e') {
            if (token == 's' && expr[i + 1] == 'i' && expr[i + 2] == 'n') {
                postfix += "sin ";
                i += 2;
            }
            else if (token == 'c' && expr[i + 1] == 'o' && expr[i + 2] == 's') {
                postfix += "cos ";
                i += 2;
            }
            else if (token == 't' && expr[i + 1] == 'a' && expr[i + 2] == 'n') {
                postfix += "tan ";
                i += 2;
            }
            else if (token == 'l' && expr[i + 1] == 'n') {
                postfix += "ln ";
                i++;
            }
            else if (token == 'e' && expr[i + 1] == 'x') {
                postfix += "ex ";
                i++;
            }
        }
    }
    while (!stk.empty()) {
        postfix += stk.top();
        postfix += " ";
        stk.pop();
    }
    return postfix;
}

// Hàm tính giá trị của biểu thức hậu tố
double evaluate_postfix(string postfix) {
    stack<double> stk;
    for (int i = 0; i < postfix.length(); i++) {
        char token = postfix[i];
        if (isdigit(token)) {
            double num = token - '0';
            while (isdigit(postfix[i + 1])) {
                num = num * 10 + (postfix[i + 1] - '0');
                i++;
            }
            stk.push(num);
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == 'd' || token == 's' || token == 'c' || token == 't' || token == 'l' || token == 'e') {
            double op1, op2, result;
            if (token == '+') {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                result = op1 + op2;
                stk.push(result);
            }
            else if (token == '-') {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                result = op1 - op2;
                stk.push(result);
            }
            else if (token == '*') {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                result = op1 * op2;
                stk.push(result);
            }
            else if (token == '/') {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                result = op1 / op2;
                stk.push(result);
            }
            else if (token == 'd') {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                result = op1 % op2;
                stk.push(result);
            }
            else if (token == 's') {
                double op = stk.top();
                stk.pop();
                result = sin(op);
                stk.push(result);
            }
            else if (token == 'c') {
                double op = stk.top();
                stk.pop();
                result = cos(op);
                stk.push(result);
            }
            else if (token == 't') {
                double op = stk.top();
                stk.pop();
                result = tan(op);
                stk.push(result);
            }
            else if (token == 'l') {
                double op = stk.top();
                stk.pop();
                result = log(op);
                stk.push(result);
            }
            else if (token == 'e') {
                double op = stk.top();
                stk.pop();
                result = exp(op);
                stk.push(result);
            }
        }
    }
    return stk.top();
}
int main() {
    string bieuthuc;
    cin >> bieuthuc;
    cout<<evaluate_postfix(infix_to_postfix(bieuthuc));
    return 0;
}