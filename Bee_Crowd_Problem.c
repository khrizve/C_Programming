/*----------1018_BANK_NOTE----------*/

#include <stdio.h>

int main()
{

    int value;
    scanf("%d", &value);
    printf("%d\n", value);
    int banknote[] = {100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 6; i++)
    {
        int nc = value / banknote[i];
        value %= banknote[i];
        printf("%d nota(s) de R$ %d,00\n", nc, banknote[i]);
    }

    return 0;
}

/*--------1019_TIME_CONVENSION--------*/

#include <stdio.h>

int main()
{

    int n, h, m, rs;
    scanf("%d", &n);
    h = n / 3600;
    m = (n % 3600) / 60;
    rs = n % 60;

    printf("%d:%d:%d\n", h, m, rs);

    return 0;
}

/*-----------1021_BANK_NOTE_AND_COIN---------------*/

#include <stdio.h>
#include <math.h>

int main()
{

    double amt;
    int note[] = {100, 50, 20, 10, 5, 2};
    int coin[] = {100, 50, 25, 10, 5, 1};
    int nc[6] = {0};
    int cc[6] = {0};
    scanf("%lf", &amt);
    int cent = amt * 100;

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++)
    {
        nc[i] = cent / (note[i] * 100);
        cent = cent % (note[i] * 100);
        printf("%d nota(s) de R$ %d.00\n", nc[i], note[i]);
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++)
    {
        cc[i] = cent / coin[i];
        cent = cent % coin[i];
        printf("%d moeda(s) de R$ %.2lf\n", cc[i], coin[i] / 100.0);
    }

    return 0;
}

/*-----------1047_GAME_TIME_WITH_MINUTE----------*/

#include <stdio.h>

int main()
{
    int ih, im, fh, fm;
    scanf("%d %d %d %d", &ih, &im, &fh, &fm);
    if (fm < im)
    {
        fm = fm + 60;
        fh = fh - 1;
        fm = fm - im;

        if (fh < ih)
        {
            fh = fh + 24;
            fh = fh - ih;
        }
        else
        {
            fh = fh - ih;
        }
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", fh, fm);
    }

    else if (fh == ih && fm == im)
    {
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    }

    else if (fm > im)
    {
        fm = fm - im;

        if (fh > ih)
        {
            fh = fh - ih;
        }
        else
        {
            fh = fh - ih;
        }

        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", fh, fm);
    }

    return 0;
}

/*--------------1049_ANIMALS----------------*/

#include <stdio.h>

int main()
{
    char a[17];
    char b[17];
    char c[17];

    scanf("%s %s %s", &a, &b, &c);
    if (a[0] == 'v' && b[0] == 'a' && c[0] == 'c')
    {
        printf("aguia\n");
    }
    else if (a[0] == 'v' && b[0] == 'a' && c[0] == 'o')
    {
        printf("pomba\n");
    }
    else if (a[0] == 'v' && b[0] == 'm' && c[0] == 'o')
    {
        printf("homem\n");
    }
    else if (a[0] == 'v' && b[0] == 'm' && c[0] == 'h')
    {
        printf("vaca\n");
    }
    else if (a[0] == 'i' && b[0] == 'i' && c[2] == 'm')
    {
        printf("pulga\n");
    }
    else if (a[0] == 'i' && b[0] == 'i' && c[2] == 'r')
    {
        printf("lagarta\n");
    }
    else if (a[0] == 'i' && b[0] == 'a' && c[0] == 'h')
    {
        printf("sanguessuga\n");
    }
    else if (a[0] == 'i' && b[0] == 'a' && c[0] == 'o')
    {
        printf("minhoca\n");
    }

    return 0;
}

/*--------------1051_TAXES---------------*/

#include <stdio.h>

int main()
{
    double money, x;

    scanf("%lf", &money);
    if (money >= 0 && money <= 2000.00)
    {
        printf("Isento\n");
    }
    else if (money >= 2000.01 && money <= 3000.00)
    {
        x = money - 2000.00;
        printf("R$ %0.2lf\n", x * 0.08);
    }
    else if (money >= 3000.01 && money <= 4500.00)
    {
        x = money - 3000.00;
        printf("R$ %0.2lf\n", x * 0.18 + 1000.00 * 0.08);
    }
    else if (money >= 4500.01)
    {
        x = money - 4500.00;
        printf("R$ %0.2lf\n", x * 0.28 + 1500.00 * 0.18 + 1000.00 * 0.08);
    }

    return 0;
}

/*------------------1060_POSITIVE_NUMBERS-----------------*/

#include <stdio.h>

int main()
{

    float n;
    int p = 0;
    for (int i = 0; i < 6; i++)
    {
        scanf("%f", &n);
        if (n >= 0)
        {
            p++;
        }
    }
    printf("%d valores positivos\n", p);

    return 0;
}

/*-------------------------1061_EVENT_TIME-----------------------*/

#include <stdio.h>
int main()
{
    int sd, sh, sm, ss, ed, eh, em, es, scal, ecal, ts, d, h, m, s;

    scanf("Dia %d", &sd);
    scanf("%d : %d : %d\n", &sh, &sm, &ss);
    scanf("Dia %d", &ed);
    scanf("%d : %d : %d", &eh, &em, &es);

    scal = ss + (sm * 60) + (sh * 3600) + (sd * 86400);
    ecal = es + (em * 60) + (eh * 3600) + (ed * 86400);

    ts = ecal - scal;

    d = ts / 86400;
    ts = ts % 86400;
    h = ts / 3600;
    ts = ts % 3600;
    m = ts / 60;
    s = ts % 60;

    printf("%d dia(s)\n", d);
    printf("%d hora(s)\n", h);
    printf("%d minuto(s)\n", m);
    printf("%d segundo(s)\n", s);

    return 0;
}

/*--------------1071_Sum_of_Consecutive_Odd _Numbers_I-----------------*/

#include <stdio.h>

int main()
{
    int x, y, sum = 0, i = 1;
    int min, max;

    scanf("%d%d", &x, &y);

    if (x < y)
    {
        min = x;
        max = y;
    }
    else
    {
        max = x;
        min = y;
    }

    for (i = min; i < max; i++)
    {
        if (i % 2 != 0)
        {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}

/*---------------1074_EVEN_OR_ODD--------------*/

#include <stdio.h>

int main()
{

    int n, N;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &N);

        if (N == 0)
        {

            printf("NULL\n");
        }
        else if (N < 0 && N % 2 != 0)
        {

            printf("ODD NEGATIVE\n");
        }

        else if (N > 0 && N % 2 != 0)
        {

            printf("ODD POSITIVE\n");
        }
        else if (N < 0 && N % 2 == 0)
        {

            printf("EVEN NEGATIVE\n");
        }
        else if (N > 0 && N % 2 == 0)
        {

            printf("EVEN POSITIVE\n");
        }
    }

    return 0;
}

/*-------------1075_REMAINING_2-------------------*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 10000; i++)
    {
        if (i % n == 2)
        {

            printf("%d\n", i);
        }
    }
    return 0;
}

/*--------------1078_MULTIPLICATION_TABLE----------------*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 11; i++)
    {
        printf("%d x %d = %d\n", i, n, n * i);
    }
}

/*----------------1114_FIXED_PASSWORD-------------*/

#include <stdio.h>

int main()
{
    int password;
label:
    scanf("%d", &password);
    if (password == 2002)
    {
        printf("Acesso Permitido\n");
        goto end;
    }

    else
    {
        printf("Senha Invalida\n");
        goto label;
    }

end:
    return 0;
}

/*---------------1115_QUADRANT----------------*/

#include <stdio.h>

int main()
{
    int x, y;
lebel:
    scanf("%d %d", &x, &y);

    if (x > 0 && y > 0)
    {
        printf("primeiro\n");
        goto lebel;
    }
    else if (x > 0 && y < 0)
    {
        printf("quarto\n");
        goto lebel;
    }
    else if (x < 0 && y > 0)
    {
        printf("segundo\n");
        goto lebel;
    }
    else if (x < 0 && y < 0)
    {
        printf("terceiro\n");
        goto lebel;
    }
    else if (x == 0 || y == 0)
    {
        goto end;
    }
end:
    return 0;
}

/*----------1134_TYPE_OF_FUEL-----------*/

#include <stdio.h>

int main()
{

    int alcohol = 0, gasolin = 0, disel = 0;
    int code;
lebel:
    scanf("%d", &code);
    if (code == 1)
    {
        alcohol++;
        goto lebel;
    }
    if (code == 2)
    {
        gasolin++;
        goto lebel;
    }
    if (code == 3)
    {
        disel++;
        goto lebel;
    }
    if (code == 4)
    {
        goto end;
    }
    if (code > 4)
    {
        goto lebel;
    }

end:

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcohol);
    printf("Gasolina: %d\n", gasolin);
    printf("Diesel: %d\n", disel);
    return 0;
}

/*-----------------1117_SCORE_VALIDATION-----------------*/

#include <stdio.h>

int main()
{
    double score, sum = 0, count = 0;

    while (count < 2)
    {
        scanf("%lf", &score);
        if (score >= 0 && score <= 10)
        {
            sum += score;
            count++;
        }
        else
        {
            printf("nota invalida\n");
        }
    }

    printf("media = %0.2lf\n", sum / 2);

    return 0;
}

/*---------------1095_SEQUENCE_IJ_1-----------------*/

#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1, j = 60; i <= 37, j >= 0; i += 3, j -= 5)
    {
        printf("I=%d J=%d\n", i, j);
    }
    return 0;
}

/*---------------1133_REST_OF_A_DIVISION---------------*/

#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y)
    {
        int z = x;
        x = y;
        y = z;
    }
    for (int num = x + 1; num < y; num++)
    {
        if (num % 5 == 2 || num % 5 == 3)
        {
            printf("%d\n", num);
        }
    }

    return 0;
}

/*-------------1080_HIGHEST_AND_POSITION----------------*/

#include <stdio.h>

int main()
{
    int numbers[100];
    int highest_value = 0;
    int highest_position = 0;

    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &numbers[i]);

        if (numbers[i] > highest_value)
        {
            highest_value = numbers[i];
            highest_position = i + 1;
        }
    }

    printf("%d\n", highest_value);
    printf("%d\n", highest_position);

    return 0;
}

/*----------1157_DIVISORS_1---------------*/

#include <stdio.h>

int main()
{
    int num, a;
    scanf("%d", &num);
    for (a = 1; a <= num; a++)
    {
        if (num % a == 0)
            printf("%d\n", a);
    }
    return 0;
}

/*----------1150_EXEEDING_Z------------*/

#include <stdio.h>

int main()
{
    int X, Z, sum = 0, count = 0;

    scanf("%d", &X);

    do
    {
        scanf("%d", &Z);
    } while (Z <= X);

    while (sum <= Z)
    {
        sum += X + count;
        count++;
    }

    printf("%d\n", count);

    return 0;
}

/*-----------------1094_EXPERIMENTS---------------------*/

#include <stdio.h>

int main()
{
    int n, x, total = 0, c = 0, r = 0, s = 0;
    char animal;
    float poc, por, pos;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &x, &animal);
        total += x;
        if (animal == 'C')
        {
            c += x;
        }
        else if (animal == 'R')
        {
            r += x;
        }
        else if (animal == 'S')
        {
            s += x;
        }
    }
    poc = ((float)c / (float)total) * 100;
    por = ((float)r / (float)total) * 100;
    pos = ((float)s / (float)total) * 100;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", c);
    printf("Total de ratos: %d\n", r);
    printf("Total de sapos: %d\n", s);
    printf("Percentual de coelhos: %0.2f %%\n", poc);
    printf("Percentual de ratos: %0.2f %%\n", por);
    printf("Percentual de sapos: %0.2f %%\n", pos);

    return 0;
}

/*------------2060_BINO'S_CHALLENGE-----------*/

#include <stdio.h>

int main()
{
    int N, num, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);

        if (num % 2 == 0)
            count_2++;
        if (num % 3 == 0)
            count_3++;
        if (num % 4 == 0)
            count_4++;
        if (num % 5 == 0)
            count_5++;
    }

    printf("%d Multiplo(s) de 2\n", count_2);
    printf("%d Multiplo(s) de 3\n", count_3);
    printf("%d Multiplo(s) de 4\n", count_4);
    printf("%d Multiplo(s) de 5\n", count_5);

    return 0;
}

/*-----------------1198_Hashmat_the_Brave_Warrior----------------------*/

#include <stdio.h>

int main()
{
    long long int hashmat_army, opponent_army, difference;

    while (scanf("%lld", &hashmat_army) != EOF)
    {
        scanf("%lld", &opponent_army);

        if (hashmat_army > opponent_army)
        {
            difference = hashmat_army - opponent_army;
        }
        else
        {

            difference = opponent_army - hashmat_army;
        }

        printf("%lld\n", difference);
    }

    return 0;
}

/*-----------------1805_Natural_Sum------------------*/

#include <stdio.h>

int main()
{
    long long A, B;

    scanf("%lld %lld", &A, &B);

    long long sum = (B * (B + 1) / 2) - ((A - 1) * A / 2);

    printf("%lld\n", sum);

    return 0;
}

/*--------------------2748_OIUTPUT_2---------------------------*/

#include <stdio.h>

int main()
{

    printf("---------------------------------------\n");
    printf("|        Roberto                      |\n");
    printf("|                                     |\n");
    printf("|        5786                         |\n");
    printf("|                                     |\n");
    printf("|        UNIFEI                       |\n");
    printf("---------------------------------------\n");

    return 0;
}

/*--------------------2755_OutPut_9------------------------*/

#include <stdio.h>

int main()
{

    printf("\"Ro'b'er\tto\\/\"\n");
    printf("(._.) ( l: ) ( .-. ) ( :l ) (._.)\n");
    printf("(^_-) (-_-) (-_^)\n");
    printf("(\"_\") ('.')\n");
    return 0;
}

/*-----------2764_Date_Input_And_Output--------------------*/

#include <stdio.h>

int main()
{

    int d, m, y;
    char a, b;
    scanf("%d %c %d %c %d", &d, &a, &m, &b, &y);
    printf("%02d/%02d/%02d\n", m, d, y);
    printf("%02d/%02d/%02d\n", y, m, d);
    printf("%02d-%02d-%02d\n", d, m, y);

    return 0;
}

/*--------------------2759_Input_And_Output_Charactar--------------------*/

#include <stdio.h>

int main()
{
    char x, y, z;

    scanf("%c %c %c", &x, &y, &z);

    printf("A = %c, B = %c, C = %c\n", x, y, z);
    printf("A = %c, B = %c, C = %c\n", y, z, x);
    printf("A = %c, B = %c, C = %c\n", z, x, y);

    return 0;
}

/*------------------1866_BILL--------------------*/

#include <stdio.h>

int main()
{
    int c;
    scanf("%d", &c);

    while (c--)
    {
        int n;
        scanf("%d", &n);

        int result;

        if (n % 2 == 0)
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
        printf("%d\n", result);
    }

    return 0;
}

/*-------------------1585_Making_Kites---------------------*/

#include <stdio.h>

int main()
{
    int n, x, y, area;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        area = 0.5 * (x * y);
        printf("%d cm2\n", area);
    }

    return 0;
}

/*---------------------1165_Prime_Number----------------------*/

#include <stdio.h>

int main()
{
    long int n, x, j, count;
    scanf("%ld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &x);

        count = 0;

        for (j = 1; j <= x; j++)
        {

            if (x % j == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            printf("%d eh primo\n", x);
        }
        else
        {
            printf("%d nao eh primo\n", x);
        }
    }
    return 0;
}

/*-----------------2456_Cards----------------*/

#include <stdio.h>

int main()
{
    int n[6];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &n[i]);
    }
    if (n[0] < n[1] && n[1] < n[2] && n[2] < n[3] && n[3] < n[4])
    {
        printf("C\n");
    }
    else if (n[0] > n[1] && n[1] > n[2] && n[2] > n[3] && n[3] > n[4])
    {
        printf("D\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}

/*------------2987_Balloon_of_Honor-------------*/

#include <stdio.h>

int main()
{
    char alpha;
    scanf("%c", &alpha);
    switch (alpha)
    {
    case 'A':
        printf("1\n");
        break;
    case 'B':
        printf("2\n");
        break;
    case 'C':
        printf("3\n");
        break;
    case 'D':
        printf("4\n");
        break;
    case 'E':
        printf("5\n");
        break;
    case 'F':
        printf("6\n");
        break;
    case 'G':
        printf("7\n");
        break;
    case 'H':
        printf("8\n");
        break;
    case 'I':
        printf("9\n");
        break;
    case 'J':
        printf("10\n");
        break;
    case 'K':
        printf("11\n");
        break;
    case 'L':
        printf("12\n");
        break;
    case 'M':
        printf("13\n");
        break;
    case 'N':
        printf("14\n");
        break;
    case 'O':
        printf("15\n");
        break;
    case 'P':
        printf("16\n");
        break;
    case 'Q':
        printf("17\n");
        break;
    case 'R':
        printf("18\n");
        break;
    case 'S':
        printf("19\n");
        break;
    case 'T':
        printf("20\n");
        break;
    case 'U':
        printf("21\n");
        break;
    case 'V':
        printf("22\n");
        break;
    case 'W':
        printf("23\n");
        break;
    case 'X':
        printf("24\n");
        break;
    case 'Y':
        printf("25\n");
        break;
    case 'Z':
        printf("26\n");
        break;
    }
    return 0;
}

/*--------------3040_The_Christmas_Tree-----------------*/

#include <stdio.h>

int main()
{
    int n, h, d, g;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &h, &d, &g);
        if ((h >= 200 && h <= 300) && (d >= 50) && (g >= 150))
        {
            printf("Sim\n");
        }
        else
        {
            printf("Nao\n");
        }
    }

    return 0;
}

/*------------1170_Blobs--------------*/

#include <stdio.h>

int main()
{
    int n, days;
    float x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x);
        days = 0;
        while (x > 1)
        {
            x /= 2;
            days++;
        }
        printf("%d dias\n", days);
    }

    return 0;
}

/*----------1168_LEDS------------*/

#include <stdio.h>

int main()
{
    int n, j;
    char num[101];
    long long leds;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &num);
        j = 0;
        leds = 0;
        while (1)
        {
            if (num[j] == '\0')
                break;
            if (num[j] == '1')
                leds += 2;
            if (num[j] == '2')
                leds += 5;
            if (num[j] == '3')
                leds += 5;
            if (num[j] == '4')
                leds += 4;
            if (num[j] == '5')
                leds += 5;
            if (num[j] == '6')
                leds += 6;
            if (num[j] == '7')
                leds += 3;
            if (num[j] == '8')
                leds += 7;
            if (num[j] == '9')
                leds += 6;
            if (num[j] == '0')
                leds += 6;
            j++;
        }
        printf("%lld leds\n", leds);
    }
    return 0;
}

/*------------1957_converting_to_Hexadecimal----------------*/

#include <stdio.h>

void decimalToHexadecimal(int decimalNumber)
{
    int remainder;
    int quotient = decimalNumber;
    int i = 0;
    char hexadecimalNumber[100];

    while (quotient != 0)
    {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimalNumber[i++] = remainder + '0';
        else
            hexadecimalNumber[i++] = remainder + 'A' - 10;

        quotient /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}

int main()
{
    int decimalNumber;

    scanf("%d", &decimalNumber);

    decimalToHexadecimal(decimalNumber);

    return 0;
}

/*---------2787_CHESS--------------*/

#include <stdio.h>

int main()
{
    int L, C;
    scanf("%d %d", &L, &C);

    if ((L % 2 == 0 && C % 2 == 0) || (L % 2 != 0 && C % 2 != 0))
    {
        printf("1\n"); // White
    }
    else
    {
        printf("0\n"); // Black
    }

    return 0;
}

// /*--------------------1101_Sequence_of_Numbers_and_Sum------------*/

#include <stdio.h>

int main()
{
    int a, b, min, max;

    while (1)
    {
        scanf("%d %d", &a, &b);
        int sum = 0;

        if (a <= 0 || b <= 0)
        {
            break;
        }
        if (a > b)
        {
            min = b;
            max = a;
        }
        else
        {
            min = a;
            max = b;
        }
        for (int i = min; i <= max; i++)
        {
            sum += i;
            printf("%d ", i);
        }

        printf("Sum=%d\n", sum);
    }
    return 0;
}

/*----------------1858_Theon's_Answer----------------*/

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int T[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &T[i]);
    }

    int minHits = T[0];
    int answer = 1;

    for (int i = 1; i < N; i++)
    {
        if (T[i] < minHits)
        {
            minHits = T[i];
            answer = i + 1;
        }
    }

    printf("%d\n", answer);

    return 0;
}

/*-------------- 2863_Umil_Bolt----------------*/

#include <stdio.h>

int main()
{
    int t;
    while (scanf("%d", &t) != EOF)
    {
        double fast = 11.0;
        for (int i = 0; i < t; i++)
        {
            double time;
            scanf("%lf", &time);
            if (time < fast)
            {
                fast = time;
            }
        }
        printf("%.2lf\n", fast);
    }
    return 0;
}

/*--------------------2674_Super_Primes:_Engage!----------------*/

#include <stdio.h>

int prime_num(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int prime_digits(int num)
{
    while (num > 0)
    {
        int digit = num % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7)
        {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        if (prime_num(n))
        {
            if (prime_digits(n))
            {
                printf("Super\n");
            }
            else
            {
                printf("Primo\n");
            }
        }
        else
        {
            printf("Nada\n");
        }
    }

    return 0;
}

/*-----------------2840_Balloon++-----------------*/

#include <stdio.h>

int main()
{
    int r, l;
    scanf("%d %d", &r, &l);

    double volume = (4.0 / 3.0) * 3.1415 * r * r * r;

    int balloons = (int)(l / volume);

    printf("%d\n", balloons);

    return 0;
}

/*-------------------2140_Two_Bills-------------------*/

#include <stdio.h>

int possible(int change)
{
    int bills[] = {2, 5, 10, 20, 50, 100};
    int bills_num = sizeof(bills) / sizeof(bills[0]);

    for (int i = 0; i < bills_num; i++)
    {
        for (int j = i + 1; j < bills_num; j++)
        {
            if (bills[i] + bills[j] == change)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m;

    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }

        int cng = m - n;
        if (possible(cng))
        {
            printf("possible\n");
        }
        else
        {
            printf("impossible\n");
        }
    }

    return 0;
}

/*-----------------------2029_Honey_Reservoir-----------------*/

#include <stdio.h>

int main()
{
    double V, D, r, h, A;

    while (scanf("%lf %lf", &V, &D) != EOF)
    {
        r = D / 2.0;
        A = 3.14 * r * r;
        h = V / A;

        printf("ALTURA = %.2f\n", h);
        printf("AREA = %.2f\n", A);
    }

    return 0;
}

/*------------------2058_Triangles_and_Regular_Polygons-----------*/

#include <stdio.h>

int main()
{
    long long N;

    if (scanf("%lld", &N) != 1)
    {
        return 1;
    }

    long long int numOfTriangles = N - 2;

    printf("%lld\n", numOfTriangles);

    return 0;
}

/*---------------2758_Floating_Number_Input_and_Output--------------*/

#include <stdio.h>

int main()
{

    float a, b;
    double c, d;

    scanf("%f %f", &a, &b);
    scanf("%lf %lf", &c, &d);

    printf("A = %f, B = %f\n", a, b);
    printf("C = %lf, D = %lf\n", c, d);
    printf("A = %.1f, B = %.1f\n", a, b);
    printf("C = %.1lf, D = %.1lf\n", c, d);
    printf("A = %.2f, B = %.2f\n", a, b);
    printf("C = %.2lf, D = %.2lf\n", c, d);
    printf("A = %.3f, B = %.3f\n", a, b);
    printf("C = %.3lf, D = %.3lf\n", c, d);
    printf("A = %.3E, B = %.3E\n", a, b);
    printf("C = %.3E, D = %.3E\n", c, d);
    printf("A = %.0f, B = %.0f\n", a, b);
    printf("C = %.0lf, D = %.0lf\n", c, d);

    return 0;
}

/*------------------1768_Christmas_Tree-----------------*/

#include <stdio.h>

int main()
{

    int t, i, j, z;

    while (scanf("%d", &t) != EOF)
    {

        for (i = 0; i < t; i += 2)
        {
            for (j = 0; j < (t - i) / 2; j++)
                printf(" ");

            for (z = i; z >= 0; z--)
                printf("*");

            printf("\n");
        }

        for (i = 0; i < t / 2; i++)
            printf(" ");
        printf("*\n");

        for (i = 1; i < t / 2; i++)
            printf(" ");

        printf("***\n\n");
    }

    return 0;
}
