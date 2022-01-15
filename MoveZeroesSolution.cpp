//
// Created by Jason MacK on 2021-12-17.
//

#include "MoveZeroesSolution.h"
#include <iterator>
#include <iostream>
#include <ostream>
#include <string>
// nums.size is within range of { 1 <= 10,000 }
//

// 1. [0,1,0,3,12]

// 2. [0,1,0,3,12]
// index is zero, value at index is zero
// 3. [1, 0, 3, 12]
// 4. []

void MoveZeroesSolution::moveZeroes(vector<int> &nums) {
    // tokens to identify what is in the array then perform action
    // use vector#push_back to send array to back

    // when moving everything to the right, shift everything to the left
    // maintain order of non-zero integers.

    /**
     * Jason? Maybe?
     * Index based
     */
    // could use iterator for begin/end
    // on each loop
    //      set<ints> ofIndex;

    //      if zero
    //          add index to set
    //
    //      loop indexes
    //          remove zero
    //          push to back
    // if we use a for-loop, we can't modify the array while iterating
    //

     /**
      * Gideon
      * For loop
      * for (int i = 0; i < nums.size(); i++) {
      *     if (i+1 >= nums.size() { // check for out of bounds
      *         break;
      *     }
      *     // might need to check for i+1 not out of bounds?
      *     if (nums[i] == 0 && nums[i+1] != 0) {
      *         int temp = nums[i+1];
      *         nums[i+1] = 0;
      *         nums[i] = temp;
      *     }
      * }
      *
      */



    /**
     * For loop by index solution, single pass
     */
    // on loop
    // if zero
    //  do something
    //  if != zero
    //      skip


    // maybe reduce i by -1 if found and modifying the underlying vector

    // maybe use a boolean flag when going over the vector
    // we are going to find elements that are, or are not zero

    /**
     * Jason
     * Binary search/divide and conquer? solution
     * Whats the complexity of this?
     */
     // keep pointer of left
     // keep pointer of right
     // get value at left
     // get value at right
     // if (left is zero)
     //     add to end
     // if (right is zero)
     //     add to end
     // if (right == left) {
     //     break
     // } else {
     //     reduce right by 1
     //     increase left by 1
     // }
     // we're done


    /**
     * Alex
     * vector<int>::iterator i;
     *
     * for (i = nums.begin(); i != nums.end(); i++ )
     * {
     *      if (i == 0)
     *      {
 *              // Sort
     *      }
     * }
     *      sort(nums.begin(), nums.end(), compute);

    // vector<int>::iterator i;

    for (int i = nums.begin(); i != nums.end(); i++ )
    {
    if (i == 0)
       {

             }
          }

     */


}

void MoveZeroesSolution::test(vector<int> &nums, const vector<int> &expected) {
    if (nums.size() != expected.size()) {
        throw invalid_argument("Nums size and expected size are not the same.");
    }
    for (int index = 0; index < nums.size(); index++) {
        if (nums[index] != expected[index]) {
            throw invalid_argument("Value does not match.");
        }
    }
    cout << "Passed!";
}

// [ 1, 3, 0, 0, 12 ]
// l = 1, r = 12, skip
// l = 3, r = 0, erase r, move r to end, make r equal to r - 1
void MoveZeroesSolution::jason(vector<int>& nums) {
    if (nums.size() <= 1) {
        return;
    }
    auto left = nums.begin();

    auto right = nums.end() - 1;

    while (left <= right) {
        if (*left == 0) {
            std::rotate(left, left + 1, nums.end());
        } else {
            left++;
        }
        if (*right == 0 && right != nums.end() - 1) {
            std::rotate(right, right + 1, nums.end());
        } else {
            right--;
        }
    }
    // keep a pointer of left and right
    // if value at point is zero
    //      erase
    //
//    while (left < right) {
//        if (*left == 0) {
//            left = nums.erase(left);
//
//            nums.emplace_back(0);
//
//            right--;
//            left++;
//        } else {
//            left++;
//        }
//        if (left >= right) {
//            break;
//        }
//        if (*right == 0) {
//            right = nums.erase(right);
//            nums.emplace_back(0);
//            right--;
//        } else {
//            right--;
//        }
//    }
}

void MoveZeroesSolution::gideon(vector<int> &nums) {
    // Is it completely sorted?
    bool isSorted = false;
    // Loop to keep running through as long as its not sorted
    while (!isSorted) {
        // Reset this for every for loop as long as sorting was needed
        bool sortNeeded = false;
        for (int i = 0; i < nums.size(); i++) {
            // Check if you're about to go out of bounds. if so, abort
            if (i+1 >= nums.size()) {
                break;
            }
            // if next number is not zero, swap it for this 0
            if (nums[i] == 0 && nums[i+1] != 0) {
                sortNeeded = true;
                // Use a temporary value
                int temp = nums[i+1];
                nums[i+1] = 0;
                nums[i] = temp;
            }
        }
        // After loop is done, check if sorting needed to be done
        // If so, keep going
        if (sortNeeded) {
            continue;
            // If not, means you have solved it!
        } else {
            break;
        }
    }

}

void MoveZeroesSolution::alex(vector<int> &nums) {

    if (nums.size() <= 1)
    {
        return;
    }

    bool solved = false;
    int zeroCount = 0;

    while (!solved)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // Iterate over
            if (i == 0)
            {
                // Erase the zero
                nums.erase(find(nums.begin(), nums.end(), 0));
                // Add the zero to the end
                nums.push_back(0);

                zeroCount++;
            }


        }

        if (zeroCount == 0)
        {
            break;
        }

        // Check for the right order
        if (find(nums.begin(), nums.end(), 0) == nums.end() - zeroCount)
        {
            solved = true;
        }
    }
}

void MoveZeroesSolution::ryan(vector<int> &nums) {
    int zeroCount = 0;

    // determine amount of 0 values in vector
    for(int num : nums){
        if(num == 0){
            zeroCount++;
        }
    }

    if(zeroCount != 0) {
        for (int z = 0; z < nums.size(); z++){
            if(nums[z] == 0){
                nums.erase(nums.begin() + z);
                z--;
                zeroCount--;
                nums.emplace_back(0);
                if(zeroCount == 0){
                    break;
                }
            }
        }
    }
}
