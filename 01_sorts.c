#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

void qsort(int *arr, int begin, int end)
{
    int left = begin, right = end, base;
    base = arr[(left + right)/2];
    do
    {
        while(arr[left] < base) left++;
        while(arr[right] > base) right--;
        if(left <= right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    } while(left <= right);
    if ( begin < right )
        qsort(arr, begin, right);
    if ( end > left )
        qsort(arr, left, end);
}

void sorting_function_1(int *arr, int arr_len)
{
    qsort(arr, 0, arr_len-1);
}

void heap(int *arr, int root, int bottom)
{
  int maxChild, done = 0;
  while((root * 2 + 1 <= bottom) && (!done))
  {
    if(root * 2 + 2 <= bottom)
    {
        if(arr[root * 2 + 2] > arr[root * 2 + 1])
            maxChild = root * 2 + 2;
        else
            maxChild = root * 2 + 1;
    }
    else
        maxChild = root * 2 + 1;
    if(arr[root] < arr[maxChild])
    {
      int temp = arr[root];
      arr[root] = arr[maxChild];
      arr[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}

void sorting_function_2(int *arr, int arr_len)
{
  FILE *heapsort;
  heapsort = fopen("heapsort.log", "w");
  for (int i = (arr_len / 2) - 1; i >= 0; i--)
    heap(arr, i, arr_len - 1);
    fprintf(heapsort, "%d", arr[i], " ");
  for (int i = arr_len - 1; i >= 1; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heap(arr, 0, i - 1);
    fprintf(heapsort, "%d", arr[i]), " ";
  }
}

int main()
{
    FILE *quicksort;
    FILE *heapsort;
    quicksort = fopen("quicksort.log", "w");
    heapsort = fopen("heapsort.log", "w");
    int arr_len;
    scanf("%d",&arr_len);
    int *arr = (int*)malloc(sizeof(int) * arr_len);
    for(int i = 0; i < arr_len; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting_function_1(arr, arr_len);
    for(int i = 0; i < arr_len; i++)
    {
        printf("%d", arr[i]);
        if(i<arr_len-1)
        printf(" ");
    }
    free(arr);
    printf("\n");
}
