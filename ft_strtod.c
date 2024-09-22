#include "./myLib.h"

#define MANTIS 18

static int maxExp = 511;

static double powersOf10[] = {
    10.,
    100.,
    1.0e4,
    1.0e8,
    1.0e16,
    1.0e32,
    1.0e64,
    1.0e128,
    1.0e256
};

double
ft_strtod(const char *str, char **endptr)
{
    double ret = 0, dbexp = 1.0, *power;
    int real1 = 0, real2 = 0, i = 0, exp = 0;
    char *tmp = (char*)str, *end, *floatPoint = NULL;
    bool sign = false, expSign = false;

    if (!tmp)
        return (ret);
    while (ft_isspace(*tmp))
        ++tmp;
    if (*tmp == '-') {
        sign = true;
        ++tmp;
    }
    if (*tmp == '+')
        ++tmp;
    while (ft_isdigit(tmp[i])) {
        i++;
        if (tmp[i] == '.' && !floatPoint) {
            if (i < MANTIS)
                floatPoint = tmp + i;
            i++;
        }
    }
    end = tmp + i;
    if (i > MANTIS)
        i = MANTIS;
    if (floatPoint)
        --i;
    while (ft_isdigit(*tmp) && i > 0) {
        if (i > 9)
            real1 = (real1 * 10) + *tmp - '0';
        else
            real2 = (real2 * 10) + *tmp - '0';
        ++tmp;
        --i;
        if (*tmp == '.') {
            ++tmp;
        }
    }
    ret = (1.0e9 * real1) + real2;
    if (*end == 'e' || *end == 'E')
    {
        ++end;
        if (*end == '-') {
            expSign = true;
            ++end;
        }
        if (*end == '+')
            ++end;
        while (ft_isdigit(*end)) {
            exp = (exp * 10) + *end - '0';
            ++end;
        }
        if (expSign)
            exp = -exp;
    }
    if (floatPoint) {
        exp -= ((tmp - 1) - floatPoint);
        if (exp < 0) {
            expSign = true;
            exp = -exp;
        }
    }
    if (exp > maxExp)
        exp = maxExp;
    for (power = powersOf10; exp != 0; exp >>= 1, power++) {
        if (exp & 0b1) {
            dbexp *= *power;
        }
    }
    if (expSign)
        ret /= dbexp;
    else
        ret *= dbexp;
    if (endptr)
        *endptr = end;
    if (sign)
        return (-ret);
    return (ret);
}
