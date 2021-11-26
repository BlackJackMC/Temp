#include <iostream>
#include <math.h>
using namespace std;
string convert(long long int n, long long int base)
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
    return result;
}
bool isGear(string number)
{
    bool state;
    if(number.size()<3)
    {
        return false;
    }
    if (number[0] > number[1])
    {
        state = true;
    }
    else if (number[0] < number[1])
    {
        state = false;
    }
    else
    {
        return false;
    }
    for (long long int i = 1; i < number.length() - 1; i++)
    {
        if (state)
        {
            if (number[i] >= number[i + 1])
            {
                return false;
            }
            state = !state;
        }
        else
        {
            if (number[i] <= number[i + 1])
            {
                return false;
            }
            state = !state;
        }
    }
    return true;
}
bool gear_check(long long int dec, string bin, string oct, string hex)
{
    return (isGear(to_string(dec)) + isGear(bin) + isGear(oct) + isGear(hex)) >= 2;
}
bool isPrime(long long int number)
{
    if (number <= 2)
        return number > 1;
    else
    {
        for (long long int i = 2; i <= sqrt(number); i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
int main()
{
    long long int n, dec, sum = 0;
    string bin, oct, hex;
    cin >> n >> dec;
    dec += 1;
    while (n > 0)
    {
        bin = convert(dec, 2);
        oct = convert(dec, 8);
        hex = convert(dec, 16);
        if (gear_check(dec, bin, oct, hex))
        {
            if (isPrime(dec))
            {
                sum += 1;
            }
            cout << dec << "\n";
            n--;
        }
        dec++;
    }
    cout << sum << "\n";
    return 0;
}
