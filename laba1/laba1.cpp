#include <iostream>
using namespace std;

int f2i(float fl) //перевод float в int
{
    long int fst[1];
    float scnd[1] = { fl };

    int sz1 = sizeof(scnd);
    int dx1 = (int(scnd) - int(fst)) / sz1;

    return (fst[dx1]);
}

long long int d2i(double fl) //перевод double в int
{
    long long int fst[1] = { 0 };
    double scnd[1] = { fl };
    int dx1 = (int(scnd) - int(fst)) / sizeof(scnd);
    return (fst[dx1]);
}

int f2iU(float inpt) //перевод float в int
{
    union chg
    {
        long int i;
        float fl;
    };

    chg t;
    t.fl = inpt;
    
    return (t.i);
}

long long int d2iU(double inpt) //перевод double в int
{
    union chg
    {
        long long int i;
        double fl;
    };

    chg t;
    t.fl = inpt;

    //cout << t.fl << " " << t.i << "\n";

    return (t.i);
}

string revers(string str) //данная функция инвертирует string
{
    string ans = "";
    for (int i = str.length(); i >= 0; i--)
    {
        ans = ans + str[i];
    }
    return(ans);
}

string i2b(int nmbr) //простая функция по переводу int в двоичный
{ 
    int lenBit = sizeof(int);
    long int mask = 1;
    string ans = "";
    for (int j = 0; j < lenBit * 8; j++)
    {
        int tmp = nmbr & mask;
        if (tmp == 0)
        {
            ans = ans + "0";
        }
        else
        {
            ans = ans + "1";
        }
        mask *= 2;
    }

    return revers(ans);
}

string i2b(long long int nmbr, int lenBit, long long int mask) //та же функция что и выше, но с доп параметрами
{
    string ans = "";
    for (int j = 0; j < lenBit*8; j++)
    {
        long long int tmp = nmbr & mask;
        if (tmp == 0)
        {
            ans = ans + "0";
        }
        else
        {
            ans = ans + "1";
        }
        mask *= 2;
    }

    return revers(ans);
}
string invert(string chislo)
{
    for (int i = 0; i < chislo.length(); i++)
        if (chislo[i] == '0')
            chislo[i] = '1';
        else chislo[i] = '0';
    return chislo;
}

long long int b2i(string chislo)
{
    int itr=0;
    long long int number = 0;
    int t,flag=0;
    if (chislo[1] == '1')
    {
        chislo = invert(chislo);
        number = 1;
        flag = 1;
    }
    for (int i = sizeof(number) * 4; i >= 0; i--)
    {
        if (chislo[i] == '1')
             t = 1;
        else t = 0;
        number = number + t*pow(2, itr);
        //cout << chislo[i] << " " << i << " " << itr << " " << number << "\n";
        itr++;
    }
    if (flag == 1)
        number = -number;
    return number;
}

int switch_bit(int number, int bit, char state)
{
    string chislo = i2b(number);
    chislo[bit] = state;
    return b2i(chislo);
}

float switch_bit(int number, int bit, char state)
{
    string chislo = i2b(number);
    chislo[bit] = state;
    return b2i(chislo);
}

void makeCool(string inpt)//эта функция выводит число с отступами каждые 8 символов
{
    //system("color 03");
    for (int i = 0; i < inpt.length(); i++)
    {
        if (i % 8 == 1)
            cout << " ";
        cout << inpt[i];
    }
    //system("color 0F");
}


int main()
{
    setlocale(LC_ALL, "RUS");

    cout << "Размер int " << sizeof(int) << "\n";
    cout << "Размер long int " << sizeof(long int) << "\n";
    cout << "Размер long long int " << sizeof(long long int) << "\n";
    cout << "Размер short int " << sizeof(short int) << "\n";
    cout << "Размер float " << sizeof(float) << "\n";
    cout << "Размер long float " << sizeof(long float) << "\n";
    cout << "Размер double " << sizeof(double) << "\n";
    cout << "Размер беззнаковых типов идентичен обыкновенным. Размеры приведены в байтах.\n";

label://эта метка нужна для корректного возвращения в начало работы алгоритма
    char control='0', control2 = '0';
    long int chiI=0, stepI=0, itr=0, mask=0;
    float chiF=0, stepF=0;
    long double chiD, stepD;
    
    /*
    for (int i = 0; i < 1000; i++)
    {
        cout << i2b(i) << "\n";
        makeCool(i2b(i));
        cout << "\n";

    }*/

    for (float i = 0; i < 0.1; i += 0.01)//этот блок нужен для проверки алгоритма, если он что то выводит, значит всё не правильно и вообще плохо
    {
        int x = f2i(i);
        int y = f2iU(i);
       if (x != y)
            cout << "ПЕПЕ УПЯЧКА! УПЯЧКА! ОБНАРУЖЕНА ОЩИБКА. ИНФОРМАЦИЯ ДЛЯ ОТЛАДКИ: " << i << " " << x << " " << y << "\n";

    }
 
    //cout << d2i(3301.3301);

    cout << "\nДанная программа представляет числа так как они существуют в ОЗУ.\nЕсть два способа перевода типа float в int: через union и массивы.\nЧтобы преобразовать число введите тип числа (для float f, для double d, для int f), а затем само число.\nЗатем введите, хотите ли входить в цикл (y/n), и если да, то укажите шаг и количество повторений, а так же маску.\nДля выхода введите любой другой символ.\n";
    cin >> control;//переменная control отвечает за то, с каким типом данных юудет работать программа
    switch (control)
    {
    case 'F':case 'f'://это тип float
    {
        cout << "Введите число и нужен ли цикл (y/n).\n";
        cin >> chiF >> control2;
        switch (control2)
        {
        case 'n'://без цикла
        {
            cout << "\nПри помощи массива:";
            makeCool(i2b(f2i(chiF)));
            cout << "\nПри помощи union:  ";
            makeCool(i2b(f2iU(chiF)));
            cout << "\n";
            goto label;
            break;
        }

        case 'y'://с циклом
        {
            cout << "Введите шаг, количество итераций и маску.\n";
            cin >> stepF >> itr >> mask ;

            if (stepF == 0)//если шаг равен 0 то выполнять это не имеет смысла, а синий экран и код ошибки добавлены как пасхалка
            {
                system("cls");
                system("color 1F");
                return 666;
            }

            for (int j = 0; j <= itr; j++)//сам цикл тут
            {
                cout << "\n" << "Итерация " << j << " из " << itr << ", число " << chiF + j * stepF ;
                cout << "\nПри помощи массива:";
                makeCool(i2b(f2i(chiF + j * stepF), sizeof(float), mask));
                cout << "\nПри помощи union:  ";
                makeCool(i2b(f2iU(chiF + j * stepF), sizeof(float), mask));
                cout << "\n";
            }
            goto label;
            break;
        }

        default: {cout << "\nВвод не распознан."; goto label; };
        }
        break;
    }

    case 'D':case 'd'://для типа double
    {
        cout << "Введите число и нужен ли цикл (y/n).\n";
        cin >> chiD >> control2;
        switch (control2)
        {
        case 'n'://без цикла
        {
            cout << "\nПри помощи массива:";
            makeCool(i2b(d2i(chiD),sizeof(double),1));
            cout << "\nПри помощи union:  ";
            makeCool(i2b(d2iU(chiD),sizeof(double), 1));
            cout << "\n";
            goto label;
            break;
        }

        case 'y'://с циклом
        {
            cout << "Введите шаг, количество итераций и маску.\n";
            cin >> stepF >> itr >> mask;

            if (stepF == 0)//если шаг равен 0 то выполнять это не имеет смысла, а синий экран и код ошибки добавлены как пасхалка
            {
                system("cls");
                system("color 1F");
                return 666;
            }

            for (int j = 0; j <= itr; j++)//сам цикл тут
            {
                cout << "\n" << "Итерация " << j << " из " << itr << ", число " << chiD + j * stepF;
                cout << "\nПри помощи массива:";
                makeCool(i2b(d2i(chiD + j * stepF), sizeof(double), mask));
                cout << "\nПри помощи union:  ";
                makeCool(i2b(d2iU(chiD + j * stepF), sizeof(double), mask));
                cout << "\n";
            }
            goto label;
            break;
        }

        default: {cout << "\nВвод не распознан."; goto label; };
        }
        break;
    }

    case 'I':case 'i'://для int
    {
        cout << "Введите число и нужен ли цикл (y/n).\n";
        cin >> chiI >> control2;
        switch (control2)
        {
        case 'n'://без цикла
        {
            cout << "\nПри помощи массива:";
            makeCool(i2b(chiI));
            cout << "\n";
            goto label;
            break;
        }

        case 'y'://с циклом
        {
            cout << "Введите шаг, количество итераций и маску.\n";
            cin >> stepI >> itr >> mask;

            if (stepI == 0)//если шаг равен 0 то выполнять это не имеет смысла, а синий экран и код ошибки добавлены как пасхалка
            {
                system("cls");
                system("color 1F");
                return 666;
            }

            for (int j = 0; j <= itr; j++)//сам цикл тут
            {
                cout << "\n" << "Итерация " << j << " из " << itr << ", число " << chiI + j * stepI;
                cout << "\nПри помощи массива:";
                makeCool(i2b(chiI + j * stepI, sizeof(int), mask));
                cout << "\n";
            }
            goto label;
            break;
        }

        default: {cout << "\nВвод не распознан."; goto label; };
        }
        break;
    }

    case 'a'://для идз
    {   string str;
       
        
    }

    default: return 0;
    }
}
