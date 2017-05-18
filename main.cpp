//
// Created by Алина Бадамшина on 17.05.17.
//
#include <iostream>
#include <map>
#include "matrix.h"
#include "list.h"

using namespace std;

Matrix potentials(6, 6, 1);

int main(){
    map<double, List> pots;
    for (int i = 0; i < potentials.get_N(); i++){
        for (int j = 0; j < potentials.get_M(); j++){
            add(&pots[potentials.getItem(i, j)], i, j);
            }
        }
    for(map<double, List>::iterator it = pots.begin(); it!=pots.end(); it++){
        cout << (*it).first << ":" << endl;
        printList(&(*it).second);
    }
}

