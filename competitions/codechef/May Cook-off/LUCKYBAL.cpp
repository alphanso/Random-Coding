// http://www.codechef.com/problems/LUCKYBAL/
/* 
 * File:   main.cpp
 * Author: Rishabh
 *
 * Created on May 20, 2012, 11:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */

int main() 
{
    int T, len, k;
    cin >> T;
    string S;
    for(int i = 0; i < T; i++)
    {
        long long count = 0;
        cin >> S;
        len = S.size();
        k = 0;
        for(int j = 0; j < len; j++)
        {
            if(S[j] == '7')
            {
                count += j - k;
                k++;
            }
            else 
            {
                k = 0;
                count += j + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}
