//
// Created by harub on 07/02/2024.
//

#ifndef LABORATORIO_DI_ALGORITMI_GRAPH_H
#define LABORATORIO_DI_ALGORITMI_GRAPH_H
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Graph {
private:

    int nodes;
    //crea un lista di adiacenza tramite pair
    vector<vector<pair<int,int>>> adj;
    int edge;

public:
    Graph(int  nodes) {
        this->nodes = nodes;
        adj.resize(nodes+1);
    }

    void addEdge(int a,int b,int const weight){
        //this->adjList[a][b] = weight;
        adj[a].push_back(make_pair(b,weight));
        adj[b].push_back(make_pair(a,weight));
    }

    void printAdjacencyList(){
        for(int i = 1; i < adj.size(); ++i){
            cout<<"Vertex: "<<i<<endl;
            for(const auto& it : adj[i]){
                cout<<" ->"<< it.first<<" weight:  "<<it.second<<endl;
            }
            cout<<endl;

        }
    }

    ~Graph() {
        for (int i = 1; i < adj.size(); ++i) {
            adj[i].clear(); // Svuota il vettore di adiacenza di ogni vertice
        }
        adj.clear(); // Svuota il vettore di vettori di adiacenza
    }

};


#endif //LABORATORIO_DI_ALGORITMI_GRAPH_H
