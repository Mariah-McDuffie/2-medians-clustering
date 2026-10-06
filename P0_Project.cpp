//C++
//Project P0

#include <iostream>
#include "clustering.h"
#include "defs.h"


using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
        fatal("Usage:\n\n  P0 inputFileName\n\n");
    
    //Timer variables
    timer t;
    t.start("Timer has started");

    string inputFileName = argv[1];
    vector<Point> points = readNum(inputFileName);
    // int numCount = points.size(); // cardinality of input numbers
    

    if (!QUIET) {
    std::cout << "\nCommand line arguments: \n\t";
    for (int i = 0; i < argc; i++)
      std::cout << argv[i] << " ";
    std::cout << "\n\n";
    std::cout << "Input will be read from: " << inputFileName << endl;
    std::cout << "Numbers will be optimally clustered using 2-medians.\n";
    std::cout << "Cardinality of the cluster containing the smallest value will be output to screen.\n" << std::endl;
  }

  // Performing Clustering
  int splitIndex = clustering(points);

  //Left Cluster is what we want... Left cluster = 0...splitIndex - 1
  //Cardinality of Cluster containing the smallest value
  int leftClusterSize = splitIndex;
  std::cout << leftClusterSize << endl; 

  t.stop("\nTimer stopped.");
  double compTime;
  compTime = t.timeVal();
  
  int seconds = 0;
  int min = 0;
  int hour = 0;
  
  seconds = (int)compTime % 60;
  min = (int)compTime / 60;
  hour = min / 60;
  min = min % 60;
  
  if (!QUIET)
    std::cout << hour << " hours, " << min << " minutes, " << seconds << " seconds.\n" << std::endl;

  return 0;
}





