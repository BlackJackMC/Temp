#include <iostream>
#include <string>
using namespace std;
string first="", second="";
string neg="";
bool first_neg, second_neg;
void compact(string &number)
{
    if(number[0]=='-')
    {
        while(number[1] == '0')
        {
            number.erase(1,1);
        }
        if(number=="-")
        {
            number=="0";
        }
    }
    else
    {
        while(number[0] == '0')
        {
            number.erase(0,1);
        }
        if(number=="")
        {
            number="0";
        }
    }
}
void input()
{
    string temp;
    bool check = false;
    while(cin>>temp)
    {
        if(check==false)
        {
            if(temp=="*")
            {
                check = true;
            }
            else
            {
                first+=temp;
            }
        }
        else if(check==true)
        {
            second+=temp;
        }
    }
    compact(first);
    compact(second);
    if(first=="0" or second=="0")
    {
        cout<<first<<"\n"<<"*\n";
        cout<<second<<"\n"<<"=\n";
        cout<<0;
        exit(0);
    }
    first_neg = first[0]=='-';
    second_neg = second[0]=='-';
    if(first_neg) first.erase(0,1);
    if(second_neg) second.erase(0,1);
    if(first_neg!=second_neg)
    {
        neg = "-";
    }
}
string add(string a,string b)
{
    string ans;
    int carry = 0;
    int i = a.length()-1, j = b.length()-1;
    while(i>=0 || j>=0)
    {
        int x = i>=0?a[i]-'0':0;
        int y = j>=0?b[j]-'0':0;
        int sum = x+y+carry;
        carry = sum/10;
        sum = sum%10;
        ans = char(sum+'0')+ans;
        i--;
        j--;
    }
    if(carry>0)
    {
        ans = char(carry+'0')+ans;
    }
    return ans;
}
void multiply()
{
    int temp;
    int n=second.length()-1;
    int carry=0;
    string digit="";
    string ans;
    string ans_temp="";
    while(n>=0)
    {
        for(int i=first.length()-1; i>=0;i--)
        {
            temp=(first[i]-'0') * (second[n]-'0')+carry;
            if(temp>9)
            {
                carry=temp/10;
                temp%=10;
            }
            else
            {
                carry=0;
            }
            ans=char(temp+'0')+ans;
        }
        if(carry!=0)
        {
            ans=char(carry+'0')+ans;
            carry=0;
        }
        if(ans_temp!="")
        {
            ans+=digit;
            ans=add(ans,ans_temp);
        }
        ans_temp=ans;
        ans="";
        digit+="0";
        n--;
    }
    if(first_neg) cout<<"-";
    cout<<first<<"\n"<<"*\n";
    if(second_neg) cout<<"-";
    cout<<second<<"\n"<<"=\n";
    if(neg!="") cout<<neg;
    cout<<ans_temp;
}
int main()
{
    input();
    multiply();
    return 0;
}
