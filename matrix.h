//
// Created by Алина Бадамшина on 17.05.17.
//

#ifndef ELECTRIC_FIELD_MATRIX_H
#define ELECTRIC_FIELD_MATRIX_H

#endif //ELECTRIC_FIELD_MATRIX_H
class matrix {
private:
    double a;
    int n, m;
public:
    // матрица без элементов
    matrix ()
    {
        a = 0;
        n = 0;
        m = 0;
    }

    // получить строку матрицы
    double *getRow(int index) {
        if (index >= 0 && index < n)
            return a[index];
        return 0;
    }

    // получить столбец матрицы
    double *getColumn(int index) {
        if (index < 0 || index >= m)
            return 0;
        double *c = new double[n];
        for (int i = 0; i < n; ++i)
            c[i] = a[i][index];
        return c;
    }
    // удаление столбцов с index1 по index2
    matrix eraseColumns (int index1, int index2)
    {
        matrix c = matrix (n, m - (index2 - index1 + 1));
        for (int j = 0; j < index1; ++ j)
            for (int i = 0; i < n; ++ i)
                c[i][j] = a[i][j];
        for (int j = index2 + 1; j < m; ++ j)
            for (int i = 0; i < n; ++ i)
                c[i][j - index2 - 1 + index1] = a[i][j];
        return c;
    }
    int *getSize(){
        int Size;
        Size = n*m;
        return Size;
    }
    // сколько строк в матрице
    int *getNumberofStrings() {
        return n;
    }
    // сколько столбцов в матрице
    int *getNumberofColumns() {
        return m;
    }
    //вывести элемент матрицы
    double *getElement(int index1, int index2){
        return
};

};
//прочитать матрицу с файла