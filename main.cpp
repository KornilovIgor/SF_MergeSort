#include <iostream>

void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr, int l, int r);

int main()
{
    int n = 6;

    int* arr = new int[n] {80, 2000, 1, 451, 211, 71};

    for (size_t i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    mergeSort(arr, 0, n-1);

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;


    return 0;
}

void mergeSort(int* arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int m = (l + r - 1) / 2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

void merge(int* arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    int left[nl];
    int right[nr];

    for (int i = 0; i < nl; ++i)
    {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < nr; ++j)
    {
        right[j] = arr[m + j + 1];
    }
    
    int i = 0;
    int j = 0;
    int k = l;

    while (i < nl && j < nr)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}