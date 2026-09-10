//
// Created by Anh Le on 8/8/26.
//
bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int maxVowels(string s, int k) {
    int ans = 0;
    int cnt = 0;
    for (int right = 0, left = 0; right < s.size(); right++)
    {
        if (isVowel(s[right]))
            cnt++;
        if (right >= k)
        {
            if (isVowel(s[left]))
                cnt--;
            left++;
        }
        ans = max(ans,cnt);
    }
    return ans;
}