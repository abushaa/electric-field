//
// Created by Алина Бадамшина on 18.05.17.
//

#ifndef ELECTRIC_FIELD_MATRIX_H
#define ELECTRIC_FIELD_MATRIX_H

#endif //ELECTRIC_FIELD_MATRIX_H
class Matrix
{
private:
    int n, m;
    double **A;
public:
    Matrix (int N, int M) //E-0 нулевая, E-1 единичная
    {
        n = N;
        m = M;
        A = new double *[n];
        for (int i = 0; i < n; ++ i)
        {
            A[i] = new double[m];
            for (int j = 0; j < m; ++ j)
                A[i][j] = (i == j) * E;
        }
    }

    int get_N(){
        return n;
    }

    int get_M(){
        return m;
    }

    double getItem(int x, int y){
        return A[x][y];
    }

    void setItem(int x, int y, double value){
        A[x][y] =  value;
    }
    void Display(){
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                std::cout << A[i][j];
            }
            std::cout << std::endl;
        }
    }
};
