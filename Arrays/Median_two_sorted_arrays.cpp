/*The expected time complexity gives away binary search in this case.
We are going to do binary search for the answer in this case.

Given a sorted array A of length m, we can split it into two parts:

{ A[0], A[1], â€¦ , A[i - 1] }    { A[i], A[i + 1], â€¦ , A[m - 1] }
All elements in right part are greater than elements in the left part.

The left part has i elements, and right part has m - i elements.
There are m + 1 kinds of splits.

(i = 0 ~ m)

When i = 0, the left part has â€œ0â€� elements, the right part has â€œmâ€� elements.
When i = m, the left part has â€œmâ€� elements, right part has â€œ0â€� elements.

For the array B, we can split it in the same way:

{ B[0], B[1], â€¦ , B[j - 1] }    { B[j], B[j + 1], â€¦ , B[n - 1] }
The left part has â€œjâ€� elements, and right part has â€œn - jâ€� elements.

Put Aâ€™s left part and Bâ€™s left part into one set. (Letâ€™s name this set â€œLeftPartâ€�)

Put Aâ€™s right part and Bâ€™s right part into one set. (Letâ€™s name this setâ€�RightPartâ€�)

        LeftPart           |            RightPart
{ A[0], A[1], â€¦ , A[i - 1] }    { A[i], A[i + 1], â€¦ , A[m - 1] }
{ B[0], B[1], â€¦ , B[j - 1] }    { B[j], B[j + 1], â€¦ , B[n - 1] }
If we can ensure the following:

LeftPartâ€™s length == RightPartâ€™s length (or RightPartâ€™s length + 1)
All elements in RightPart is greater than elements in LeftPart,
then we can split all elements in {A, B} into two parts with equal length, and one part is always greater than the other part.

Then the median can thus be easily found.

Based on condition 1, can you derive the value of j if value of i is known?
Can you binary search on i ?
*/

#include<vector>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
            int m = A.size(), n = B.size();
            if (m > n) return findMedianSortedArrays(B, A);
            int imin, imax, i, j; 
            imin = 0;
            imax = m;
            while (imin <= imax) {
                i = (imin + imax)/2;
                j = (m+n+1)/2 - i;
                if (j > 0 && i < m && B[j - 1] > A[i]) {
                    imin = i + 1;
                } else if (i > 0 && j < n && A[i - 1] > B[j]) {
                    imax = i - 1;
                } else {
                    int median1 = 0, median2 = 0;
                    if (i == 0) {
                        median1 = B[j - 1];
                    } else if (j == 0) {
                        median1 = A[i - 1];
                    } else {
                        median1 = max(A[i - 1], B[j - 1]);
                    }
                    if ((m+n) % 2 == 1) {
                        return 1.0 * median1;
                    }
                    if (i == m) {
                        median2 = B[j];
                    } else if (j == n) {
                        median2 = A[i];
                    } else {
                        median2 = min(A[i], B[j]);
                    }
                    return 1.0 * (median1 + median2) / 2.0;
                }
            }
            return -1.0;
        }
};
