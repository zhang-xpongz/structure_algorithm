#include <iostream>
using namespace std;

void bubbleSort(int *a, int n)
{
    int cnt = 0;
    for(int i=0; i<n;i++)
    {
        cnt++;
        bool ex = false;
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                ex  =true;
            }
        }

        if(ex == false)
        {
            break;
        }
    }
    cout<<"cnt"<<cnt<<endl;
}

void insertSort(int *a, int n)
{
    for(int i = 1; i< n; i++)
    {
        int value = a[i];
        int j = i-1;
        for(; j>=0;j--)
        {
            if(a[j] > value)
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = value;
    }
}

int main()
{
    int a[7] = {6,7,5,3,1,2,4};

    //bubbleSort(a, 7);
    insertSort(a, 7);
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
