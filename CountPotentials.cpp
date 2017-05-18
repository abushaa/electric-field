#include <iostream>
#include <fstream>
#include <string>

class Matrix
{
private:
    int n, m;
    double **A;
public:
    Matrix (int N, int M, bool E = 0) //E-0 ������� ������, E-1 ��������� �������
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
};

int main() {
    std::ifstream file("q.txt");
    std::string s;
    while(getline(file, s)){

    }
    return 0;
}
