#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Matrix
{
private:
    int n, m;
    double **A;
public:
    Matrix (int N, int M) //E-0 нулевая матрца, E-1 единичная матрица
   {
      n = N;
      m = M;
      A = new double *[n];
      for (int i = 0; i < n; i++)
      {
         A[i] = new double[m];
         for (int j = 0; j < m; j++)
            A[i][j] = 0.0;
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
       A[x][y] = value;
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

int main() {
    std::ifstream file("q.txt");
    std::string s;

    Matrix Potensials(5, 5);
    Matrix Ex(5, 5);
    std::cout << Ex.get_N();
    std::cout << Ex.get_M();
    std::cout << Ex.getItem(0, 0);
    Ex.Display();
    Matrix Ey(5, 5);
    while(getline(file, s)){
        const char *line = s.c_str();
        if(line[0] == '1'){ //монополь
            int q = atoi(&line[2]); //заряд
            int x = atoi(&line[4]);
            int y = atoi(&line[6]);
            for(int i=0; i<5; i++){
                for(int j=0; j<5; i++){
                    Ex.setItem(i, j, 3.0);
                    Ey.setItem(i, j, 3.0);
                    Potensials.setItem(i, j, 3.0);
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
    return 0;
}

