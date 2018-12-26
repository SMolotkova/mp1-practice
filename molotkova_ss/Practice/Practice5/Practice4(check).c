#include <stdio.h> 
#define N 4 
int scan(int dop[], int quantity[], int dlya_dop) // ââåëè øòðèõêîä è êîëè÷åñòâî òîâàðà
{
    int i;
    do
    {
        printf("Ââåäèòå øòðèõêîä\n");
        scanf("%d", &dop[dlya_dop]);
    }
    while ((dop[dlya_dop] >N) || (dop[dlya_dop] <1));
    printf("\nÂâåäèòå êîëè÷åñòâî\n");
    scanf("%d", &i); //êîëè÷åñòâî òåêóùåãî òîâàðà
    return i; //ñîõðàíÿåòñÿ
}
void description(char names[][10], int prices[], int discounts[], int i)// ïîñëåäíåå-íîìåð øòðèõêîäà âûâîä îïèñàíèÿ
{
    int j;
    for(j = 0; j < 10; j++)
        printf("%c", names[i][j]);
    printf("price=%d discount=%d\n", prices[i], discounts[i]);
}    
void adding (int quantity[], int n, int z)// ìàññèâ êîëè÷åñòâî, íîìåð øòðèõêîäà, êîëè÷åñòâî òîâàðà
{
    quantity[n] += z;
}
void check_formation(char names[][10], int prices[], int discounts[], int quantity[])
{
    int a = 0;// ñòîèìîñòü îáùàÿ áåç ñêèäîê
    int b = 0;// ñòîèìîñòü ñî ñêèäêàìè
    int i;// ñ÷åò÷èê 
    for(i = 0; i < N; i++)
    {
        if (quantity[i] > 0){
        description(names, prices, discounts, i);
        printf("Êîëè÷åñòâî=%d", quantity[i]);
        a = a + quantity[i] * prices[i];
        b = b + prices[i] * 0.01 * (100 - discounts[i]) * quantity[i];}
    }
    printf ("Ñòîèìîñòü áåç ñêèäîê=%d\n Ñòîèìîñòü ñî ñêèäêàìè=%d\n Îáùàÿ ñêèäêà=%d\n", a,b, (a-b)*100/a);
}
void main ()
{//ÁÀÇÀ
    char names[N][10] = {"          ", "milk      ", "bread     ", "fish      "};
    int prices[N] = {0, 68, 21, 170};
    int discounts[N] = {0, 10, 15, 5};
    int quantity[N] = {0};//êîëè÷åñòâî
    int dop[10];
    int p;//çíà÷åíèÿ êîìàíäû
    int q;//êîëè÷åñòâî òåêóùåãî òîâàðà
    int dlya_dop = 0;//ñ÷åò÷èê ñêàíîâ îäíîãî òîâàðà
    q = scan(dop, quantity, dlya_dop);
    do
    {
        printf("1-ñêàíèðîâàòü\n 2-âûâåñòè îïèñàíèå\n 3-äîáàâèòü â ÷åê\n 4-ñôîðìèðîâàòü ÷åê\n 5- ïîäâåñòè èòîã\n");
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
