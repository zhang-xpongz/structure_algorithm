#include <iostream>
using namespace std;

int binarySearch(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;

    while(low<=high)
    {
        int mid = low + ((high-low)>>1);
        if(a[mid] == val)
        {
            return mid;
        }

        if(a[mid] > val)
        {
            high = mid-1;
        }

        if(a[mid] < val)
        {
            low = mid+1;
        }
    }
    return -1;
}

int _binarySearch_recursion(int *a, int low, int high, int val)
{
    if(low > high)
        return -1;

    int mid = low + ((high-low)>>1);

    if(a[mid] == val)
        return mid;
    else if(a[mid] < val)
    {
        return _binarySearch_recursion(a, mid+1, high, val);
    }
    else
    {
        return _binarySearch_recursion(a, low, mid-1, val);
    }

}

int binarySearch_recursion(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;
    return _binarySearch_recursion(a, low, high, val);
}

int main()
{
    int a[8] = {1,2,3,4,5,6,7,8};
    //int n = binarySearch(a, 8, 8);
    int n = binarySearch_recursion(a, 8, 5);
    cout << n << endl;
    return 0;
}
