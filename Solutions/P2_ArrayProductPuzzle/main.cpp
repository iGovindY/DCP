/** This problem was asked by Uber.
 *  Given an array of integers, return a new array such that each element at index i of
 *  the new array is the product of all the numbers in the original array except the one at i.
 *  For example, if our input was [1, 2, 3, 4, 5], the expected output would be
 *  [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

 *  Follow-up: what if you can't use division?
 */

#include <iostream>

using namespace std;

void productPuzzle(int arr[], int n)
{
    int product[n] = {1};

    for(int i = 1 ; i < n ; i++)
    {
        product[i] = product[i-1] * arr[i-1];
    }

    int rightProduct = 1;
    for(int i = n-2 ; i >= 0 ; i--)
    {
        rightProduct = rightProduct * arr[i+1];
        product[i] = product[i] * rightProduct;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout<< product[i] << " ";
    }
}

int main()
{
        /** input */
    int arr[]   = {2, 3, 4, 5};
    int size    = sizeof(arr)/sizeof(int);

    productPuzzle(arr,size);

    return 0;
}
