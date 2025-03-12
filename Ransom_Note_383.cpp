//
// Created by Anh Le on 3/11/25.
//
#include<iostream>
#include <unordered_set>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
   unordered_multiset<char> s;
   for (char c : magazine)
   {
      s.insert(c);
   }

   for (char c : ransomNote)
   {
      unordered_multiset<char>::iterator it = s.find(c);
      if (it != s.end())
      {
         s.erase(it);
      } else return false;
   }

   return true;
}