This repository provides code for Sorting.

You will read the sorting task from the standard input. 
The first line is an integer, which specifies the sorting algorithm you should call. The integer can take six values: 0 for bubble sort, 1 for insertion sort, 2 for selection sort, 3 for merge sort, 4 for quick sort using extra array for partitioning, and 5 for quick sort with in-place partitioning. Other values are illegal, but you can assume that the user will not input illegal values.
The second line specifies the number of integers you are asked to sort. Let that number be N. Then the following N lines list the N integers to be sorted.

An example of input is
3
5
-1
-3
2
0
4
This example calls merge sort to sort 5 integers -1, -3, 2, 0, and 4 in ascending order.

The program writes the sorted result to the standard output. Each line lists one number. For the above example, the output looks like
-3
-1
0
2
4