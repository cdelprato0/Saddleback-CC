/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#include "BoyerMoore.h"

BoyerMoore::BoyerMoore() {
	// TODO Auto-generated constructor stub

}

BoyerMoore::~BoyerMoore() {
	// TODO Auto-generated destructor stub
}

// A utility function to get maximum of two integers
int BoyerMoore::max(int a, int b)
{
    return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void BoyerMoore::badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void BoyerMoore::search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        cout << "Comparing \"" << txt << "\" with \"" << pat << "\"\n";

        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
        }

        if (j < 0)
        {

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
            cout << "Comparing \"" << txt << "\" with \"" << pat << "\"\n";

        }

        else {
            s += max(1, j - badchar[txt[s + j]]);
            cout << "Comparing \"" << txt << "\" with \"" << pat << "\"\n";

        }
        cout << "Comparing \"" << txt << "\" with \"" << pat << "\"\n";

    }

    cout << endl << s << " Comparisons\n\n";

}
