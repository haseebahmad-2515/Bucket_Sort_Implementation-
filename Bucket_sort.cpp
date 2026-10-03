#include <iostream>
using namespace std;

void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(float A[], int n)
{
    // 1) Let B[0...n-1] be a new array
    float** B = new float*[n];


    // Keep track of how many elements are in each bucket
    int* count = new int[n];

    // 4) Make B[i] an empty list
    for (int i = 0; i < n; i++)
    {
        B[i] = new float[n];
        count[i] = 0;
    }

    // 5) for i = 1 to n
    for (int i = 0; i < n; i++)
    {
        // 6) insert A[i] into list B[floor(n*A[i])]
        int index = n * A[i];

        B[index][count[index]] = A[i];
        count[index]++;
    }

    // 7) for i = 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // 8) sort B[i] with insertion sort
        insertionSort(B[i], count[i]);
    }

    // 9) concatenate the lists together
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            A[k] = B[i][j];
            k++;
        }
    }

    
    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete[] B[i];
    }

    delete[] B;
    delete[] count;
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    float* A = new float[n];

    cout << "Enter elements between 0 and 1:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    bucketSort(A, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    delete[] A;

    return 0;
}