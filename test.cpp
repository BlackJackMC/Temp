#include <iostream>
using namespace std;
string multiply(string first, string second)
{
    int temp;
    int carry=0;
    string ans;
    for(int i=first.length()-1; i>=0;i--)
    {
        temp=(first[i]-'0') * stoi(second)+carry;
        carry=temp/10;
        temp%=10;
        ans=char(temp+'0')+ans;
    }
    if(carry!=0)
    {
        ans=to_string(carry)+ans;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n==1 or n==0)
    {
        cout<<1;
        return 0;
    }
    else
    {
        string current="1";
        string temp;
        for(int i=2;i<=n;i++)
        {
            temp=to_string(i);
            current= multiply(current,temp);
        }
        cout<<current;
    }
}
