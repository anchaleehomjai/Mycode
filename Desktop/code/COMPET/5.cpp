#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, K;
    string s1 = " ";
    cin >> N;
    cin >> K;
    char str;
    int arr[N], one, two;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < K; i++)
    {
        cin >> str;
        cin >> one;
        cin >> two;
        if (str == 'C')
        {
            arr[one] = two;
            //     for(int i =1 ;i<=N;i++){
            // cout << arr[i]<<" ";
        }

        else
        {
            int produc = 1;
            if (one == two)
            {
                produc = one;
                if (produc == 0)
                {
                    s1 += "0";
                }
                else if (produc > 0)
                {
                    s1 += "+";
                }
                else
                {
                    s1 += "-";
                }
            }
            else
            {
                for (int i = one; i <= two; i++)
                {
                    // cout <<int( arr[i])<<" ";
                    produc = produc * int(arr[i]);
                    // cout << produc;
                }

                if (produc == 0)
                {
                    s1 += "0";
                }
                else if (produc > 0)
                {
                    s1 += "+";
                }
                else
                {
                    s1 += "-";
                }
            }
        }
    }

    cout << s1;
    cout << endl;

    return 0;
}
