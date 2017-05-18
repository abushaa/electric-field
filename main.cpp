//
// Created by Алина Бадамшина on 17.05.17.
//
#include <iostream>
#include <map>
#include "matrix.h"
#include "list.h"
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream file("/Users/abushaa/ClionProjects/electric-field/q.txt");
    string s;
    int N;
    cin>>N;
    Matrix Potentials(N, N);
    Matrix Ex(N, N);
    Matrix Ey(N, N);
    while(getline(file, s)){
        const char *line = s.c_str();
        if(line[0] == '1'){ //монополь
            int q = atoi(&line[2]); //зар€д
            int x = atoi(&line[4]);
            int y = atoi(&line[6]);
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    double distance = pow(pow(i-x+1, 2)+pow(j-y+1, 2), 0.5);
                    double Exij = q*(i-x+1)/pow(distance, 3);
                    double Eyij = q*(j-y+1)/pow(distance, 3);
                    double Pij = q/distance;
                    Ex.addValueToItem(i, j, Exij);
                    Ey.addValueToItem(i, j, Eyij);
                    Potentials.addValueToItem(i, j, Pij);
                }
            }
        }
        if(line[0] == '2'){ //диполь
            int dx = atoi(&line[2]); //компонента х от дипольного момента
            int dy = atoi(&line[4]);
            int x = atoi(&line[6]);
            int y = atoi(&line[8]);
        }
    }

    map<double, List> pots;
    for (int i = 0; i < Potentials.get_N(); i++){
        for (int j = 0; j < Potentials.get_M(); j++){
            add(&pots[Potentials.getItem(i, j)], i, j);
            }
        }
    ofstream pot("/Users/abushaa/ClionProjects/electric-field/potentials.txt");
    for(map<double, List>::iterator it = pots.begin(); it!=pots.end(); it++){
        pot << (*it).first << ":";
        pot << "\n";
        outputList(&(*it).second, pot);
    }
}

