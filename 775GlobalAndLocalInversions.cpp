#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
private:
long long ans = 0;
void merge(vector<int>& arr, long long N, long long M, long long K)
{
    long long i = N, j = K + 1;
    long long temp[M - N + 1];
    long long t = 0;
    while ((i <= K) && (j <= M))
    {
        if (arr[j] < arr[i])
        {
            ans += (K + 1 - i);
            temp[t] = arr[j];
            ++j;
        }
        else
        {
            temp[t] = arr[i];
            ++i;
        }
        ++t;
    }
    while (i<=K)
    {
        temp[t++] = arr[i++];
    }
    while (j<=M)
    {
        temp[t++] = arr[j++];
    }
    t = 0;
    for (long long q = N; q <= M; q++)
    {
        arr[q] = temp[t++];
    }    
}

void mergeSort(vector<int>& arr, long long N, long long M){
    if(M>N){
        long long mid = (M - N)/2 + N;
        mergeSort(arr,N,mid);
        mergeSort(arr,mid+1,M);
        merge(arr,N,M,mid);
    }
}
public:
    bool isIdealPermutation(vector<int>& arr) {
        int N = arr.size();
        int local = 0;
        for(int i=0;i<N - 1;++i){
            if(arr[i] > arr[i+1])
            ++local;
        }
        mergeSort(arr,0,N-1);
        return ans == local;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}