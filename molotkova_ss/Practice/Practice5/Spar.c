#include <stdio.h> 
#define N 4 
int scan(int dop[], int quantity[], int dlya_dop) // ����� �������� � ���������� ������
{
    int i;
    do
    {
        printf("������� ��������\n");
        scanf("%d", &dop[dlya_dop]);
    }
    while ((dop[dlya_dop] >N) || (dop[dlya_dop] <1));
    printf("\n������� ����������\n");
    scanf("%d", &i); //���������� �������� ������
    return i; //�����������
}
void description(char names[][10], int prices[], int discounts[], int i)// ���������-����� ��������� ����� ��������
{
    int j;
    for(j = 0; j < 10; j++)
        printf("%c", names[i][j]);
    printf("price=%d discount=%d\n", prices[i], discounts[i]);
}    
void adding (int quantity[], int n, int z)// ������ ����������, ����� ���������, ���������� ������
{
    quantity[n] += z;
}
void check_formation(char names[][10], int prices[], int discounts[], int quantity[])
{
    int a = 0;// ��������� ����� ��� ������
    int b = 0;// ��������� �� ��������
    int i;// ������� 
    for(i = 0; i < N; i++)
    {
        if (quantity[i] > 0){
        description(names, prices, discounts, i);
        printf("����������=%d", quantity[i]);
        a = a + quantity[i] * prices[i];
        b = b + prices[i] * 0.01 * (100 - discounts[i]) * quantity[i];}
    }
    printf ("��������� ��� ������=%d\n ��������� �� ��������=%d\n ����� ������=%d\n", a,b, (a-b)*100/a);
}
void main ()
{//����
    char names[N][10] = {"          ", "milk      ", "bread     ", "fish      "};
    int prices[N] = {0, 68, 21, 170};
    int discounts[N] = {0, 10, 15, 5};
    int quantity[N] = {0};//����������
    int dop[10];
    int p;//�������� �������
    int q;//���������� �������� ������
    int dlya_dop = 0;//������� ������ ������ ������
    q = scan(dop, quantity, dlya_dop);
    do
    {
        printf("1-�����������\n 2-������� ��������\n 3-�������� � ���\n 4-������������ ���\n 5- �������� ����\n");
        scanf("%d", &p);
        switch(p)
        {
            case 1:
                q = scan(dop, quantity, dlya_dop);
                break;
            case 2:
                description(names, prices, discounts, dop[dlya_dop]);
                break;
            case 3:
                adding(quantity, dop[dlya_dop], q);
                dlya_dop++;
                break;
            case 4:
                check_formation(names, prices, discounts, quantity);
                break;
            case 5:   
                check_formation(names, prices, discounts, quantity);
                break;
        }
    }
    while(p != 5);
}
