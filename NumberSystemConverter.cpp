/// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double
#define st string
#define ch char
#define cn(n) cin >> n
#define cll(n)   \
    long long n; \
    cin >> n
#define cdl(n) \
    double n;  \
    cin >> n
#define cst(s) \
    string s;  \
    cin >> s
#define ct(n) cout << n
#define w(n) while (n > 0)
#define elif else if
#define wh(n)    \
    long long n; \
    cin >> n;    \
    while (n--)
#define a(m, n)                 \
    long long a[n];             \
    for (int i = m; i < n; i++) \
    cin >> a[i]
#define b(m, n)                  \
    long long b[n];              \
    for (int i = m; i <= n; i++) \
    b[i] = 0
#define f(m, i, n) for (int i = m; i < n; i++)
#define fr(m, i, n) for (int i = m - 1; i >= n; i--)
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define bye cout << endl

st from, to;
ch first_symbol, last_symbol;
ll base;
bool valid = true;

int from_decimal(st main_number)
{
    if (to == "bin")
        base = 2;
    elif (to == "oct") base = 8;
    elif (to == "hex") base = 16;
    stringstream temp(main_number);
    dl number = 0;
    temp >> number;
    ll rem, remm, extra, extraa, ascii, asciii;
    ll int_part = (ll)number;
    dl flt_part = number - int_part;
    ch converted_number[500], k = 0;
    if (int_part == 0)
        ct(0);
    else
    {
        w(int_part)
        {
            rem = int_part % base;
            int_part /= base;
            if (rem > 9)
            {
                extra = rem - 9;
                ascii = 64 + extra;
            }
            else
                ascii = 48 + rem;
            converted_number[k++] = ch(ascii);
        }
        fr(k, i, 0) ct(converted_number[i]);
    }
    ct(".");
    f(0, i, 8)
    {
        flt_part *= base;
        remm = (ll)flt_part;
        if (remm > 9)
        {
            extraa = remm - 9;
            asciii = 64 + extraa;
        }
        else
            asciii = 48 + remm;
        ct(ch(asciii));
        flt_part -= (ll)flt_part;
    }
}

int to_decimal(st main_number)
{
    if (from == "bin")
        base = 2;
    elif (from == "oct") base = 8;
    elif (from == "hex") base = 16;
    bool flag = true;
    ll k = 0, point = 0, converted_int, converted_flt, extra;
    dl converted_number = 0;
    f(0, i, main_number.size())
    {
        if (main_number[i] == '.')
        {
            point = i;
            flag = false;
            break;
        }
    }
    if (flag)
        point = main_number.size();
    f(0, i, point)
    {
        if (main_number[i] >= '0' && main_number[i] <= '9')
            converted_int = main_number[i] - '0';
        else
        {
            extra = (ll)main_number[i] - 64;
            converted_int = 9 + extra;
        }
        converted_number += converted_int * pow(base, point - i - 1);
    }
    f(point + 1, i, main_number.size())
    {
        k--;
        if (main_number[i] >= '0' && main_number[i] <= '9')
            converted_flt = main_number[i] - '0';
        else
        {
            extra = (ll)main_number[i] - 64;
            converted_flt = 9 + extra;
        }
        converted_number += converted_flt * pow(base, k);
    }
    ct(converted_number);
}

int to_binary(st main_number)
{
    if (from == "oct")
        base = 3;                  /// base=8=2^3
    elif (from == "hex") base = 4; /// base=16=2^4
    ll converted_int, extra;
    st converted_number;
    f(0, i, main_number.size())
    {
        if (main_number[i] == '.')
            converted_number += '.';
        else
        {
            if (main_number[i] >= '0' && main_number[i] <= '9')
                converted_int = main_number[i] - '0';
            else
            {
                extra = (ll)main_number[i] - 64;
                converted_int = 9 + extra;
            }
            fr(base, j, 0)
            {
                if (converted_int >= pow(2, j))
                {
                    converted_number += '1';
                    converted_int -= pow(2, j);
                }
                else
                    converted_number += '0';
            }
        }
    }
    ct(converted_number);
}

int convert(ll n, ch converted[500], ll converted_number, ll m, ll extra)
{
    f(0, i, n)
    {
        converted_number = 0, m = base;
        f(i, j, i + base)
        {
            m--;
            if (converted[j] == '1')
                converted_number += pow(2, m);
            else
                converted_number += 0;
        }
        i += base - 1;
        if (converted_number < 10)
            ct(converted_number);
        else
        {
            extra = converted_number - 9;
            ct((ch)(64 + extra));
        }
    }
}

int from_binary(st main_number)
{
    if (to == "oct")
        base = 3;                /// base=8=2^3
    elif (to == "hex") base = 4; /// base=16=2^4
    bool flag = true;
    ll point = 0, temp, int_number, flt_number, int_range, flt_range, converted_int_number, converted_flt_number, extra_int, extra_flt, k = 0, l = 0, k1, l1;
    ch converted_int[500], converted_flt[500];
    f(0, i, main_number.size())
    {
        if (main_number[i] == '.')
        {
            point = i;
            flag = false;
            break;
        }
    }
    if (flag)
        point = main_number.size();
    temp = main_number.size() - point;
    int_number = main_number.size() - temp;
    flt_number = temp - 1;
    if (int_number % base == 0)
        int_range = int_number;
    else
        int_range = ((int_number / base + 1) * base);
    f(0, i, int_range - int_number) converted_int[k++] = '0';
    f(0, i, int_number) converted_int[k++] = main_number[i];
    convert(k, converted_int, converted_int_number, k1, extra_int);
    ct(".");
    if (flt_number % base == 0)
        flt_range = flt_number;
    else
        flt_range = ((flt_number / base + 1) * base);
    f(point + 1, i, main_number.size()) converted_flt[l++] = main_number[i];
    f(0, i, flt_range - flt_number) converted_flt[l++] = '0';
    convert(l, converted_flt, converted_flt_number, l1, extra_flt);
}

int from_oct(st main_number)
{
    ll converted_int, extra;
    st converted_number;
    f(0, i, main_number.size())
    {
        if (main_number[i] == '.')
            converted_number += '.';
        else
        {
            if (main_number[i] >= '0' && main_number[i] <= '9')
                converted_int = main_number[i] - '0';
            else
            {
                extra = (ll)main_number[i] - 64;
                converted_int = 9 + extra;
            }
            fr(3, j, 0)
            {
                if (converted_int >= pow(2, j))
                {
                    converted_number += '1';
                    converted_int -= pow(2, j);
                }
                else
                    converted_number += '0';
            }
        }
    }
    from == "bin";
    to == "hex";
    from_binary(converted_number);
}

int to_oct(st main_number)
{
    ll converted_int, extra;
    st converted_number;
    f(0, i, main_number.size())
    {
        if (main_number[i] == '.')
            converted_number += '.';
        else
        {
            if (main_number[i] >= '0' && main_number[i] <= '9')
                converted_int = main_number[i] - '0';
            else
            {
                extra = (ll)main_number[i] - 64;
                converted_int = 9 + extra;
            }
            fr(4, j, 0)
            {
                if (converted_int >= pow(2, j))
                {
                    converted_number += '1';
                    converted_int -= pow(2, j);
                }
                else
                    converted_number += '0';
            }
        }
    }
    from == "bin";
    to == "oct";
    from_binary(converted_number);
}

int main()
{
    ct("This program can convert:");
    bye;
    ct("\t- binary to octal" << endl
                             << "\t- binary to decimal" << endl
                             << "\t- binary to hexa-decimal" << endl);
    ct("\t- octal to binary" << endl
                             << "\t- octal to decimal" << endl
                             << "\t- octal to hexa-decimal" << endl);
    ct("\t- decimal to binary" << endl
                               << "\t- decimal to octal" << endl
                               << "\t- decimal to hexa-decimal" << endl);
    ct("\t- hexa-decimal to binary" << endl
                                    << "\t- hexa-decimal to octal" << endl
                                    << "\t- hexa-decimal to decimal");
    bye;
    ct("(Both integer and float numbers are acceptable)");
    bye, bye;
    ct("# use\n   - bin for binary\n   - oct for octal\n   - dec for decimal\n   - hex for hexa-decimal");
    bye, bye;
    ll t = 0;
    w(1)
    {
        t++;
        ct("Case-" << t);
        bye;
        ct("From: ");
        cn(from);
        if (from == "bin" || from == "oct" || from == "dec" || from == "hex")
        {
            ct("To: ");
            cn(to);
            if ((to == "bin" || to == "oct" || to == "dec" || to == "hex") && from != to)
            {
                ct("Enter the number: ");
                cst(main_number);
                first_symbol = '0';
                if (from == "bin")
                    last_symbol = '1';
                elif (from == "oct") last_symbol = '7';
                elif (from == "dec") last_symbol = '9';
                if (from == "bin" || from == "oct" || from == "dec")
                {
                    f(0, i, main_number.size())
                    {
                        if (main_number[i] == '.')
                            valid = true;
                        elif (main_number[i] < first_symbol || main_number[i] > last_symbol)
                        {
                            valid = false;
                            break;
                        }
                    }
                }
                elif (from == "hex")
                {
                    f(0, i, main_number.size())
                    {
                        if ((main_number[i] >= '0' && main_number[i] <= '9') || (main_number[i] >= 'A' && main_number[i] <= 'F') || main_number[i] <= '.')
                            valid = true;
                        else
                        {
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid == true)
                {
                    ct("Ans: ");
                    if (from == "dec" && (to == "bin" || to == "oct" || to == "hex"))
                        from_decimal(main_number);
                    if (to == "dec" && (from == "bin" || from == "oct" || from == "hex"))
                        to_decimal(main_number);
                    if (to == "bin" && (from == "oct" || from == "hex"))
                        to_binary(main_number);
                    if (from == "bin" && (to == "oct" || to == "hex"))
                        from_binary(main_number);
                    if (from == "oct" && to == "hex")
                        from_oct(main_number);
                    if (to == "oct" && from == "hex")
                        to_oct(main_number);
                }
            }
            else
                valid = false;
        }
        else
            valid = false;
        if (!valid)
            ct("Invalid.");
        bye, bye;
    }
}