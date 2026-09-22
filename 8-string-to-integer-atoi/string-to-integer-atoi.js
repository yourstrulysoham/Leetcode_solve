/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    let number = 0;
    let isLeading = true;
    let isNegetive = false;

    for (let i = 0; i < s.length; i++) {
        const num = parseInt(s[i]);

        if (isLeading && s[i] === ' ') {
            continue;
        } else if (isLeading && s[i] === '+') {
            isNegetive = false;
            isLeading = false;
        } else if (isLeading && s[i] === '-') {
            isNegetive = true;
            isLeading = false;
        } else if (num >= 0 && num <= 9) {
            isLeading = false;
            number = number * 10 + num;
        } else {
            break;
        }
    }

    number = isNegetive ? (number * -1) : number;

    if (number < -2147483648) {
        return -2147483648;
    }

    if (number > 2147483647) {
        return 2147483647;
    }

    return number;
};