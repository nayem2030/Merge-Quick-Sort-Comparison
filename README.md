# Merge Sort vs Quick Sort: Comparison Counting and Sorted Batch Merging

**Course:** CSE 208 - Algorithm Lab (Green University of Bangladesh)
**Lab Report No:** 02
**Student:** Md. Nayem Hasan (ID: 250002030)
**Language:** C

## About the Project

An organization collects N integer records. The records may come in random, ascending, descending or duplicate-heavy order. This program:

1. Sorts the records in ascending order using **Merge Sort** and **Quick Sort** (last element as pivot).
2. Counts the **element comparisons** made by each algorithm
   - Merge Sort: comparisons made while merging
   - Quick Sort: comparisons made while partitioning
3. Reads a new batch of M **already sorted** records and merges it into the sorted dataset in O(N + M) time, **without sorting everything again**.

## Files

| File | Description |
|------|-------------|
| `lab2_sorting.c` | Complete C source code |
| `input.txt` | Sample input (Test Case 1) |
| `README.md` | Project description |

## Input Format (`input.txt`)

```
N M
a1 a2 ... aN        (N records, any order)
b1 b2 ... bM        (M records, already sorted ascending)
```

## How to Compile and Run

```bash
gcc lab2_sorting.c -o lab2
./lab2
```

Keep `input.txt` in the same folder as the program.

## Sample Test Cases

### Test Case 1 (random order)

Input:
```
8 4
7 2 9 1 5 3 4 6
0 2 8 10
```

Output:
```
Merge Sort: 1 2 3 4 5 6 7 9
Quick Sort: 1 2 3 4 5 6 7 9
Merge Comparisons: 16
Quick Comparisons: 15
Updated Array: 0 1 2 2 3 4 5 6 7 8 9 10
```

### Test Case 2 (already ascending)

Input:
```
8 3
1 2 3 4 5 6 7 8
2 4 10
```

Output:
```
Merge Sort: 1 2 3 4 5 6 7 8
Quick Sort: 1 2 3 4 5 6 7 8
Merge Comparisons: 12
Quick Comparisons: 28
Updated Array: 1 2 2 3 4 4 5 6 7 8 10
```

## Complexity

| Algorithm / Operation | Best Case | Worst Case | Space |
|-----------------------|-----------|------------|-------|
| Merge Sort | O(N log N) | O(N log N) | O(N) |
| Quick Sort (last element pivot) | O(N log N) | O(N^2) | O(log N) to O(N) stack |
| Merging the sorted batch | O(N + M) | O(N + M) | O(N + M) |

## Key Observation

For already sorted input, Quick Sort with the last element as pivot always gets the largest element as pivot, so the partitions are completely unbalanced. The comparisons become 7 + 6 + ... + 1 = N(N-1)/2 = 28 for N = 8 (the O(N^2) worst case), while Merge Sort needs only 12 comparisons because its splitting does not depend on the values.
