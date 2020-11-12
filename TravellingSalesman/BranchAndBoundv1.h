#pragma once
#include "Graph.h"
#include "Node.h"
#include <stack>
#include <queue>
#include <ostream>


class BranchAndBoundv1
{
private:

private:
    int tmpDistance;
    int upperBound;
    Graph graph;
    std::stack<int> path;
    std::stack<int> tmpPath;
    
    bool* wasVisited;
    int* pathToAdjustingCities;
    int initialLowerBound;

public:
    BranchAndBoundv1(Graph graph);
    ~BranchAndBoundv1();
    void recursiveBnB(Node node);
    int resolveLowerBound(Node node, int nextCity);
    void run();
    void displayPath();

};

