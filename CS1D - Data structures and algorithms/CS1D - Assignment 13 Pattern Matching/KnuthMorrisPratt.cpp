/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#include "KnuthMorrisPratt.h"

KnuthMorrisPratt::KnuthMorrisPratt() {
	count = 0;

}

KnuthMorrisPratt::~KnuthMorrisPratt() {

}

void KnuthMorrisPratt::preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;

    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];

        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1]) {
                break;
            }
            else {
                k = f[k];
            }
        }
        f[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KnuthMorrisPratt::KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            count++;
            cout << "Comparing \"" << pattern << "\" with \"" << target << "\"\n";

            if (k == m) {
                return 1;
            }
        }
        else{
            k = f[k];
            count++;
            cout << "Comparing \"" << pattern << "\" with \"" << target << "\"\n";
        }
    }
    return 0;
}

int KnuthMorrisPratt::getCount() const {
	return count;
}
