//
// Created by kubiii on 10/23/26.
//

long long numberOfWays(string &s) {
    long long ans = 0;
    int rightOnes = 0, rightZeros = 0, leftOnes = 0, leftZeros= 0;
    for (char c : s) {
        rightOnes+= (c-'0');
    }
    rightZeros = s.size() - rightOnes;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0') {
            //s[i] is one
            rightOnes--;
            ans += (leftZeros * rightZeros);
            leftOnes++;
        } else {
            // s[i] is zero
            rightZeros--;
            ans += (leftOnes * rightOnes);
            leftZeros++;
        }
    }
    return ans;
}