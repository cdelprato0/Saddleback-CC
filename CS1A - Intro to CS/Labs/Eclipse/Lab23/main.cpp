#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string words);

int main()
{
string word;

cout << "Enter a string: ";
cin >> word;
cout << endl;

if(isPalindrome(word) == true )
cout << word << " is a palindrome.";

else
cout << word << " is not a palindrome.";
}
