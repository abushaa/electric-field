//
// Created by Алина Бадамшина on 17.05.17.
//
#include <iostream>
#include <map>
#include "matrix.h"
#include "list.h"
#include <fstream>

using namespace std;

int main(){
    ifstream file("q.txt");
    string s;
    getline(file, s);
    cout << s << endl;
    Matrix Potentials(5, 5);
    Matrix Ex(5, 5);
    //cout << Ex.get_N();
    //cout << Ex.get_M();
    //cout << Ex.getItem(0, 0);
    //Ex.Display();
    Matrix Ey(5, 5);
    while(getline(file, s)){

        const char *line = s.c_str();
        if(line[0] == '1'){ //монополь

            int q = atoi(&line[2]); //заряд
            int x = atoi(&line[4]);
            int y = atoi(&line[6]);
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){

                    Ex.setItem(i, j, 3.0);
                    Ey.setItem(i, j, 3.0);
                    Potentials.setItem(i, j, 3.0);
                }
            }
            Ex.Display();
        }
        if(line[0] == '2'){ //диполь
            int dx = atoi(&line[2]); //компонента х от дипольного момента
            int dy = atoi(&line[4]);
            int x = atoi(&line[6]);
            int y = atoi(&line[8]);
        }
    }
    Potentials.Display();
    map<double, List> pots;
    for (int i = 0; i < Potentials.get_N(); i++){
        for (int j = 0; j < Potentials.get_M(); j++){
            add(&pots[Potentials.getItem(i, j)], i, j);
            }
        }
    for(map<double, List>::iterator it = pots.begin(); it!=pots.end(); it++){
        cout << (*it).first << ":" << endl;
        printList(&(*it).second);
    }
}

