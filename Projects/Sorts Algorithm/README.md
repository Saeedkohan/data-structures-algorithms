# Time Complexity Analysis of Sorting Algorithms

This README provides a detailed analysis and comparison of four classical sorting algorithms based strictly on the given Python implementations. The algorithms are evaluated in three standard cases: Best Case, Average Case, and Worst Case. A comparative table and a precise explanatory analysis are provided for each algorithm.

---

## Algorithms Covered

* Bubble Sort
* Insertion Sort
* Merge Sort
* Quick Sort

All complexity analyses are derived directly from the behavior of the provided code, not from abstract or idealized versions.

---

## Time Complexity Comparison Table

The table below summarizes the time complexity of each algorithm in different cases.

| Algorithm      | Best Case  | Average Case | Worst Case | Key Reason                         |
| -------------- | ---------- | ------------ | ---------- | ---------------------------------- |
| Bubble Sort    | O(n)       | O(n²)        | O(n²)      | Early termination using swap check |
| Insertion Sort | O(n)       | O(n²)        | O(n²)      | Progressive shifting of elements   |
| Merge Sort     | O(n log n) | O(n log n)   | O(n log n) | Fixed divide-and-merge structure   |
| Quick Sort     | O(n log n) | O(n log n)   | O(n²)      | Strongly dependent on pivot choice |

---

## Detailed Algorithm Analysis

### Bubble Sort

**Why is the Best Case O(n)?**
In the given implementation, if the array is already sorted, no swaps occur during the first pass. The `swapped` flag remains `False`, causing the algorithm to terminate early after a single linear scan of the array.

**What conditions lead to the Worst Case?**
The worst case occurs when the array is sorted in reverse order. In this situation, every comparison leads to a swap, and both nested loops execute fully, resulting in quadratic time complexity.

**Which case does it resemble in practice and why?**
In practice, Bubble Sort usually behaves closer to the Average or Worst Case because real-world data is rarely fully sorted. This makes Bubble Sort inefficient for large datasets.

---

### Insertion Sort

**Why is the Best Case O(n)?**
When the array is already sorted, the condition in the inner `while` loop is never satisfied. Each element is compared once, leading to a single linear traversal of the array.

**What conditions lead to the Worst Case?**
The worst case occurs when the array is sorted in reverse order. Each new element must be shifted all the way to the beginning of the array, resulting in maximum comparisons and shifts.

**Which case does it resemble in practice and why?**
Insertion Sort often behaves close to the Best Case in practice when the data is small or nearly sorted. For this reason, it is frequently used as an optimization step in hybrid sorting algorithms.

---

### Merge Sort

**Why is the Best Case O(n log n)?**
Merge Sort always divides the array into two halves regardless of input order. The recursion depth is `log n`, and merging at each level takes linear time, resulting in O(n log n).

**What conditions lead to the Worst Case?**
There is no specific input that worsens Merge Sort. The algorithm performs the same sequence of operations regardless of the initial ordering of elements.

**Which case does it resemble in practice and why?**
Merge Sort consistently performs at O(n log n) in practice. Its predictable behavior makes it suitable for large datasets, although it requires additional memory.

---

### Quick Sort

**Why is the Best Case O(n log n)?**
In the best case, the chosen pivot divides the array into two nearly equal parts. This results in a recursion depth of `log n`, with linear work done at each level.

**What conditions lead to the Worst Case?**
The worst case occurs when the pivot is always the smallest or largest element, producing highly unbalanced partitions. This causes the recursion depth to grow to `n`, leading to O(n²) complexity.

**Which case does it resemble in practice and why?**
In practice, Quick Sort typically behaves close to the Average Case. Balanced partitions are statistically more likely, and the algorithm benefits from low memory usage and good cache performance.

---

## Final Summary

* Bubble Sort and Insertion Sort are simple but inefficient for large datasets.
* Insertion Sort performs very well on small or nearly sorted inputs.
* Merge Sort offers stable and predictable performance at the cost of extra memory.
* Quick Sort is usually the fastest in practice but has a poor worst-case scenario.

This analysis can be directly used as a formal academic report for a data structures course.
