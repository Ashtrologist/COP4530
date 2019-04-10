#include "Graph.hpp"

//Constructor for edge class
Edge::Edge(){
    distance1 = "";
    distance2 = "";
    weight = 0;
}

//Deconstructor for edge class
Edge::~Edge(){}

//Deconstructor for graph class
//Graph::~Graph(){}

void Graph::addEdge(string label1, string label2, unsigned long weight){
    Edge *edge1 = new Edge();

    edge1 -> distance1 = label1;
    edge1 -> distance2 = label2;
    edge1 -> weight = weight;
    vertexEdge.push_back(edge1);

}

void Graph::removeEdge(string label1, string label2){
    Edge *edge1 = new Edge();

    for(unsigned long i = 0; i < vertexEdge.size(); i++){
        edge1 = vertexEdge[i];
        if((edge1 -> distance1 == label1) && (edge1 -> distance2 == label2)){
            vertexEdge.erase(vertexEdge.begin() + i);
        }
    }
}

void Graph::addVertex(string label){

    vertex.push_back(label);

}

void Graph::removeVertex(string label){
    Edge *edge1 = new Edge ();
    for(unsigned long i = 0; i < vertex.size(); i++){
        if(vertex[i] == label){
            vertex.erase(vertex.begin() + i);

            for(unsigned long j = 0; j < vertexEdge.size(); j++){
                edge1 = vertexEdge[j];
                if((edge1 -> distance1 == label) || (edge1 -> distance2 == label)){
                    vertexEdge.erase(vertexEdge.begin() + j);
                }
            }
        }
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path){
    unsigned long ashton = 0;

    return ashton;
}
