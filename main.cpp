#pragma once 
#include <iostream> 
#include "Bin.h" 
using namespace std; 
#define N 10 

void main() 
{ 
int *a = new int[N]; 
int *b = new int[N]; 
Gen(a, N, 10.0); 
Print(a, N); 

FILE *mass = fopen("C:\mass.bin", "wb"); 
if (mass != NULL) 
{ 
fwrite(&a, sizeof(a[0]), N, mass); 
cout « mass « endl; 
fclose(mass); 
} 
else 
{ 
cout « "error"; 
} 
fopen("C:\mass.bin", "rb"); 
fread(&b, sizeof(b[0]), N, mass); 
for(int i = 0; i < N; i++) 
cout « b[i]; 

fclose(mass); 

Choose_Sort(b, N); 
Print(b, N); 
delete a; 
delete b; 
}