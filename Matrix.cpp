#include "Matrix.h"
#include "general.h"
#include <math.h>
//------------------------------ Implemenation  -----------------------------
//this will be hard

// you bet your ass
Matrix::Matrix() //default constructor
{
	cout<<"default constructing Matrix..."<<endl;
	rows=columns=0;
	buf=NULL;
}
Matrix::Matrix( int m,  int n)//declare an mxn matrix
{
	cout<<"Constructing "<<m<<"by "<<n<<"Matrix"<<endl;
	rows = m ;
	columns = n ;
	buf = new double[rows*columns];
}
Matrix::Matrix(const Matrix& A) //copy constructor	//is there a benefit or necessity for using this-> pointer?
{
	cout<<"Copying  Matrix "<<A<<"..."<<endl;
	rows = A.rows;					//this->rows	?
	columns =  A.columns;				//this->columns	?
	buf = new double[rows*columns];
	for(int i=0;i<rows*columns;i++)
	{
		buf[i]=A.buf[i];
	}
}
Matrix::~Matrix()//destructor
{
	cout<<"Janitor is cleaning up. Destructing  Matrix..."<<endl;	//is there a way to say "Destructing Matrix "<<*this<<endl ?
	rows=0;
	columns=0;
	if(buf)
	{
	delete[] buf;
	buf=NULL;
	}
}
//Assignment
Matrix& Matrix::operator = (const Matrix& A) //overloading =
{
	if(buf) delete[] buf; //deletes buffer of "this"
	rows = A.rows;
	columns = A.columns;
	buf = new double[rows*columns];
        for(int i=0;i<rows*columns;i++)
        {
                buf[i]=A.buf[i];
        }

	return *this;

}
//____________________operators______________________________________

bool Matrix::operator == (const Matrix& A)//overloading ==		//fix for tolerance!! -T	//Handle NULL Matrices! -T
{
	if(rows!=A.rows || columns!=A.columns) return false;
        for(int i=0;i<rows*columns;i++)
        {
                if(buf[i]!=A.buf[i]) return false;
        }

	return true;
}
bool Matrix::operator != (const Matrix& A)//overloading !=
{
	return !(*this==A); //use ==
}
Matrix& Matrix::operator += (const Matrix& A) //overloading +=
{
        if(rows!=A.rows || columns!=A.columns)		//Check for same dimensions
	{
	cout<<"Matrices of different dimensions, returning original Matrix"<<endl;
	return *this;
	}
							//Add buffer values
        for(int i=0;i<rows*columns;i++)
        {
		buf[i]=buf[i]+A.buf[i];
        }
	return *this;
}
Matrix& Matrix::operator -=(const Matrix& A) //overloading -=
{
	if(rows!=A.rows || columns!=A.columns)          //Check for same dimensions
	{
	cout<<"Matrices of different dimensions, returning original Matrix"<<endl;
	return *this;
	}
	                                                //Subtract buffer values
	for(int i=0;i<rows*columns;i++)
	{
		buf[i]=buf[i]-A.buf[i];
	}
	return *this;
}
Matrix& Matrix::operator *=(const Matrix& A) //overloading *=
{

        if(columns!=A.rows)          //Check for same dimensions
        {
        cout<<"Cannot multiply, returning original Matrix"<<endl;
        return *this;
        }
	Matrix tmp(rows, A.columns);
	double sum;
	int nrows=rows;
	int ncols=A.columns;

        for(int i=0; i<nrows; i++)			//counts through new Matrix Rows
        {
		for(int j=0; j<ncols; j++)		//counts through new Matrix Columns
		{	sum=0;
			for(int k=0; k<rows; k++)	//Provides Numerical Value for Mat[i,j]
			{
				sum = sum + buf[i*columns+k]*A.buf[k*A.columns+j];
			}
			tmp.buf[i*ncols+j]=sum;
		}
        }
	*this=tmp;

	return *this;
}

Matrix& Matrix::operator *=(double a) //overloading *=
{
	for(int i=0; i<rows*columns; i++)
	{
		buf[i]=buf[i]*a;
	}

	return *this;
}

Matrix& Matrix::operator *=(const Vector& b) //overloading *=		does this work?
{
	const int Sizeb=b.Size();

	Matrix tmp(1,Sizeb);
	if(rows!=1)
	{
	cout<<"Cannot compute cross product, matrix has more than 1 column, returning original Matrix"<<endl;
	return *this;
	}
	for(int i=0; i<Sizeb; i++)       //turn vector into [1*size] matrix
	{
		tmp.buf[i]=b[i];
	}


					//return the cross product
	return ((*this)*=tmp);
}

Matrix Matrix::operator + () //unary +
{
	return *this; //good enough.
}
Matrix Matrix::operator - () //unary -
{
	Matrix tmp;
	tmp=(*this)*(-1);
	return tmp;
}
double& Matrix::operator ()( int i,  int j)// access (i,j)
{
	return buf[i*columns+j]; // is this correct? Unsafe	//why is this unsafe?? -T
}
double& Matrix::operator()( int i,  int j) const //read only
{
	return buf[i*columns+j]; // is this correct? (yes).  Unsafe (Why??) -T
}
ostream& operator << (ostream& output, const Matrix& A)
{
	//should we output the dimension first?		//Sure I guess...
	cout<<"Outputting "<<A.GetRows()<<" x "<<A.GetColumns()<<" Matrix"<<endl;
	for ( int i = 0; i < A.GetRows(); i++)
	{
		for ( int j = 0; j < A.GetColumns(); j++)
			output << A(i,j) << "\t   ";
		output << endl;
	}
	return output; }

istream& operator >> (istream& input, Matrix& A)	//Is this right? Can we simply use i cnt and A.buf, or is there a scope issue preventing?
{

	//use BypassComment to skip comments.
        if(A.buf) delete[] A.buf;
        BypassComment (input);
        input>>A.rows;
	input>>A.columns;		//can remove this if figure out how to input number of data	-T
	BypassComment (input);		//only need one of these -T

//	input>>ndata;			//Is this correct? I have no idea how to input number of data. If not input, I would like to check  that ndata=m*n,
					// or check that all matrix is full -T
        A.buf=new double[A.rows()*A.columns()];
	for(int i=0;i<A.rows;i++)
	{
		for(int j=0; j<A.columns; i++)
		{
			input>>A(i,j);
		}
	}

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

