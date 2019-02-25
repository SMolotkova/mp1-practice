#pragma once 
#include <iostream> 
#include <time.h> 
#include "Bin.h" 
using namespace std; 

void Choose_Sort(int *b, int N) { 
int i, j, min, min_ind; 
for (i = 0; i < N; i++) { 
min = b[i]; 
min_ind = i; 
for (j = i + 1; j < N; j++) { 
if (b[j] < min) { 
min = b[j]; 
min_ind = j; 
} 
} 
b[min_ind] = b[i]; 
b[i] = min; 
} 
} 

void Gen(int *a, int N, double max) 
{ 
int i; 
srand((unsigned int)time(0)); 
for (i = 0; i < N; i++) 
a[i] = max / RAND_MAX * rand() + 1; 
} 

void Print(int *a, int N) 
{ 
for(int i = 0; i < N; i++) 
cout « a[i] « " "; 
cout « endl; 
}