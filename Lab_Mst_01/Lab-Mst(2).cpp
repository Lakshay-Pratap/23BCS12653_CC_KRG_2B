#include <bits/stdc++.h>
using namespace std;

int singleNumber(int nums[], int n)
{
    int result = 0;

    for(int i = 0; i < 32; i++)
    {
        int sum = 0;

        for(int j = 0; j < n; j++)
        {
            if(nums[j] & (1 << i))
                sum++;
        }

        if(sum % 3)
            result |= (1 << i);
    }

    return result;
}