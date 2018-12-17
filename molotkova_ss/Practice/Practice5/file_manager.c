#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_LEN 100
 
#define SIZE 10
int choose_pivot(int i,int j );
void quicksort(int *a,int m,int n);
void swap(int *x,int *y);
void selection_sort(int* a, const int n);
void display(int *a,int size);
void insertion_sort(int *a,const int size);

void merge(int *a, int *tmp, int left, int mid, int right);
void msort(int *a, int *tmp, int left, int right);
void merge_sort(int *a, int *tmp, const int size);

void buble_sort(int *a, const int n);

void counting_sort(int *a, const int size);
//ОСНОВНАЯ ФУНКЦИЯ 
void main()
{
 
    int* a;//ДАН МАССИВ из 10 элементов(size) динамический
	a = (int*)malloc(SIZE);
	int method;
    int i=0;// ввели i 
	int* tmp;
	tmp = (int*)malloc(SIZE);
	for (i=0; i<SIZE; i++)
		a[i]=SIZE-i;
    //printf("The array before sorting:\n"); // вывод до сортировки
    char* b = (char*)malloc(MAX_LEN);
	wchar_t* ca = (wchar_t*)malloc(MAX_LEN);
	fgets(b, MAX_LEN, stdin);
	a[strlen(b) - 1] = '\0' ;
	swprintf( ca, MAX_LEN, L"%hs" ,b);
    ListDirectoryContents(ca);
	//display(a,SIZE); //вызов функции вывода на экран
	printf (" Select sort: \n1. Selection sort \n2. Quicksort \n3. Insertion sort \n4. Merge sort \n5. Buble sort \n6. Counting sort \n"); 
    scanf ("%d", &method); 
	switch (method) {
	     case 1 : selection_sort(a,SIZE);
			 break;
		 case 2 : quicksort(a,0, SIZE-1);
			 break;
		 case 3 : insertion_sort(a, SIZE);
			 break;
		 case 4 :  merge_sort(a, tmp, SIZE);
			 break;
		 case 5 : buble_sort(a, SIZE);
			 break;
		// case 6 : counting_sort(a, SIZE);
		//	 break;
	}
	//selection_sort(a,SIZE); //вызов функции сортировки выбором
 
    printf("The array after sorting:\n"); //вывод после сортировки
    display(a,SIZE); //вызов функции вывода на экран
}
 
/*
    swap two integers
*/
void swap(int *x,int *y)
{
    int temp;
 
    temp = *x;
    *x = *y;
    *y = temp;
}
/*
    selection sort
*/
void selection_sort(int *a,const int size)//требуется сам массив и его размер
{
    int i, j, min;
 
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void display(int *a,const int size) // выводит на экран элементы  int массива размера до константы size
{
    int i;
    for(i=0; i<size; i++)
        printf("%d ",a[i]);
    printf("\n");
}
int choose_pivot(int i,int j )// функкция для быстрой сортировки
{
    return((i+j) /2);
}
 
void quicksort(int *a,int m,int n) //сам массив и ???
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&a[m],&a[k]);
        key = a[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (a[i] <= key))
                i++;
            while((j >= m) && (a[j] > key))
                j--;
            if( i < j)
                swap(&a[i],&a[j]);
        }
        /* swap two elements */
        swap(&a[m],&a[j]);
 
        /* recursively sort the lesser list */
        quicksort(a,m,j-1);
        quicksort(a,j+1,n);
    }
}
void insertion_sort(int *a,const int size)
{
 
    int i,j, k;
    for (i = 1; i < size; ++i)
    {
        k = a[i];
        j = i - 1;
        while ((j >= 0) && (k < a[j]))
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = k;
    }
}
void merge_sort(int *a, int *tmp, const int size)
{
    msort(a, tmp, 0, size - 1);
}
 
void msort(int *a, int *tmp, int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        msort(a, tmp, left, mid);
        msort(a, tmp, mid + 1, right);
        merge(a, tmp, left, mid + 1, right);
    }
}
 
void merge(int *a, int *tmp, int left, int mid, int right)
{
    int i, left_end, count, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    count = right - left + 1;
 
    while ((left <= left_end) && (mid <= right))
    {
        if (a[left] <= a[mid])
        {
            tmp[tmp_pos] = a[left];
            tmp_pos = tmp_pos + 1;
            left = left +1;
        }
        else
        {
            tmp[tmp_pos] = a[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
 
    while (left <= left_end)
    {
        tmp[tmp_pos] = a[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right)
    {
        tmp[tmp_pos] = a[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
 
    for (i = 0; i <= count; i++)
    {
        a[right] = tmp[right];
        right = right - 1;
    }
}
void buble_sort(int *a,const int size)
{
    int i,j;
    for(i=0; i<(size-1); i++)
    {
        for(j=0; j<(size-(i+1)); j++)
        {
            {
                if(a[j] > a[j+1])
                    swap(&a[j],&a[j+1]);
            }
 
        }
    }
}
/*void counting_sort(int *a, const int size)
{
     int a[SIZE]={0},i,j;
     
     for(i=0;i<size;++i)
      a[a[i]]=a[a[i]]+1;
      
     printf("\nSorted elements are:");
     
     for(i=0;i<=size;++i)
      for(j=1;j<=a[i];++j)
       printf("%d ",i); */
int ListDirectoryContents(const wchar_t *sDir)
{ 
    WIN32_FIND_DATA fdFile; 
    HANDLE hFind = NULL; 
    wchar_t sPath[2048]; 

    wsprintf(sPath, L"%s\\*.*", sDir); 
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) 
    { 
        wprintf(L"Path not found: [%s]\n", sDir); 
        return 1; 
    } 

    do
    { 
        if (wcscmp(fdFile.cFileName, L".") != 0  && wcscmp(fdFile.cFileName, L"..") != 0) 
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8; 
            fileSize |= fdFile.nFileSizeLow;

            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wprintf(L"File: %s Size: %d\n", sPath, fileSize); 
        }
    } 
    while(FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return 0; 
} 
 счетчик
 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
 
int main ()
{
    double start, finish;
    int nums[10000];
    int a, b, t;
    int size;
 
    size = 10000;
    srand(time(NULL));
    for(t=0; t<size; t++) nums[t] = rand() % 100;
 
   printf("First massive:\n");
   for(t=0; t<size; t++) printf("%d ", nums[t]);
   printf("\n");
 
   /*!!!*/ start = GetTickCount();
    /*Пузырьковый метод*/
    for(a=1; a<size; a++)
        for(b=size-1; b>=a; b--) {
            if(nums[b-1]>nums[b]) {
                t = nums[b-1];
                nums[b-1] = nums[b];
                nums[b] = t;
            }
        }
    /*--------------------------*/
     /*!!!*/   finish = GetTickCount();
 
    for(t=0; t<size; t++) printf("%d ", nums[t]);
    printf("\nSeconds: %.15f\n", finish - start);
 
    return 0;
}
 
через clock_t
