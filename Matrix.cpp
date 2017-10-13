#include "Matrix.h"
#include "general.h"
#include <math.h>
//------------------------------ Implemenation  -----------------------------
//this will be hard

// you bet your ass
Matrix::Matrix() //default constructor
{
	rows=columns=0;
	buf=NULL;
}
Matrix::Matrix( int m,  int n)//declare an mxn matrix
{
}
Matrix::Matrix(const Matrix& A) //copy constructor
{
}
Matrix::~Matrix()//destructor
{
}
//Assignment
Matrix& Matrix::operator = (const Matrix& A) //overloading =
{
	return *this;
}
//operators
bool Matrix::operator == (const Matrix& A)//overloading ==
{
	return true;
}
bool Matrix::operator != (const Matrix& A)//overloading !=
{
	return !(*this==A); //use ==
}
Matrix& Matrix::operator += (const Matrix& A) //overloading +=
{
	return *this;
}
Matrix& Matrix::operator -=(const Matrix& A) //overloading -=
{
	return *this;
}
Matrix& Matrix::operator *=(const Matrix& A) //overloading *=
{
	return *this;
}

Matrix& Matrix::operator *=(double a) //overloading *=
{
	return *this;
}
Matrix& Matrix::operator *=(const Vector& b) //overloading *=
{
	return *this;
}

Matrix Matrix::operator + () //unary +
{
	return *this; //good enough.
}
Matrix Matrix::operator - () //unary -
{
	Matrix tmp;
	return tmp;
}
double& Matrix::operator ()( int i,  int j)// access (i,j)
{
	return buf[i*columns+j]; // is this correct? Unsafe
}
double& Matrix::operator()( int i,  int j) const //read only
{
	return buf[i*columns+j]; // is this correct? Unsafe
}
ostream& operator << (ostream& output, const Matrix& A) 
{
	//should we output the dimension first?
	for ( int i = 0; i < A.GetRows(); i++) 
	{
		for ( int j = 0; j < A.GetColumns(); j++)
			output << A(i,j) << "\t   ";
		output << endl; 
	}
	return output; 
}

istream& operator >> (istream& input, Matrix& A) 
{

	//use BypassComment to skip comments.

	return input;
}


//------------Member Functions------------------------------
Matrix Matrix::Adjugate() //Adjoint/Adjugate
{
	Matrix tmp; 
	return tmp;
}
double Matrix::Cofactor(int i, int j) //cofactor Cij
{
	double tmp;
	return tmp;
}
Matrix Matrix::Cofactor()//matrix of cofactors
{
	Matrix tmp;
	return tmp;
}
double Matrix::Minor(int i, int j)//Minor Mij
{
	double tmp;
	return tmp;
}
bool Matrix::IsSingular()
{
	return (this->det()==0);  //may not work, because of double precision. you fix it.
}
bool Matrix::IsSymmetric()
{
	return ((*this)==(this->Transpose()));
}
const int Matrix::GetRows() const
{
	return rows;
};

const int Matrix::GetColumns() const
{
	return columns; //
};
Matrix Matrix::Transpose()  //transpose
{
	Matrix tmp;
	return tmp;
}
Matrix Matrix::Inverse()//Inverse Matrix
{
	Matrix tmp;
	return tmp;
}
Matrix Matrix::Null(int n) //make a "zero" Matrix, with a new dimension, change "this"
{
	return *this;
}
Matrix Matrix::Null()//make a "zero" Matrix, does not change the dimension, change "this"
{
	return *this;
}
Matrix Matrix::Identity( int n)//make a nxn identity matrix,change "this"
{
	return *this;
}
Matrix Matrix::Identity()//make a identity matrix, does not change the dimentsion, change "this"
{
	return *this;
}
bool Matrix::LU(Matrix& L, Matrix& U)//LU decomposition. return true if successful
{
		return true;	
}
bool Matrix::QR(Matrix& Q, Matrix& R)
{
	return true;
}
double Matrix::det()//determinant(Matrix)
{
	double tmp;
	return tmp;
}
Vector Matrix::Eigenvalues()//find the eigen values and store them in a vector 
{
	Vector tmp;
	return tmp;
}
Vector Matrix::Root(const Vector& b)//solving linear system of equations. b is actually a vector (mx1 Matrix) 
{
	Vector tmp;
	return tmp;
}
//------------------------------------------------------------------------------------------------
//operators, + - * can be overloaded as global operators

Matrix operator + (const Matrix& A, const Matrix& B) //Matrix A+B, using += .....
{
	Matrix tmp=A;
	tmp+=B;//use "+="
	return tmp;//
}

Matrix operator - (const Matrix& A, const Matrix& B) //Matrix A+B, using -= .....
{
	Matrix tmp=A;
	tmp-=B;//use "-="
	return tmp;//
}

Matrix operator * (const Matrix& A, const Matrix& B) //Matrix A+B, using *= .....
{
	Matrix tmp=A;
	tmp*=B;//use "*="
	return tmp;//
}


Matrix operator * (double a, const Matrix& A) //Matrix a*A, using *= .....
{
	Matrix tmp=A;
	//do a*A

	return tmp;
};


Matrix operator * (const Matrix& A, double a ) //Matrix A*a, using *= .....
{
	Matrix tmp=A;
	//do A*a

	return tmp;
};

Vector operator * (const Vector& b, const Matrix& A ) //Matrix A*a, using *= .....
{
	Vector tmp;
	//do b*A

	return tmp;
};
Vector operator * (const Matrix& A, const Vector& b) //Matrix A*b, 
{
	Vector tmp;
	//do A*b

	return tmp;
}

