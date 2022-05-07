//
// Created by Jason MacKeigan on 2022-04-23.
//
#include <iostream>
#include <vector>

using std::pair, std::vector;

class Vertex {

    int m_num;

};

class Edge {

    pair<Vertex, Vertex> vertices;

    Edge(pair<Vertex, Vertex> vertices) {
        this->vertices = vertices;
    }

};

class EdgeCollection {

    vector<Edge> edges;

    Vertex* center;

    void add_edge(pair<int, int> vertices) {
        //look through existing edges to find any existing duplicate vertices
            //if they exist, use that existing object instead of instantiating a new oen
            //else create a new one
            //create a new edge from either 2 new, or 1 existing and 1 new
    }

};

// center = 2
// GraphNode node1 = new GraphNode(1);
//

class StarGraph {



};

int main() {

}