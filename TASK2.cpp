#include <iostream>
using namespace std;

int main()
{

    int a, b;
    char op;

    cout << "Enter first operand : ";
    cin >> a;

    cout << "Enter operator(+, -, *, /, %) : ";
    cin >> op;

    cout << "Enter second operand : ";
    cin >> b;

    switch (op)
    {
    case '+':
        cout << " The sum is " << a + b;
        break;
    case '-':
        cout << " The difference is " << a - b;
        break;
    case '*':
        cout << " The product is " << a * b;
        break;
    case '/':
        cout << " The quotient is " << a / b;
        break;
    case '%':
        cout << " The remainder is " << a % b;
        break;

    default:
        cout << "Invalid operator !!";
        break;
    }

    return 0;
}
