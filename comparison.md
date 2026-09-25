# Comparison of Merge Sort and Quick Sort

| Feature | Merge Sort | Quick Sort |
|---------|------------|------------|
| Duplicate values | Handles | Handles |
| Stability | Stable | Not stable normally |
| Best Case | O(n log n) | O(n log n) |
| Average Case | O(n log n) | O(n log n) |
| Worst Case | O(n log n) | O(n²) |
| Space | O(n) | O(log n) average |
| Equal order preserved | Yes | No normally |
| Stable modification | Not required | Possible |

## Stability Verification

Weight 10:
Original: P4, P8
Stable result: P4, P8

Weight 15:
Original: P2, P5
Stable result: P2, P5

Weight 20:
Original: P1, P3, P6
Stable result: P1, P3, P6

Therefore, Merge Sort preserves the original relative
order of equal-weight packages.
