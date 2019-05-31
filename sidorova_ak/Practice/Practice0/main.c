#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
    float x1, y1, r1, x2, y2, r2, d; // d-расстояние между центрами окружностей
    setlocale(LC_ALL, "Russian");

    printf("Введите координаты первой окружности и ее радиус: ");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Введите координаты второй окружности и ее радиус: ");
    scanf("%f %f %f", &x2, &y2, &r2);

    d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
    printf("Окружности полностью совпадают.\n");
        return;
    }
    if ((x1 == x2) && (y1 == y2) && ((r1 > r2) || (r1 < r2)))
    {
        printf("Центры окружностей совпадают, а одна из окружностей лежит в первой.\n");
        return;
    }
    if (d > (r1 + r2))
    {
        printf("Окружности полностью не пересекаются и не касаются, ни одна из окружностей не находится в другой.\n");
        return;
    }
    if (d == (r1 + r2))
    {
        printf("Окружности касаются внешним образом.\n");
        return;
    }
    if (((d + r1) == r2) || ((d + r2) == r1))
    {
        printf("Окружности полностью касаются, причем одна из окружностей внешне касается с другой, т.е. одна лежит внутри второй окружности.\n");
        return;
    }
    if ((d < (r1 - r2)) || (d < (r2 - r1)))
    {
        printf("Одна окружность находится внутри другой, и они не пересекаются.\n");
        return;
    }
    
    printf("Окружности пересекаются и имеют две общие точки.\n");
}