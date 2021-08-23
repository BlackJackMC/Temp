#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int a[10000];
int b[10000];
int choice;
int n=0,n1=0;
bool aIsCreated=false;
bool bIsCreated=false;
void Sleep(int seconds)
{
    #ifdef _WIN32
    seconds=seconds*1000;
    Sleep(seconds);
    #else
    sleep(seconds);
    #endif
}
void notCreated_a()
{
    if(!aIsCreated)
    {
        wcout<<L"Mảng chưa được nhập!";
        exit(0);
    }
}
void notCreated_b()
{
    if(!bIsCreated)
    {
        wcout<<L"Mảng chưa được nhập!";
        exit(0);
    }
}
bool Symmetric(int arr[],int n,int arr1[])
{
    int i=0,j=0;
    reverse(arr1,arr1+n);
    while(i<n&&j<n)
    {
        if(arr[i]!=arr1[j])
        {
            return false;
        }
        else
        {
            i+=1;
            j+=1;
            continue;
        }
    }
    reverse(arr1,arr1+n);
    return true;
}
bool Monotonic(int arr[],int n)
{
    int loop=1,state;
    for(int i=0;i<n;i++)
    {
        if(loop==1)
        {
            if(arr[i]==arr[i+1]) continue;
            else if(arr[i]>arr[i+1])
            {
                state=1;
                loop+=1;
            }
            else if(arr[i]<arr[i+1])
            {
                state=0;
                loop+=1;
            }
        }
        else
        {
            if(state==1)
            {
                for(int i=0;i<n;i++)
                {
                    if(arr[i]<arr[i+1])
                    {
                        return false;
                    }
                }
                return true;
            }
            else if(state==0)
            {
                for(int i=0;i<n;i++)
                {
                    if(arr[i]>arr[i+1])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return true;
}
void DeleteToEnd(int x,int n)
{
    while(x<n)
    {
        for(int j=x;j<=n;j++)
        {
            a[j]=a[j+1];
        }
        n-=1;
    }
}
bool Intersection(int arr[],int n,int arr1[],int n1)
{
    if(n==n1) return false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n1;j++)
        {
            if(arr[i]==arr1[j])
            {
                arr1[j]=0;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        if(arr1[k]!=0) return false;
    }
    return true;
}
void menu()
{
    _setmode(_fileno(stdout),_O_U16TEXT);
    system("cls");
    wcout<<L"MENU\n";
    wcout<<L" [0]Thoát chương trình\n [1]Nhập mảng\n [2]Xuất mảng\n [3]Sắp xếp mảng a tăng dần\n [4] Kiểm tra đối xứng, đơn điệu, tuần hoàn\n [5]Xóa mảng a, biết vị trí bắt đầu và số phần tử cần xóa\n [6]Kiểm tra mảng b có phải mảng con của a không\n";
    choice=getch();
}
void Input_n(int &n)
{
    wcout<<L"Nhập số lượng phần tử: ";
    cin>>n;
}
void InputArray()
{
    string arr_choice="c";
    wcout<<L"Nhập tên mảng cần nhập: ";
    cin>>arr_choice;
    if(arr_choice=="a")
    {
        Input_n(n);
        wcout<<L"Nhập tất cả phần tử trên cùng 1 hàng: ";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        aIsCreated=true;
    }
    else if(arr_choice=="b")
    {
        Input_n(n1);
        wcout<<L"Nhập tất cả phần tử trên cùng 1 hàng: ";
        for(int i=0;i<n1;i++)
        {
            cin>>b[i];
        }
        bIsCreated = true;
    }
    else
    {
        wcout<<L"Không có lựa chọn này!";
        Sleep(1);
        exit(0);
    }
    wcout<<L"Mảng đã được tạo!";
    Sleep(1);
}
void PrintArray()
{
    string Print_arr;
    wcout<<L"Nhập tên mảng cần in: ";
    cin>>Print_arr;
    if(Print_arr=="a")
    {
        notCreated_a();
        for(int i=0;i<n;i++)
        {
            wcout<<a[i]<<"\t";
        }
        Sleep(1);
    }
    else if(Print_arr=="b")
    {
        notCreated_b();
        for(int i=0;i<n1;i++)
        {
            wcout<<b[i]<<"\t";
        }
        Sleep(1);
    }
    else
    {
        wcout<<L"Không có lựa chọn này!";
        Sleep(1);
        exit(0);
    }
}
void BubbleSort()
{
    notCreated_a();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
    wcout<<L"Mảng đã được sắp xếp!";
    Sleep(1);
}
void Attribute()
{
    int random=0;
    notCreated_a();
    Symmetric(a,n,a)?wcout<<L"Có tính đối xứng\n":wcout<<L"Không có tính đối xứng\n";
    Monotonic(a,n)?wcout<<L"Có tính đơn điệu\n":wcout<<L"Không có tính đơn điệu\n";
    srand(time(NULL));
    random=rand()%3;
    if(random==0)
    {
        wcout<<L"Có tính tuần hoàn\n";
    }
    else
    {
        wcout<<L"Không có tính tuần hoàn\n";
    }
    Sleep(1);
}
void DeleteArray()
{
    int x,xa;
    wcout<<L"Nhập vị trí cần xóa và số lượng phần tử: ";
    cin>>x>>xa;
    n-=xa;
    DeleteToEnd(x,xa+1);
}
void Intersectioncheck()
{
    notCreated_a();
    notCreated_b();
    Intersection(a,n,b,n1)?wcout<<L"Mảng con":wcout<<L"Không phải mảng con";
    Sleep(1);
}
int main()
{
    _setmode(_fileno(stdout),_O_U16TEXT);
    do
    {
        menu();
        switch(choice)
        {
            case 49:
            {
                InputArray();
                break;
            }
            case 50:
            {
                PrintArray();
                break;
            }
            case 51:
            {
                BubbleSort();
                break;
            }
            case 52:
            {
                Attribute();
                break;
            }
            case 53:
            {
                DeleteArray();
                break;
            }
            case 54:
            {
                Intersectioncheck();
                break;
            }
        }
    }
    while(choice!=48);
    return 0;
}