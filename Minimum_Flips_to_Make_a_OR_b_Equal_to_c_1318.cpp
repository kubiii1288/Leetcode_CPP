//
// Created by Anh Le on 8/16/26.
//
int minFlips(int a, int b, int c) {
    int flips = 0;
    while (a || b || c)
    {
        int bitA = a & 1;
        int bitB = b & 1;
        int bitC = c & 1;

        if (bitC != (bitA | bitB))
        {
            if (bitC)
                flips += (!bitA && !bitB);
            else
                flips += (bitA + bitB);
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return flips;
}