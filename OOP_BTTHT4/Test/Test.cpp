#include<iostream>
#include<string.h>
#include<cctype>
#include<string>
#include <cmath>
#include <iomanip>
#include <stack>
using namespace std;
string PostfixPrefixCalculator(string input)
{
    if (isdigit(input[input.length() - 1]))
    {
        stack<double> Stack;
        for (short j = input.size() - 1; j >= 0; j--) {
            if (input[j] == ' ')
                continue;
            if (isdigit(input[j])) {
                double num = 0, i = j;
                while (j < input.size() && isdigit(input[j]))
                    j--;
                j++;
                for (unsigned int k = j; k <= i; k++)
                    num = num * 10 + double(input[k] - '0');
                Stack.push(num);
            }
            else {

                double o1 = Stack.top();
                Stack.pop();
                double o2 = Stack.top();
                Stack.pop();
                switch (input[j]) {
                case '^':
                    Stack.push(pow(o1, o2));
                    break;
                case '+':
                    Stack.push(o1 + o2);
                    break;
                case '-':
                    Stack.push(o1 - o2);
                    break;
                case '*':
                    Stack.push(o1 * o2);
                    break;
                case '/':
                    Stack.push(o1 / o2);
                    break;
                }
            }
        }
        string result = to_string(Stack.top());
        return result;
    }
    else
    {
        stack<double> st;

        for (unsigned int i = 0; i < input.size(); ++i) {
            if (input[i] == ' ')
                continue;
            else if (isdigit(input[i])) {
                double num = 0;
                while (isdigit(input[i])) {
                    num = num * 10 + (int)(input[i] - '0');
                    i++;
                }
                i--;
                st.push(num);
            }
            else {
                double val1 = st.top();
                st.pop();
                double val2 = st.top();
                st.pop();
                switch (input[i]) {
                case '^':
                    st.push(pow(val2, val1));
                    break;
                case '+':
                    st.push(val2 + val1);
                    break;
                case '-':
                    st.push(val2 - val1);
                    break;
                case '*':
                    st.push(val2 * val1);
                    break;
                case '/':
                    st.push(val2 / val1);
                    break;
                }
            }
        }
        string result_1 = to_string(st.top());
        return result_1;
    }
}
int main()
{
    string input = "- + - + 1 * 2 - 3 / 4 + - 5 * 6 - 7 8 / 9 10 / 321 123 * 234 432 / * 543 ^ + 987 234 2 20";
    cout << PostfixPrefixCalculator(input);
    return 0;
}