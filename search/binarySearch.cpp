#include <iostream>
#include <vector>
using namespace std;

int binarySearchFirstBigger(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(a[mid] >= val)
        {
            if(a[mid-1] < val)
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        if(a[mid] < val)
        {
            low = mid+1;
        }
    }
    return -1;
}

int binarySearchLastSmaller(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(a[mid] <= val)
        {
            if(a[mid+1] > val)
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        if(a[mid] > val)
        {
            high = mid-1;
        }
    }
    return -1;
}

int binarySearchFirst(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(a[mid] == val)
        {
            if(a[mid-1] < val)
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
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

int binarySearchLast(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(a[mid] == val)
        {
            if(a[mid+1] > val)
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
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


// int a[6] = {4,5,6,1,2,3}
int binary(int *a, int n, int val)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(a[mid] == val)
        {
            return mid;
        }

        if(a[mid-1] > a[mid] || a[mid+1] < a[mid])
        {
            if(a[mid] > val && val < a[0])
            {
                low = mid+1;
            }
            else if(a[mid] > val)
            {
                high = mid -1;
            }

            if(a[mid] < val && val > a[n-1])
            {
                high = mid -1;
            }
            else if(a[mid] < val)
            {
                low = low+1;
            }
        }
        else
        {
            if(a[mid] > val)
            {
                high = high-1;
            }

            if(a[mid] < val)
            {
                low = low +1;
            }
        }

    }
    return -1;


}

int search(vector<int>& nums, int target) {
    int len = nums.size();
    int low = 0;
    int high = len-1;

    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(nums[mid] == target)
        {
            return mid;
        }

        if(nums[mid-1] > nums[mid] || nums[mid+1] < nums[mid])
        {
            if(nums[mid] > target && target < nums[0])
            {
                low = mid+1;
            }
            else if(nums[mid] > target)
            {
                high = mid -1;
            }

            if(nums[mid] < target && target > nums[len-1])
            {
                high = mid -1;
            }
            else if(nums[mid] < target)
            {
                low = low+1;
            }
        }
        else
        {
            if(nums[mid] > target)
            {
                high = high-1;
            }

            if(nums[mid] < target)
            {
                low = low +1;
            }
        }
    }
    return -1;
}

int main()
{
    //int a[8] = {1,2,3,3,3,3,7,8};
    //int n = binarySearch(a, 8, 8);
    //int n = binarySearch_recursion(a, 8, 5);
    //int first = binarySearchFirst(a, 8, 3);
    //int last = binarySearchLast(a, 8, 3);
    //int first = binarySearchFirstBigger(a, 8, 3);
    //int last = binarySearchLastSmaller(a, 8, 3);
    //cout << "firstBigger2:" << first<<endl;
    //cout << "lastSmaller1:" << last << endl;
    int a[6]={4,5,6,1,2,3};
    int n = binary(a, 6, 5);
    cout << n << endl;
    return 0;
}
