#include <iostream>
using namespace std;

void bubbleSort(int *a, int n)
{
    for(int i=0; i<n;i++)
    {
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

void selectSort(int *a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int j=i+1;
        int tmp2 = j;
        for(; j<n; j++)
        {
            if(a[j] < a[tmp2])
            {
                tmp2 = j;
            }
        }

        if(a[tmp2] < a[i])
        {
            int tmp = a[i];
            a[i] = a[tmp2];
            a[tmp2] = tmp;
        }
    }
}

void merge(int *a, int p, int q, int m, int n)
{
    int index1 = p;
    int index2 = m;
    cout << "p:" << p<< "q:" << q<< "m:" << m<< "n:"<< n<<endl;
    int *tmp = new int[(n-p+1)];
    int cnt=0;
    while(index1 <=q && index2<=n)
    {
        if(a[index1] < a[index2])
        {
            tmp[cnt] = a[index1];
            cnt++;
            index1++;
        }
        else
        {
            tmp[cnt] = a[index2];
            cnt++;
            index2++;
        }
    }

    while(index1<=q)
    {
        tmp[cnt] = a[index1];
        cnt++;
        index1++;
    }

    while(index2 <= n)
    {
        tmp[cnt] = a[index2];
        cnt++;
        index2++;
    }

    int i = 0;
    while(i<(n-p+1))
    {
        a[p+i] = tmp[i];
        i++;
    }
    delete []tmp;
}

void mergeSortSub(int *a, int p, int q)
{
    if(p>=q)return;

    int m = (p+q)/2;
    mergeSortSub(a, p, m);
    mergeSortSub(a, m+1, q);

    merge(a, p, m, m+1, q);
}

void mergeSort(int *a, int n)
{
    mergeSortSub(a, 0, n-1);
}

int partition(int *a, int p, int q)
{
    int pivot = a[q];
    int i = p;
    for(int j =p; j < q; j++)
    {
        if(a[j] < pivot)
        {
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            i++;
        }
    }
    //cout << i << endl;
    int tmp1 = a[q];
    a[q] = a[i];
    a[i] = tmp1;
    return i;
}

void quickSortSub(int *a, int p, int q)
{
    if(p >= q)return;

    int n = partition(a, p, q);
    quickSortSub(a, p, n-1);
    quickSortSub(a, n+1, q);
}

void quickSort(int *a, int n)
{
    quickSortSub(a, 0, n-1);
}

int main()
{
    int a[8] = {6,7,5,3,1,2,4,8};

    //bubbleSort(a, 7);
    //insertSort(a, 7);
    //selectSort(a, 8);
    //mergeSort(a, 8);
    quickSort(a, 8);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
