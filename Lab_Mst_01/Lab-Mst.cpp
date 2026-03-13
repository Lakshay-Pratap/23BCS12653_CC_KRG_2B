#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> tokens = {100, 200, 300, 400};
    sort(tokens.begin(), tokens.end());

    int i = 0;
    int j = (int)tokens.size() - 1;
    int score = 0, best = 0,power = 80;

    while (i <= j) {
        if (tokens[i] <= power)
        {          
            power -= tokens[i++];
            score++;
            if (score > best) 
            {
                best = score;
            }
        }
         else if (score > 0) 
        {            
            power += tokens[j--];
            score--;
        } else 
        {
            break;                         
        }
    }
    return best;
}
