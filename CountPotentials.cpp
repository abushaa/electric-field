#include <iostream>
#include <fstream>
#include <string>

class Matrix
{
private:
    int N, M;
    double **A;
public:
    matrix (int N, int M, bool E = 0) //E-0 нулевая матрца, E-1 единичная матрица
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
       return N;
   }

   int get_M(){
       return M;
   }

   double getItem(int x, int y){
       return A[x][y];
   }

   void setItem(int x, int y, double value){
       A[x][y] =  value;
   }
};

int main() {
    std::ifstream file("q.txt");
    std::string s;
    while(getline(file, s)){

    }
    return 0;
}
