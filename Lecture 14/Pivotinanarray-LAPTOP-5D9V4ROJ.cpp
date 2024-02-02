#include <iostream>
using namespace std;
int pivot1(int arr[], int size)
{
    int l = 0, u = size - 1, ans, mid = l + ((u - l) / 2);
    while (l < u)
    {
        if (arr[mid] >= arr[0])
        {
            l = mid + 1;
        }
        else
        {
            u = mid;
        }
        mid = l + ((u - l) / 2);
        ans = mid;
    }
    return ans;
}
int pivot2(int arr[], int size)
{
    int l = 0, u = size - 1, ans, mid = l + ((u - l) / 2);
    while (l < u)
    {
        if (arr[mid] >= arr[0])
        {
            l = mid;
        }
        else
        {
            u = mid - 1;
        }
        mid = l + ((u - l) / 2);
        ans = mid;
    }
    return ans;
}

int main()
{
    int numbers1[10] = {7, 9, 35, 187, 789, 3353, 53466, 4, 2, 1};
    int numbers2[5] = {8, 10, 17, 1, 3};
    cout << pivot1(numbers1, 10) << endl
         << pivot2(numbers1, 10) << endl
         << pivot1(numbers2, 5) << endl
         << pivot2(numbers2, 5);
}