#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void addEdge(int from, int dest, int weight){
    cout<<from<<" "<<dest<<" "<<weight<<endl;
}
int main() {
    //apertura del file
    string fileName = "input.txt";
    ifstream input(fileName);
    if (!input.is_open()) {
        cerr << "Error opening file" << endl;
        return 1; // Uscita con errore
    }else{
        // Contatore per le linee lette,iteratore per le linee
        //vettore per gli alberghi
        int lineCount = 0;
        string line;
        int dimension;
        vector<int> hotel;
    // Leggi il file riga per riga e incrementa il contatore per ciascuna riga letta
    while (getline(input, line)) {
        if(lineCount == 0){
            dimension = stoi(line);
        }else if(lineCount == 1){
            for(char c:line) {
                if (isdigit(c)) {
                    hotel.push_back(c - '0'); // Converte il carattere numerico in intero e lo aggiunge al vettore
                }
            }
        }else{
            //elabora le chiamate a funzione
            istringstream iss(line);
            int a, b, weight;
            if (iss >> a >> b >> weight) {
                addEdge(a, b, weight);
            }
        }



        lineCount++;
    }

    // Chiudi il file dopo averlo letto
    input.close();
        cout << "Dimensione: " << dimension << endl;
        for(int num : hotel){
            cout <<" "<<num;
        }
    }
// Stampa il numero di linee lette
    return 0;
}
