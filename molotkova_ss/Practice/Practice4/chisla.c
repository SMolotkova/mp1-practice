#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 //������ ������
void main() {
	int rezhim;
    printf("�������� �����(1 ��� 2)");
	scanf ("%d", &rezhim);
if(rezhim==1)
{	srand(time(NULL));
    int n,u,i,m;
    n = rand() % 1000;
    i = 1;
   do {
        printf("%d-� �������: ", i);
        scanf("%d", &u);
        if (u < n) printf("����\n");
        else
        if (u > n) printf("�����\n");
        else {
        printf("�������!\n ������� %d\n", i);
        break;
            }
        i += 1;
        }while(u!=n);
}
else {
int m,z,a=1,b=1001,j=0;
char otvet;
srand((unsigned int)time(0));
do{
	printf("������� �����\n");
	scanf( "%d", &m);
}while ((0>m)&&(m>1000));
do{ 
	z=((double)(b-a))/RAND_MAX*rand()+a; 
	printf("����� %d", z);
	scanf("%s", &otvet);
switch (otvet) {
	case '>':
		a=z;
		break;
	case '<':
		b=z;
		break;
	case '=':
		printf("���������� ����� %d \n", z);
		break;}
j++;
}
while(z!=m);
printf("���� ������� %d \n",j);
}
}
