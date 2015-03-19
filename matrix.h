#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
    Matrix(std::vector<std::vector<int>> mat);
    ~Matrix();
private:
    std::vector<std::vector<int>> m;
};

#endif // MATRIX_H
