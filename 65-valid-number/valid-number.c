char transitionTable[8][4] = {
    {2, 0, 3, 4},
    {2, 5, 6, 0},
    {6, 0, 0, 0},
    {2, 0, 3, 0},
    {7, 0, 0, 8},
    {6, 5, 0, 0},
    {7, 0, 0, 0},
    {7, 0, 0 ,0},
};
enum token {
    digit = 0,
    exponential = 1,
    dot = 2,
    sign = 3,
};

bool isNumber(char * s){
    char state = 1;
    for (int i = 0; s[i]; i++) {
        switch(s[i]) {
            case '0' ... '9':
                if (state = transitionTable[state-1][digit]) continue; else return false;
            case 'e':
            case 'E':
                if (state = transitionTable[state-1][exponential]) continue; return false;
            case '.':
                if (state = transitionTable[state-1][dot]) continue; else return false;
            case '+':
            case '-':
                if (state = transitionTable[state-1][sign]) continue; else return false;
            default:
                return false;
        }
    }
    return state == 2 || state == 6 || state == 7;
}