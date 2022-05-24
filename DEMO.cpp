#include <iostream>
using namespace std;
#define max 50
// class Min_Heap
// {
//     int heap_size;
//     int cap;
//     int arr[max];

// public:
//     Min_Heap(int s)
//     {
//         heap_size = s;
//         cap = s;
//         // arr = new int[cap];
//     }
//     void print()
//     {
//         cout << "\nArr = ";
//         for (int i = 0; i < heap_size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     int left(int i)
//     {
//         return (2 * i + 1);
//     }
//     int right(int i)
//     {
//         return (2 * i + 2);
//     }
//     void heapify(int i)
//     {
//         int smaller = i;
//         int l = left(i);
//         int r = right(i);

//         if (l < heap_size && arr[l] < arr[i])
//         {
//             smaller = l;
//         }
//         if (r < heap_size && arr[r] < arr[smaller])
//         {
//             smaller = r;
//         }

//         if (smaller != i)
//         {
//             swap(arr[i], arr[smaller]);
//             heapify(smaller);
//         }
//     }
//     void getUnsorted()
//     {
//         cout << "\nEnter The Elements of Unsorted array ::";
//         for (int i = 0; i < heap_size; i++)
//         {
//             cin >> arr[i];
//         }
//         // heapify(0);
//     }
//     int getMin()
//     {
//         return arr[0];
//     }
//     void sort()
//     {
//         for (int i = cap / 2 - 1; i >= 0; i--)
//         {
//             heapify(i);
//         }
//     }
//     int extractMin()
//     {
//         if (heap_size == 0)
//         {
//             return 999999;
//         }
//         if (heap_size == 1)
//         {
//             heap_size--;
//             return arr[0];
//         }

//         int root = arr[0];
//         arr[0] = arr[heap_size - 1];
//         heap_size--;
//         heapify(0);
//         return root;
//     }

//     void Heap_Sort()
//     {
//         cout << "\nSorted Array = ";
//         for (int i = 0; i < cap; i++)
//         {
//             int temp = extractMin();
//             cout << temp << " ";
//         }
//         cout << endl;
//     }
// };
int main()
{
    int s = 6;
    int m = 0;
    swap(s,m);
    cout << s << " " << m << endl;
    return 0;
}