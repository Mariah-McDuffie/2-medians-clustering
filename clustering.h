//C++
//Project P0


#ifndef CLUSTERING_H
#define CLUSTERING_H

#include <vector>
#include <string>

//Struct def

struct Point 
{
    double value;
    int cluster_id;
};

// Function prototypes
std::vector<Point> readNum(const std::string& filename);
double median(const std::vector<Point>& arr, int start, int end);
double computeCost(const std::vector<Point>& arr, int start, int end, double med);
int clustering(std::vector<Point>& arr);

#endif


