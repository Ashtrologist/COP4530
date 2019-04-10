
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include "GraphBase.hpp"

using namespace std;


class Edge{

   // friend class Vertex;
    //friend class Graph;
    public:
        string distance1;
        string distance2;
        int weight;

    
        Edge();
        ~Edge();

};

class Graph : public GraphBase {
    friend class Edge;
  //  friend class Vertex;

    public:
    // Graph();
    // ~Graph();
     void addVertex(std::string label);
     void removeVertex(std::string label);
     void addEdge(std::string label1, std::string label2, unsigned long weight);
     void removeEdge(std::string label1, std::string label2);
     unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

    // private:
         vector<string> vertex;
        vector<Edge*> vertexEdge;
    
};


// class Vertex{

//     friend class Edge;
//     friend class Graph;
//     private:
//         vector<string> vertex;
//         vector<Edge*> vertexEdge;
// };




#endif