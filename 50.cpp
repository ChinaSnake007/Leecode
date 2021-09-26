#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double fastpow(double x, int n){
    if(n==1)
        return x;
    
    double ret = fastpow(x,n/2);
    return n % 2 == 0 ? ret * ret : ret * ret * x;
}

double myPow(double x, int n)
{
    if(n == 0)
        return 1.0;
    return n>0?fastpow(x,abs(n)):1/fastpow(x,abs(n));
}

// double myPow(double x, int n)
// {
//     if (n == 0)
//         return 0.0;
//     int N = n;
//     double sum = x, Sum = 1.0;
//     if (n < 0)
//         N = -n;
//     while (N / 2)
//     {
//         if (N % 2 == 0)
//         {
//             sum = sum * sum;
//             N = N / 2;
//         }
//         else
//         {
//             Sum = Sum * sum;
//             sum = sum * sum;
//             N = N / 2;
//         }
//         // cout << sum << "\t" << N << '\t' << Sum << endl;
//     }
//     sum = sum * Sum;
//     // if (abs(n % 2) == 1 && abs(n) != 1)
//     //     sum = sum * x;

//     if (n > 0)
//         return sum;
//     else
//         return 1.0 / sum;
// }

int main()
{
    cout << myPow(2, -10) << endl;
    cout << pow(2, -10) << endl;
    return 0;
}