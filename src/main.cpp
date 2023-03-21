#include <iostream>

int main()
{
    int n = 6;

    int* arr = new int[n] {80, 2000, 1, 451, 211, 71};

    for (size_t i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    //mergeSort(arr, , );

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
    // вычисляем размер левой и правой части массивов
    int nl = m - l + 1;
    int nr = r - m;

    // создаём временные массивы
    int left[nl];
    int right[nr];

    // копируем данные во временные массивы
    for (int i = 0; i < nl; ++i)
    {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < nr; ++j)
    {
        right[j] = arr[m + j + 1];
    }
    
    //инициализируем индексы
    int i = 0;
    int j = 0;
    int k = l; // начало левой части

    //записываем минимальные эл-ты обратно во вхдной массив
    while (i < nl && j < nr)
    {
        if (left[i] < right[i])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j];
        }
    }

    // записываем оставшиеся элементы левой части
    while (i < nl)
    {
        arr[k++] = left[i++];
    }

    //записываем оставшиеся элементы в правой части
    while (j < nr)
    {
        arr[k++] = right[j++];
    }
}