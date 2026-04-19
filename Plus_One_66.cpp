//
// Created by Anh Le on 12/5/25.
//
vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    int pointer = digits.size() - 1;
    while (pointer >= 0 && carry == 1) {
        digits[pointer] = (digits[pointer] + 1) % 10;
        carry = (digits[pointer] == 0);
        pointer--;
    }
    if (carry)
        digits.insert(digits.begin(), 1);

    return digits;
}