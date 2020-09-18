#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string words)
{
string reverse;
int x=0;
int count=0;
int value=0;
int b=0;

cerr << x;
if(words[count] > 0)
{
count++;
}



for(int i=0; i< count/2; i++)
{
value = words[i];
reverse[i]=words[count-1-i];
reverse[count-1-i] = value;

}
cerr << x;
words[100]= tolower(words[100]);
reverse[100] = tolower(reverse[100]);

if (words[b] == reverse[b])
x=1;
else
{
x=2;



}
cerr << x;
if (x==1)
return true;
else
return false;
}
