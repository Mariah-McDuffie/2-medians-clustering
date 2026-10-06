# Mariah McDuffie

# 2 MEDIANS CLUSTERING
A C++ implementation of a 2-medians clustering algorithm for one-dimensional numerical data. The program uses brute-force enumeration of possible split points to find the partition with the minimum total clustering cost. 

# Overview

The goal of the 2-medians clustering problem is to divide a set of points into two clusters while minimizing the total distance between each point and the median of its assigned cluster.

This implementation:

1. Reads numerical data from an input file.
2. Sorts the points by value.
3. Evaluates every possible split between the two clusters.
4. Calculates the median of each resulting cluster.
5. Computes the total clustering cost for each split
6. Selects the split with the lowest total cost.
7. Assigns each point to one of the two resulting clusters.
8. Reports the size of the cluster containing the smallest values.

# Files included
- `P0_Project.cpp` - main program file 
- `clustering.h` - header file for clustering functions
- `clustering.cpp` - implementation of clustering functions
- `defs.h` - definitions

# How to run:

Compile the prject with a C++ compiler:

g++ -std=c++17 P0_Project.cpp clustering.cpp-o P0
\
Run the program by providing an input file:

./P0 inputFileName

The input file should contain numerical values that can be read as double values

# Algorithm

After sorting the input points, the algorithm evaluates every possible split between consecutive points.

For each possible split:

- The median of the first cluster is calculated.
- The median of the second cluster is calculated.
- The cost of each cluster is calculated as the sum of the absolute distances between its points and its median.
- The two cluster costs are added together. 
- The split with the lowest cost is rretained.
- Each point is assigned to one of the two resulting clusters.

The algorithm uses exhaustive evaluation of the possible split locations rather than an heuristic approach.

================================================
Pseudocode: P0
================================================

Sort A[1..n] in nondecreasing order by A[i].value  //O(n log n), space: O(n)
bestCost <- infinity
bestSplit <- undefined

for split = 1 to n - 1    // O(n)
    med1 = MEDIAN(A, 1, split)
    med2 = MEDIAN(A, split + 1, n)

    cost1 = COMPUTE-COST(A, 1, split, med1)
    cost2 = COMPUTE-COST(A, split + 1, n, med2) 
    totalCost = cost1 + cost2
        if totalCost < bestCost 
            bestCost = totalCost
            bestSplit = split
end for

for i = 1 to bestSplit    // O(n), not nested
    A[i].cluster_id = 0   //Assign point A[i] to Cluster 0
for i = bestSplit + 1 to n  // O(n), not nested
    A[i].cluster_id = 1   //Assign point A[i] to Cluster 1

return bestSplit

MEDIAN(A, p, r) // O(1)

COMPUTE-COST(A, p, r, m) // O(n)

================================================
COMPLEXITY:
================================================
Time Complexity: O(n^2)
Space complexity: O(n)

# Technologies

- C++
- C++ Standard Library
- Vectors and structs
- Sorting
- File I/O
- Algorithm analysis
- Complexity analysis

# Background 
This project was originally developed as coursework for an Advanced Data Structures and Algorithms course. It provided practical experience implementing and analyzing an algorithm for a combinatorial clustering problem.