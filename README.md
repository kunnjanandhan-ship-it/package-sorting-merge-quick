# Package Sorting Using Merge Sort and Quick Sort

## Aim

To implement Merge Sort and Quick Sort in C to sort
logistics packages according to their weights and compare
their stability, time complexity, space complexity and
number of comparisons.

## Problem Statement

A logistics company receives the following package weights:

20, 15, 20, 10, 15, 20, 25, 10

Each package has a unique package ID.

## Package Details

| Package ID | Weight | Original Position |
|------------|--------|-------------------|
| P1 | 20 | 1 |
| P2 | 15 | 2 |
| P3 | 20 | 3 |
| P4 | 10 | 4 |
| P5 | 15 | 5 |
| P6 | 20 | 6 |
| P7 | 25 | 7 |
| P8 | 10 | 8 |

## Algorithms Implemented

1. Merge Sort
2. Quick Sort
3. Stable Quick Sort

## Sorted Output

P4(10) P8(10) P2(15) P5(15)
P1(20) P3(20) P6(20) P7(25)

## Stability

Merge Sort is stable and preserves the original relative
order of equal-weight packages.

Standard Quick Sort is not stable.

Quick Sort can be modified to preserve the order of equal
elements by using the original position as a secondary key.

## Complexity

### Merge Sort

Best Case: O(n log n)

Average Case: O(n log n)

Worst Case: O(n log n)

Space Complexity: O(n)

### Quick Sort

Best Case: O(n log n)

Average Case: O(n log n)

Worst Case: O(n²)

Average Space Complexity: O(log n)

Worst Case Space Complexity: O(n)

## Number of Comparisons

For the given input:

Merge Sort = 16 comparisons

Quick Sort = 16 comparisons

## Conclusion

Both Merge Sort and Quick Sort correctly sort the package
weights.

Merge Sort is stable and directly preserves the original
relative order of equal-weight packages.

Standard Quick Sort is not stable, but it can be modified
to preserve the order using the original position.

Therefore, when maintaining the original order of equal
weights is important, Merge Sort provides stability directly.
