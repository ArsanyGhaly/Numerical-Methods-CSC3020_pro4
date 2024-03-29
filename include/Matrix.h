#if !defined MATRIX_H
#define MATRIX_H

//the indices are 1-based!!
namespace CSC2110
{
class Matrix
{
   private:
      int rows;
      int cols;

      double* mat;
	  
	  Matrix** PLU();
      Matrix* copy();
      Matrix* forwardSubstitution(Matrix* col);
      Matrix* backSubstitution(Matrix* col);
	  Matrix* pivotRows(int row1, int row2);

   public:
      Matrix(int rows, int cols);  //constructor
      ~Matrix();                   //destructor
	  
      void displayMatrix();
      int getNumRows();
      int getNumCols();

      double getElement(int row, int col);
      void setElement(int row, int col, double val);

      Matrix* add(Matrix* other);
      Matrix* multiply(Matrix* other);

      static Matrix* readMatrix(const char* file_name);  //discuss static
      void writeMatrix(const char* file_name);
	  
	  Matrix* transpose();
	  Matrix* inverse();
	  const float* toArrayColumnMajor();
};
}

#endif
