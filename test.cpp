#include <iostream>
using namespace std;
string b1, b2;
string hexa[16][2] =
    {
        {"0000", "0"},
        {"0001", "1"},
        {"0010", "2"},
        {"0011", "3"},
        {"0100", "4"},
        {"0101", "5"},
        {"0110", "6"},
        {"0111", "7"},
        {"1000", "8"},
        {"1001", "9"},
        {"1010", "A"},
        {"1011", "B"},
        {"1100", "C"},
        {"1101", "D"},
        {"1110", "E"},
        {"1111", "F"}};
string octa[8][2] =
    {
        {"000", "0"},
        {"001", "1"},
        {"010", "2"},
        {"011", "3"},
        {"100", "4"},
        {"101", "5"},
        {"110", "6"},
        {"111", "7"}};
void compact(string &number)
{
    while (number[0] == '0')
    {
        number.erase(0, 1);
        if (number.empty())
        {
            number = "0";
            return;
        }
    }
    return;
}
void balance(string &number, int length)
{
    while (number.length() < length)
    {
        number = "0" + number;
    }
    return;
}
string convert(string n, int base)
{
    string ans;
    if (base == 16)
    {
        if (n.length() % 4 != 0)
        {
            int temp = n.length() % 4;
            for (int i = 1; i <= 4 - temp; i++)
            {
                n = "0" + n;
            }
        }
        while (n.length() != 0)
        {
            string temp;
            temp = n.substr(n.length() - 4, 4);
            n.erase(n.length() - 4, 4);
            for (int i = 0; i < 16; i++)
            {
                if (hexa[i][0] == temp)
                {
                    ans = hexa[i][1] + ans;
                }
            }
        }
        return ans;
    }
    else
    {
        while (n.length() != 0)
        {
            string temp;
            if (n.length() % 3 != 0)
            {
                n = "0" + n;
            }
            temp = n.substr(n.length() - 3, 3);
            n.erase(n.length() - 3, 3);
            for (int i = 0; i < 8; i++)
            {
                if (octa[i][0] == temp)
                {
                    ans = octa[i][1] + ans;
                }
            }
        }
        return ans;
    }
}
string add()
{
    string ans;
    int carry = 0;
    int temp;
    for (int i = b1.length() - 1; i >= 0; i--)
    {
        temp = (b1[i] - '0') + (b2[i] - '0') + carry;
        ans = char((temp % 2) + '0') + ans;
        carry = temp / 2;
    }
    if (carry)
    {
        ans = "1" + ans;
    }
    compact(ans);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string result;
    cin >> b1 >> b2;
    if (b1.length() > b2.length())
    {
        balance(b2, b1.length());
    }
    else
    {
        balance(b1, b2.length());
    }
    result = add();
    cout << result << "\n\n"
         << convert(result, 8) << "\n\n"
         << convert(result, 16);
    return 0;
}
