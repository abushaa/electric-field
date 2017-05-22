//
// Created by Алина Бадамшина on 17.05.17
//
#include <cstdlib>
#include <iostream>
#include <map>
#include "matrix.h"
#include "list.h"
#include <fstream>
#include <cmath>
using namespace std;

double truncated(double to_be_cut, int digits){

    static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0,10000.0,100000.0};
    double truncated = std::trunc(to_be_cut * powerOfTen[digits]) / powerOfTen[digits];
    return truncated;
}

double scalar_multiplication(double a1, double b1, double a2, double b2){
    return a1*a2+b1*b2;
}

int main(){
    ifstream file("/home/brattelnik/Documents/CompScience/electric-field/q.txt");
    // /Users/abushaa/ClionProjects/electric-field/q.txt
    string s;
    int N;
    cin>>N;
    Matrix Potentials(N, N);
    Matrix Ex(N, N);
    Matrix Ey(N, N);
    while(getline(file, s)){
        const char *line = s.c_str();
        if(line[0] == '1'){ //монополь
            int q = atoi(&line[2]); //заряд
            int x = atoi(&line[4]);
            int y = atoi(&line[6]);
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    double distance = pow(pow(i-x+1, 2)+pow(j-y+1, 2), 0.5);
                    double Exij = q*(i-x+1)/pow(distance, 3);
                    double Eyij = q*(j-y+1)/pow(distance, 3);
                    double Pij = q/distance;
                    //Pij = truncated(Pij,2); //оставляем только три знака после запятой
                    Ex.addValueToItem(i, j, Exij);
                    Ey.addValueToItem(i, j, Eyij);
                    Potentials.addValueToItem(i, j, Pij);
                }
            }
        }
   /*     if(line[0] == '2'){ //диполь
            int dx = atoi(&line[2]); //компонента х от дипольного момента
            int dy = atoi(&line[4]);
            int x = atoi(&line[6]);
            int y = atoi(&line[8]);
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    double dipole_abs = pow(scalar_multiplication(dx, dy, dx, dy), 0,5);
                    double angle = scalar_multiplication(dx, dy, i-x+1, j-y+1)/dipole_abs/pow(scalar_multiplication(i-x+1, j-y+1, i-x+1, j-y+1), 0,5)
                    double distance = pow(pow(i-x+1, 2)+pow(j-y+1, 2), 0.5);
                    double Exij = 1/pow(distance, 3)*((i-x+1)*dx+(j-y+1)*dy*3*(i-x+1)-dx));
                    double Eyij = 1/pow(distance, 3)*((i-x+1)*dx+(j-y+1)*dy*3*(j-y+1)-dy));
                    double Pij = dipole_abs*cos(angle)/distance/distance;
                    //Pij = truncated(Pij,2); //оставляем только три знака после запятой
                    Ex.addValueToItem(i, j, Exij);
                    Ey.addValueToItem(i, j, Eyij);
                    Potentials.addValueToItem(i, j, Pij);
                }
            }
        }
    */

    }

    //Найдем максимум и минимум. Разобьем наши потенциалы на три группы в зависимости от величины, далее
    // для маленьких потенциалов сделаем высокую точность, для высоких -низкую
    // Это делается для улучшения отображения картинки
    double min_potential = Potentials.getItem(0,0);
    double max_potential = Potentials.getItem(0,0);
    for (int i = 0; i < Potentials.get_N(); i++){
        for (int j = 0; j < Potentials.get_M(); j++){
            if (Potentials.getItem(i,j)< min_potential){
                min_potential = Potentials.getItem(i,j);

            }
            if (Potentials.getItem(i,j)> max_potential and Potentials.getItem(i,j)< 10000000000000) { //немножко стыдно
                max_potential = Potentials.getItem(i, j);

            }
        }}
    double border_1 = (max_potential - min_potential)/3;
    double border_2 = 2*(max_potential - min_potential)/3;
    for (int i = 0; i < Potentials.get_N(); i++){
        for (int j = 0; j < Potentials.get_M(); j++){
            if (Potentials.getItem(i,j)< border_1){
                Potentials.setItem(i,j,truncated(Potentials.getItem(i,j),2)); //оставляем только три знака после запятой
            }
            if (Potentials.getItem(i,j)> border_1 and Potentials.getItem(i,j) < border_2){
                Potentials.setItem(i,j,truncated(Potentials.getItem(i,j),1)); //оставляем только два знака после запятой
            }
            if (Potentials.getItem(i,j) > border_2){
                Potentials.setItem(i,j,truncated(Potentials.getItem(i,j),0)); //оставляем только один знак после запятой
            }
        }}



    map<double, List> pots;
    for (int i = 0; i < Potentials.get_N(); i++){
                for (int j = 0; j < Potentials.get_M(); j++){
            add(&pots[Potentials.getItem(i, j)], i, j);
            }
        }
    ofstream pot("/home/brattelnik/Documents/CompScience/electric-field/potentials.txt");
    // /Users/abushaa/ClionProjects/electric-field/potentials.txt
    for(map<double, List>::iterator it = pots.begin(); it!=pots.end(); it++){
        pot << (*it).first << ":";
        pot << "\n";
        outputList(&(*it).second, pot);
    }


}
