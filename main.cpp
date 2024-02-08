#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Graph.h"
using namespace std;

int main() {
    //apertura del file
    string fileName = "input.txt";
    int lineCount = 0;
    //linee che stiamo attraversando
    string line;
    //nodi  del' grafo
    int dimension;
    //numero di archi
    int edges;
    //vertici in cui è presente un hotel
    vector<int> hotel;

    Graph *g = nullptr;
    ifstream input(fileName);
    if (!input.is_open()) {
        cerr << "Error opening file" << endl;
        return 1; // Uscita con errore
    }else{

    // Leggi il file riga per riga e incrementa il contatore per ciascuna riga letta
    while (getline(input, line)) {
        if(lineCount == 0){
            dimension = stoi(line);
            //Grafo
            g = new Graph(dimension);
        }else if(lineCount == 1){
            for(char c:line) {
                if (isdigit(c)) {
                    hotel.push_back(c - '0'); // Converte il carattere numerico in intero e lo aggiunge al vettore
                }
            }
        }else if(lineCount == 2) {
            edges = stoi(line);
        }else{
            //elabora le chiamate a funzione
            istringstream iss(line);
            int a, b, weight;
            if (iss >> a >> b >> weight) {
                g->addEdge(a, b, weight);
            }
        }



        lineCount++;
    }

    // Chiudi il file dopo averlo letto
    input.close();
        cout << "Dimensione: " << dimension << endl;
        for(int num : hotel){
            cout <<"\t"<<num;

        }
        cout<<endl;
        cout<<edges<<endl;

        g->printAdjacencyList();
    }

// Stampa il numero di linee lette
    return 0;
}
