#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MIN_REPEAT_FILES 31
#define MAX_COUNT_OF_FILES 50000
#define SIZE_OF_BUFFER 2048 //максимльная длина строки

void Input(wchar_t **sDir)                                       
{
    char *vvodstring;

    *sDir = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t)); //выделение памяти
    vvodstring = (char*)malloc(SIZE_OF_BUFFER * sizeof(char));

    fgets(vvodstring, SIZE_OF_BUFFER, stdin);
    vvodstring[strlen(vvodstring) - 1] = '\0';                    

    swprintf(*sDir, SIZE_OF_BUFFER, L"%hs", vvodstring);
}

void Output(wchar_t **filesName, ULONGLONG *filesSize, int *filesIndex, int N)
{
    int i;

    printf("\n Folder contents:\n");

        for (i = 0; i < N; i++)
            wprintf(L" %d. File: %s Size: %lld bytes\n", i + 1, filesName[filesIndex[i]], filesSize[filesIndex[i]]);
}
int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName, ULONGLONG *filesSize)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    int j = 0;

    sPath = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir);

    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s].\n", sDir);
        return -1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            filesSize[j] = fileSize;

            filesName[j] = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(filesName[j++], L"%s", sPath);
        }
    } while (FindNextFile(hFind, &fdFile));

    FindClose(hFind);
    return j;
}
void Menu(int *tSort)// 
	
{
    do
    {
         printf("\n Choose the type of sorting:\n 1. BubbleSort\n 2. InsertionSort\n "
            "3. SelectionSort\n 4. CountingSort\n "
            "5. QuickSort\n 6. MergeSort\n"
            "7.Close the program: ");
        scanf("%d", tSort);
    } while ((*tSort < 0) || (*tSort > 7));
}
void swap_int(int *var1, int *var2)
{
    int tmp = *var1;
    *var2 = (*var1 = *var2, tmp);
}
void swap_ULONGLONG(ULONGLONG *var1, ULONGLONG *var2)
{
    ULONGLONG tmp = *var1;
    *var2 = (*var1 = *var2, tmp);
}
void QuickSplit(ULONGLONG *filesSize, int *i, int *j, int mid, int *filesIndex)
{
    do
    {
        while (filesSize[*i] < mid)
            (*i)++;
        while (filesSize[*j] > mid)
            (*j)--;

        if (*i <= *j)
        {
            swap_ULONGLONG(&(filesSize[*i]), &(filesSize[*j]));
            swap_int(&(filesIndex[*i]), &(filesIndex[*j]));

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Merge(ULONGLONG *filesSize, int *filesIndex, int first, int midIndex, int last)
{
    int i = first, j = midIndex + 1, step;
    int *tmpIndex = (int*)malloc((last - first + 1) * sizeof(int));
    ULONGLONG *tmp = (ULONGLONG*)malloc((last - first + 1) * sizeof(ULONGLONG));

    for (step = 0; step < last - first + 1; step++)
        if ((j > last) || ((i <= midIndex) && (filesSize[i] < filesSize[j])))
        {
            tmp[step] = filesSize[i];
            tmpIndex[step] = filesIndex[i++];
        }
        else
        {
            tmp[step] = filesSize[j];
            tmpIndex[step] = filesIndex[j++];
        }

    for (step = first; step < last + 1; step++)
    {
        filesSize[step] = tmp[step - first];
        filesIndex[step] = tmpIndex[step - first];
    }

    free(tmp);
    free(tmpIndex);
}

void BubbleSort(ULONGLONG *filesSize, int *filesIndex, int N)
{
    int i, j;

    for (i = 0; i < N; i++)
        for (j = N - 1; j > i; j--)
        {
            if (filesSize[j - 1] > filesSize[j])
            {
                swap_ULONGLONG(&filesSize[j - 1], &filesSize[j]);
                swap_int(&filesIndex[j - 1], &filesIndex[j]);
            }
        }
}

void InsertionSort(ULONGLONG *filesSize, int *filesIndex, int N)
{
    int i, j, tmpIndex;
    ULONGLONG tmp;

    for (i = 1; i < N; i++)
    {
        tmp = filesSize[i];
        tmpIndex = filesIndex[i];
        j = i - 1;

        while ((j >= 0) && (filesSize[j] > tmp))
        {
            filesSize[j + 1] = filesSize[j];
            filesIndex[j + 1] = filesIndex[j];
            j--;
        }

        filesSize[j + 1] = tmp;
        filesIndex[j + 1] = tmpIndex;
    }
}

void SelectionSort(ULONGLONG *filesSize, int *filesIndex, int N)
{
    int i, j, keyIndex, keyNewIndex;
    ULONGLONG key;

    for (i = 0; i < N; i++)
    {
        key = filesSize[i];
        keyIndex = i;
        keyNewIndex = filesIndex[i];

        for (j = i + 1; j < N; j++)
        {
            if (filesSize[j] < key)
            {
                key = filesSize[j];
                keyIndex = j;
            }
        }

        swap_ULONGLONG(&filesSize[keyIndex], &filesSize[i]);
        swap_int(&filesIndex[i], &filesIndex[keyIndex]);
    }
}

void CountingSort(ULONGLONG *filesSize, int *filesIndex, int N)
{
    int i = 0, j = 0, index = 0, diff = 0, k = 0;
    int *fileIndex;
    ULONGLONG **count, min, max;

    min = max = filesSize[0];

    for (i = 0; i < N; i++)
    {
        if (filesSize[i] < min)
            min = filesSize[i];
        if (filesSize[i] > max)
            max = filesSize[i];
    }

    diff = max - min + 1;
    count = (ULONGLONG**)malloc(diff * sizeof(ULONGLONG*));
    for (i = 0; i < diff; i++)
        count[i] = (ULONGLONG*)malloc(MIN_REPEAT_FILES * sizeof(ULONGLONG));
    for (i = 0; i < diff; i++)
        for (j = 0; j < MIN_REPEAT_FILES; j++)
            count[i][j] = 0;

    for (i = 0; i < N; i++)
    {
        count[filesSize[i] - min][0]++;
        count[filesSize[i] - min][(int)count[filesSize[i] - min][0]] = filesIndex[i];
    }

    for (i = 0; i < diff; i++)
        for (j = 0; j < (count[i][0] + 1); j++)
            if (j!= 0) filesIndex[k++] = count[i][j];

    free(count);
}

void QuickSort(ULONGLONG *filesSize, int *filesIndex, int first, int last)
{
    int midIndex, i = first, j = last;

    midIndex = (first + last) / 2;

    QuickSplit(filesSize, &i, &j, filesSize[midIndex], filesIndex);

    if (j > first)
        QuickSort(filesSize, filesIndex, first, j);
    if (i < last)
        QuickSort(filesSize, filesIndex, i, last);
}

void MergeSort(ULONGLONG *filesSize, int *filesIndex, int first, int last)
{
    int midIndex = (last + first) / 2;

    if (first >= last)
        return;

    MergeSort(filesSize, filesIndex, first, midIndex);
    MergeSort(filesSize, filesIndex, midIndex + 1, last);
    Merge(filesSize, filesIndex, first, midIndex, last);
}   



void main()
{
    wchar_t *filesPath, **filesName;
    ULONGLONG *filesSize, *tmpSizes;
    clock_t start, end;
    int *filesIndex;
    int j = -1, i = 0;
    int method = 0,f = 0;

    filesName = (wchar_t**)malloc(MAX_COUNT_OF_FILES * sizeof(wchar_t*));
    filesSize = (ULONGLONG*)malloc(MAX_COUNT_OF_FILES * sizeof(ULONGLONG));

    printf("\t\t\t\tFile Manager");
    printf("\n\tWay to the folder:");

    while (j == -1)
    {
        Input(&filesPath);
        j = ListDirectoryContents(filesPath, filesName, filesSize);
    }

    filesIndex = (int*)malloc(j * sizeof(int));
    for (i = 0; i < j; i++)
        filesIndex[i] = i;

    Output(filesName, filesSize, filesIndex, j, 1);

    do
    {
        Menu(&method);
        if (method == 0) return;

        tmpSizes = (ULONGLONG*)malloc(j * sizeof(ULONGLONG));           // Выделение доп. памяти для
        for (i = 0; i < j; i++)                                         // сохранения и изменения размеров файлов
            tmpSizes[i] = filesSize[i];

        printf("\n Starting...\n Type of sort - %d.", method);
        start = clock();

        switch (method)
        {
        case 1:
            BubbleSort(tmpSizes, filesIndex, j);
            break;
        case 2:
            InsertionSort(tmpSizes, filesIndex, j);
            break;
        case 3:
            SelectionSort(tmpSizes, filesIndex, j);
            break;
        case 4:
            CountingSort(tmpSizes, filesIndex, j);
            break;
        case 5:
            QuickSort(tmpSizes, filesIndex, 0, (j - 1));
            break;
        case 6:
            QuickSort(tmpSizes, filesIndex, 0, (j - 1));
            break;
        }

        end = clock();

        Output(filesName, filesSize, filesIndex, j);
        
        printf("\n Time: %.4lf sec.\n", (double)(end - start) / CLOCKS_PER_SEC);

        for (i = 0; i < j; i++)         // Возвращение прежних индексов для новой сортировки
            filesIndex[i] = i;
        start = end = 0;
        free(tmpSizes);
    } while (1);
}
