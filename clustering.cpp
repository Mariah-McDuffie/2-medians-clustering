#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "defs.h"
#include "clustering.h"
#include <limits>

using namespace std;

//read numbers from the file

vector<Point>readNum(const string& filename)
{
    ifstream infile(filename);
    if (!infile) 
    {
        cerr << "Fatal: Cannot open file " << filename << endl;
        exit(1);
    }

    vector<Point> points;
    double val;

    while (infile >> val)
    {
        Point p;
        p.value = val; //store the number
        p.cluster_id = -1; //unassigned initially
        points.push_back(p); //add to the vector
    }

    if (points.empty()) 
    {
        cerr << "Fatal: Input file is empty" << endl;
        exit(1);
    }

    return points;

}


//compute median of sorted array
double median(const std:: vector<Point>& arr, int start, int end )
{
    int length = end - start + 1;
    int middle = start + length / 2;

    if(length % 2 == 1)
    {
        return arr[middle].value;
    } 
    else
    {
        return (arr[middle - 1].value + arr[middle].value) / 2;
    }

}
//Compute cost of assigning points 
double computeCost (const vector<Point>& arr, int start, int end, double med)
{
    double cost = 0.0;
    for(int i = start; i <= end; i++)
    {
        cost += fabs(arr[i].value - med);

    }
    return cost;
}


//compute optimal 2-medians partition

int clustering(vector<Point>& arr)
{
    //sort by value
    sort(arr.begin(), arr.end(), [](const Point& a, const Point& b) {
        return a.value < b.value;
    });

    int n = arr.size();
    double bestCost = numeric_limits<double>::infinity();
    int bestSplit = -1;

    for (int split =1; split < n; split++)
    {
        double med1 = median(arr, 0, split - 1);
        double med2 = median(arr, split, n-1);

        //cost
        double cost1 = computeCost(arr, 0, split - 1, med1);
        double cost2 = computeCost(arr, split, n-1, med2);

        //total cost
        double totalCost = cost1 + cost2;

        if (totalCost < bestCost)
        {
            bestCost = totalCost;
            bestSplit = split;
        }

    }
    //cluster id's:
    for(int i = 0; i < bestSplit; i++)
    {
        arr[i].cluster_id = 0;
    }

    for (int i = bestSplit; i < n; i++)
    {
        arr[i].cluster_id = 1;
    }
    return bestSplit; //returning the best split

}
