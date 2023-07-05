#include <iostream>
using namespace std;

class Heap {
public:
    int* a;
    int count;
    int n;

public:
    Heap(int capacity) {
        a = new int[capacity+1];
        n = capacity;
        count = 0;
    }
    
    ~Heap();

    void insert(int data);
    void delMax();
    void heapify(int *a, int n, int i);
    void sort(int *a, int n);
    void buildHeap(int *a, int n);
};

Heap::~Heap()
{
    if(a)
        delete[] a;
}

void Heap::insert(int data)
{
    if(count >= n)
        return;
    count++;
    a[count] = data;
    int i = count;
    while(i/2 > 0 && a[i] > a[i/2])
    {
        int tmp = a[i];
        a[i] = a[i/2];
        a[i/2] = tmp;
        i = i/2;
    }
}

void Heap::delMax()
{
    if(count==0)
        return;
    a[1] = a[count];
    count--;

    int i = 1;
    while(true)
    {
        int maxPos = i;
        if(i*2 < n && a[i*2] > a[maxPos])
        {
            maxPos = i*2;
        }

        if(i*2+1<n && a[i*2+1] > a[maxPos])
        {
            maxPos = i*2+1;
        }

        if(maxPos == i)
            break;

        int tmp = a[i];
        a[i] = a[maxPos];
        a[maxPos] = tmp;

        i = maxPos;
    }
}

void Heap::buildHeap(int *a, int n)
{
    for(int i = n/2; i>=1; --i)
    {
        heapify(a, n, i);
    }
}

void Heap::heapify(int *a, int n, int i)
{
    while(true)
    {
        int maxPos = i;
        if(i*2 <= n && a[i*2] > a[maxPos])
        {
            maxPos = i*2;
        }

        if(i*2+1<= n && a[i*2+1]>a[maxPos])
        {
            maxPos = i*2+1;
        }

        if(maxPos==i)
            break;

        int tmp = a[i];
        a[i] = a[maxPos];
        a[maxPos] = tmp;

        i = maxPos;
    }
}

void Heap::sort(int *a, int n)
{
    int k = n;
    while(k>1)
    {
        int i = a[1];
        a[1] = a[k];
        a[k] = i;

        k--;
        heapify(a, k, 1);
    }
}

int main()
{
    int a[10]= {0,7,5,19,8,4,1,20,13,16};
    Heap *heap = new Heap(9);
    for(int i =0;i < 10; i++)
    {
        heap->a[i] = a[i];
        cout << heap->a[i]<<endl;
    }

    heap->buildHeap(heap->a, heap->n);
    for(int i =0; i<(heap->n+1); i++)
    {
        cout << heap->a[i]<<endl;
    }

    heap->sort(heap->a, heap->n);
    for(int j=1;j<(heap->n+1);j++)
    {
        cout << heap->a[j]<<endl;
    }

}
