// https://www.hackerrank.com/challenges/2d-array/problem
// Jordan Tonni
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    
        int max = -60, n = 6;

    /*
     * General Idea: Each hour glass can be given by the 6 elements inside it.
     * Each of those terms is specified relative to a reference point, i.e. the top left element
     * 
     * Loop through each of the legal top left elements (i.e. the ones that allow you to have 2 more elements to the right an below it)
     * Maintain the sum of each hourglass and compare to get max
     *
     *
     */

    // O(M^2) i.e. O(N^2)
    for (int i = 0; i <= n - 3; ++i) // M = N-3 -> Loops M times
    {
        for (int j = 0; j <= n - 3; ++j) // Loops M times
        {
            int sum = 0;
            sum += arr[i][j];
            sum += arr[i][j + 1];
            sum += arr[i][j + 2];
            sum += arr[i + 1][j + 1];
            sum += arr[i + 2][j];
            sum += arr[i + 2][j + 1];
            sum += arr[i + 2][j + 2];

            if (sum > max)
                max = sum;
        }
    }

    cout << max << endl;
    return 0;
}


