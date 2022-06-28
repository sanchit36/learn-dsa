#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int pivot)
{
    int hi = arr.size();
    int i = 0, j = 0;
    while (i < hi)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (j - 1);
}

int quickSelect(vector<int> arr, int lo, int hi, int k)
{
    int pivot = arr[hi];
    int pi = partition(arr, pivot);

    if (k > pi)
    {
        return quickSelect(arr, pi + 1, hi, k);
    }
    else if (k < pi)
    {
        return quickSelect(arr, lo, pi - 1, k);
    }
    else
    {
        return arr[k];
    }
}

void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 7, 2, 4, 6, 5, 8, 3};
    int k;
    cin >> k;
    int ans = quickSelect(arr, 0, arr.size() - 1, arr.size() - k);
    cout << ans;
    return 0;
}