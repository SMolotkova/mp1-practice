#include <stdio.h> 
#define N 4 
int scan(int dop[], int quantity[], int dlya_dop) // ввели штрихкод и количество товара
{
    int i;
    do
    {
        printf("Введите штрихкод\n");
        scanf("%d", &dop[dlya_dop]);
    }
    while ((dop[dlya_dop] >N) || (dop[dlya_dop] <1));
    printf("\nВведите количество\n");
    scanf("%d", &i); //количество текущего товара
    return i; //сохраняется
}
void description(char names[][10], int prices[], int discounts[], int i)// последнее-номер штрихкода вывод описания
{
    int j;
    for(j = 0; j < 10; j++)
        printf("%c", names[i][j]);
    printf("price=%d discount=%d\n", prices[i], discounts[i]);
}    
void adding (int quantity[], int n, int z)// массив количество, номер штрихкода, количество товара
{
    quantity[n] += z;
}
void check_formation(char names[][10], int prices[], int discounts[], int quantity[])
{
    int a = 0;// стоимость общая без скидок
    int b = 0;// стоимость со скидками
    int i;// счетчик 
    for(i = 0; i < N; i++)
    {
        if (quantity[i] > 0){
        description(names, prices, discounts, i);
        printf("Количество=%d", quantity[i]);
        a = a + quantity[i] * prices[i];
        b = b + prices[i] * 0.01 * (100 - discounts[i]) * quantity[i];}
    }
    printf ("Стоимость без скидок=%d\n Стоимость со скидками=%d\n Общая скидка=%d\n", a,b, (a-b)*100/a);
}
void main ()
{//БАЗА
    char names[N][10] = {"          ", "milk      ", "bread     ", "fish      "};
    int prices[N] = {0, 68, 21, 170};
    int discounts[N] = {0, 10, 15, 5};
    int quantity[N] = {0};//количество
    int dop[10];
    int p;//значения команды
    int q;//количество текущего товара
    int dlya_dop = 0;//счетчик сканов одного товара
    q = scan(dop, quantity, dlya_dop);
    do
    {
        printf("1-сканировать\n 2-вывести описание\n 3-добавить в чек\n 4-сформировать чек\n 5- подвести итог\n");
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
