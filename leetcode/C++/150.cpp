#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> stack;
    int evalRPN(vector<string> &tokens)
    {
        for (auto &e : tokens)
        {
            char ch = e[0];
            if (e.size() != 1)
                ch = ' ';
            switch (ch)
            {
            case '+':
            {
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();
                int num3 = num1 + num2;
                stack.push_back(num3);
                break;
            }
            case '-':
            {
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();
                int num3 = num2 - num1;
                stack.push_back(num3);
                break;
            }
            case '*':
            {
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();
                int num3 = num1 * num2;
                stack.push_back(num3);
                break;
            }
            case '/':
            {
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();
                int num3 = num2 / num1;
                stack.push_back(num3);
                break;
            }
            default:
            {
                const char *str = e.c_str();
                int num = atoi(str);
                stack.push_back(num);
                break;
            }
            }
        }
        return stack.front();
    }
};