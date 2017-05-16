//
// Created by Алина Бадамшина on 17.05.17.
//

#ifndef ELECTRIC_FIELD_MATRIX_H
#define ELECTRIC_FIELD_MATRIX_H

#endif //ELECTRIC_FIELD_MATRIX_H
class matrix {
private:
    double **a;
    int n, m;
public:
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
};
//прочитать матрицу с файла