int divide(long long dividend, long long divisor) {
    long long temp, answer = 0, multiple = 1, toggle = 1;
    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
        toggle = 0;

    dividend = llabs(dividend);
    divisor = llabs(divisor);
    while (dividend >= divisor) {
        temp = divisor;
        multiple = 1LL;
        while ((temp << 1LL) <= dividend) {
            temp <<= 1LL;
            multiple <<= 1LL;
        }
        dividend -= temp;
        answer += multiple;
    }
    if(toggle == 1)
        return (answer < INT_MAX ? answer : INT_MAX);
    return (-answer > INT_MIN ? -answer : INT_MIN);
}