#include <iostream>

/*
                Q. search in rotated sorted array - I

            explanation -  given array - {1, 2, 3, 4, 5, 6, 7, 8, 9},   it has unique elements
                            rotate it at 7 -  arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6}
                                            target = 1

                    our first approach will be the linear search
                        whih will give us  TC - O(N)

                    to optimize it we will use binary search
                    but we have to consider that the rotated array is not sorted, so we have to identify
                    which part is sorted, for that we have to check on both half

                    arr = {7, 8, 9, 1, 2, 3, 4, 5, 6}   here low = 0, high = 8,  mid = 4
                                    in this case the left half is not sorted bcz 7 > 2
                        so we check if 1 is in the right half (we select it first bcz this part is sorted)
                        and it is not
                                            ...rest explanation in the video

    pseudo code
f(arr, n, target)
{
    low = 0, high = n-1
    while(low <= high)
    {
        mid = (low+high)/2
        if(arr[mid] == target)
            return mid;

        // left sorted
        if(arr[low] <= arr[mid])
            if(arr[low] <= target && target <= arr[mid])
                high = mid - 1
            else
                low = mid + 1

        // right is sorted
        else
            if(arr[mid] <= target && target <= arr[high])
                low = mid + 1
            else
                high = mid - 1
    }
    return -1;
}


        Actual code
int search(vector<int>&arr, int n, int k)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == k)
            return mid;

        // left sorted
        if(arr[low] <= arr[mid])
        {
            if(arr[low] <= k && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        // right is sorted
        else
        {
            if(arr[mid] <= k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}


            TC - O(log base 2 N)
*/

int main()
{
    std::cout << "Hello World!\n";
}