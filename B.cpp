#include <iostream>
#include <algorithm>
using namespace std;
long long int convert(long long int n, int base)
{
    string result;
    while (n > 0)
    {
        if (base >= 11)
        {
            if (n % base > 9)
            {
                result = char(n % base - 10 + 'A') + result;
            }
            else
            {
                result = char(n % base + '0') + result;
            }
        }
        else
        {
            result = char(n % base + '0') + result;
        }
        n /= base;
    }
    if (result == "")
    {
        result = "0";
    }
    return stoll(result);
}
long long int reverse_convert(string n, int base)
{
    long long int result = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (base >= 11)
        {
            if (n[i] >= 'A')
            {
                result = result * base + n[i] - 'A' + 10;
            }
            else
            {
                result = result * base + n[i] - '0';
            }
        }
        else
        {
            result = result * base + n[i] - '0';
        }
    }
    return result;
}
long long int _minus(long long int a, long long int b)
{
    string ans = "";
    int temp;
    int carry = 0;
    while (a > 0 or b > 0)
    {
        temp = a % 10 - carry - b % 10;
        carry = 0;
        if (temp < 0)
        {
            temp += 8;
            carry = 1;
        }
        ans = char(temp + '0') + ans;
        a /= 10;
        b /= 10;
    }
    return stoll(ans);
}
long long int NumberSort(long long int number)
{
    string num_temp = to_string(number);
    sort(num_temp.begin(), num_temp.end());
    return stoll(num_temp);
}
long long int B(long long int number)
{
    int i = 4;
    long long int temp = NumberSort(number);
    while (temp != number and i >= 0)
    {
        number = _minus(number, temp);
        temp = NumberSort(number);
        i--;
    }
    return number;
}
int main()
{
    long long int number;
    while (cin >> number)
    {
        number = convert(number, 8);
        cout << reverse_convert(to_string(B(number)), 8)<<"\n";
    }
    return 0;
}
