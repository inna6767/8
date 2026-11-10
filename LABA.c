#include <stdio.h>
#include <locale.h>

 //Задание 0 

void print_chars(int n, char c)
{
    for (int i = 1; i <= n; i++)
        putchar(c);
}

//* 
void variant1(void)
{
    int n, border;
    char c;

    printf("Сколько символов напечатать? ");
    scanf("%d", &n);
    printf("Какой символ печатать? ");
    scanf(" %c", &c);
    printf("Где печатать '+' (0 - нигде, 1 - в начале, 2 - в конце, 3 - с обеих сторон)? ");
    scanf("%d", &border);

    if (border == 1 || border == 3)
        putchar('+');

    print_chars(n, c);

    if (border == 2 || border == 3)
        putchar('+');

    putchar('\n');
}

 //**
void variant2(void)
{
    int n;
    char c1, c2;

    printf("Сколько символов напечатать? ");
    scanf("%d", &n);
    printf("Первый символ: ");
    scanf(" %c", &c1);
    printf("Второй символ: ");
    scanf(" %c", &c2);

    for (int i = 1; i <= n; i++)
        putchar(i <= n / 2 ? c1 : c2);

    putchar('\n');
}

//***
void variant3(void)
{
    int n;
    char c;

    printf("Сколько символов напечатать? ");
    scanf("%d", &n);
    printf("Какой символ печатать? ");
    scanf(" %c", &c);

    for (int i = 1; i <= n; i++)
        printf("%c!", c);

    putchar('\n');
}

 //Задание 1

void sum_task(void)
{
    int m, n;          
    int s = 0, k = 0; 

    printf("Введите m: ");    
    scanf("%d", &m);
    printf("Введите n: ");
    scanf("%d", &n);

    if (m < n)                
    {
        int t = m;
        m = n;
        n = t;
    }

    for (int i = m; i >= n; i--)
    {
        s += i;                              
        printf("выполнено %d раз\n", ++k);   
    }

    printf("результат %d\n", s);             
}
double f(double x)
{
    return 5 * x * x * x + 2 * x * x - 15 * x - 6;
}

void tabulation_task(void)
{
    double xn, xk, h; 
//Задание 2
    printf("Табулирование функции y = 5x^3 + 2x^2 - 15x - 6\n\n");

    printf("Введите начало отрезка a: ");
    scanf("%lf", &xn);
    printf("Введите конец отрезка b: ");
    scanf("%lf", &xk);
    printf("Введите шаг табуляции h: ");  
    scanf("%lf", &h);
    printf("\n+------------+------------+\n");
    printf("|     x      |    f(x)    |\n");
    printf("+------------+------------+\n");

    int steps = (int)((xk - xn) / h + 0.5);

    for (int i = 0; i <= steps; i++)
    {
        double x = xn + i * h;
        printf("| %10.4f | %10.4f |\n", x, f(x));
        printf("+------------+------------+\n");
    }
}

//Меню

int main(void)
{
    int choice;

    setlocale(LC_ALL, "ru_RU.UTF-8");

    do
    {
        printf("\n===== МЕНЮ =====\n");
        printf("1 - печать символов (задание 0)\n");
        printf("2 - печать с '+' в начале/конце (*)\n");
        printf("3 - печать двумя разными символами (**)\n");
        printf("4 - печать с '!' после каждого символа (***)\n");
        printf("5 - сумма целых чисел от m до n (задание 1)\n");
        printf("6 - табулирование функции (задание 2, вариант 11)\n");
        printf("0 - выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int n;
            char c;
            printf("Сколько символов напечатать? ");
            scanf("%d", &n);
            printf("Какой символ печатать? ");
            scanf(" %c", &c);
            print_chars(n, c);
            putchar('\n');
        }
        else if (choice == 2)
            variant1();
        else if (choice == 3)
            variant2();
        else if (choice == 4)
            variant3();
        else if (choice == 5)
            sum_task();
        else if (choice == 6)
            tabulation_task();

    } while (choice != 0);

    printf("Программа завершена.\n");
    return 0;
}
