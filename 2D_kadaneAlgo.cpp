#include<bits/stdc++.h>
using namespace std;

// Kadane's algorithm to find the maximum sum subarray in 1D array.
// Returns a pair: {max_sum, {start_index, end_index}} of the subarray.
pair<int,pair<int,int>> kadane(vector<int> arr){
    int sum = 0, maxi = INT_MIN;
    int s = 0, r = 0, temp = 0;
    int n = arr.size();

    for(int i = 0; i < n; ++i) {
        sum += arr[i];

        // Update maximum and track start and end indices
        if(sum > maxi){
            maxi = sum;
            s = temp;
            r = i;
        }

        // Reset sum if it goes negative
        if(sum < 0){
            sum = 0;
            temp = i + 1;
        }
    }
    return {maxi, {s, r}};
}

int main() { 
    int n, m;
    cin >> n >> m;

    // Input 2D array of size n x m
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    // Variables to track maximum submatrix boundaries
    int maxtop = 0, maxdown = 0, maxleft = 0, maxright = 0;
    int cur = 0, maxi = INT_MIN;

    // Iterate over all possible column pairs
    for(int i = 0; i < m ; ++i){
        vector<int> temp(n, 0); // Temporary array to store column-wise sum
        for(int j = i; j < m; ++j){
            // Add current column values to the temporary array
            for(int k = 0 ; k < n ; ++k)
                temp[k] += a[k][j];

            // Apply Kadane's algorithm to find max sum subarray in this column range
            auto ans = kadane(temp);
            cur = ans.first;

            // Update overall maximum and store boundaries
            if(cur > maxi){
                maxi = cur;
                maxtop = ans.second.first;
                maxdown = ans.second.second;
                maxleft = i;
                maxright = j;
            }   
        }
    }

    int ans = maxi;

    // Add back the absolute value of negative elements in the max submatrix
    //this is not the part of algorithm this is according to the question.
    for(int i = maxtop ; i <= maxdown ; ++i){
        for(int j = maxleft ; j <= maxright ; ++j){
            if(a[i][j] < 0)
                ans += abs(a[i][j]);
        }
    }

    // Output the maximum submatrix sum and the adjusted sum with negatives made positive
    cout << maxi << '\n' << ans << endl;

    return 0;
}
