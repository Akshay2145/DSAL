// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;


class MaxHeap
{
    int n;
    int arr[10];

    public:
    MaxHeap(int n)
    {
        this->n = n;
        for(int i = 0;i<n;i++)
        {
            arr[i] = -1;
        }
    }

    void insert()
    {
        for (int i = 0; i < this->n; ++i)
            cin>>this->arr[i];
    }

    void heapify(int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);

            heapify( n, largest);
        }
    }

    // main function to do heap sort
    void heapSort()
    {
        // Build heap (rearrange array)
        for (int i = n/2-1; i >= 0; i--)
            heapify(n, i);


        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);

            // call max heapify on the reduced heap
            heapify(i, 0);
        }
    }

    /* A utility function to print array of size n */
    void printArray()
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

};


// Driver program
int main()
{
        cout<<"enter total no of elements: \n";
    int n;
    cin>>n;

	
    MaxHeap h1(n);
    h1.insert();
    h1.heapSort();
    h1.printArray();
}
