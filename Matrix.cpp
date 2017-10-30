#include "Matrix.h"
#include "general.h"
#include <math.h>
//------------------------------ Implemenation  -----------------------------
Matrix::Matrix() //default constructor
{
        cout<<"default constructing matrix..."<<endl;
	rows=columns=0;
	buf=NULL;
}
Matrix::Matrix( int m,  int n)//declare an mxn matrix
{
        cout<<"constructing matrix with "<<m<<" rows"<<"and "<<n<<" columns"<<endl;
        buf=NULL;
        if (m>=0 && n>=0)
        {	rows=m;
                columns=n;
                buf = new double [m*n];
        }
        else
                cout<<"Please enter positive integers for the Matrix Dimensions"<<endl;
}
Matrix::Matrix(const Matrix& A) //copy constructor
{
        cout<<"copy constructor..."<<endl;
        rows=A.rows;
        columns=A.columns;
        buf=new double [rows*columns];
        for (int i=0; i<(rows*columns); i++)
        {	buf[i]=A.buf[i];
	}
}
Matrix::~Matrix()//destructor
{
        cout<<"Destructor: cleaning up...."<<endl;
        rows=0;
        columns=0;
        if (buf) delete[] buf;

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
Matrix Matrix::Adjugate() //Transpose of Cofactor Matrix
{
	Matrix tmp;
        if(rows==0||columns==0)
        {       cout<<"Matrix is empty"<<endl;
                return tmp;
        }
        if(rows!=columns)
        {       cout<<"This is not a Square Matrix, can not estimate Adjugate"<<endl;
                return tmp;
        }
	Matrix temp;
	temp=Cofactor();
	tmp= temp.Transpose();
	return tmp;
}
double Matrix::Cofactor(int i, int j) //cofactor Cij
{
	cout<<"Cofactor of a Matrix"<<endl;
        if(rows==0||columns==0)
	{	cout<<"Matrix is empty"<<endl;
		return 0;
	}
	if(rows!=columns)
        {       cout<<"This is not a Square Matrix, can not estimate cofactor"<<endl;
                return 0;
        }
        if(rows==1||columns==1)
        {       cout<<"Single value matrix, Can not estimate cofactor"<<endl;
                return 0;
        }
	double tmp;
	if ((i+j)%2==0)
	{	tmp=Minor(i,j);	
	}
	else
	{	tmp=Minor(i,j)*(-1);
	}
	return tmp;
}
Matrix Matrix::Cofactor()//matrix of cofactors
{
        Matrix tmp;
        if(rows==0||columns==0)
        {       cout<<"Matrix is empty"<<endl;
                return tmp;
        }
        if(rows!=columns)
        {       cout<<"This is not a Square Matrix, can not estimate cofactor"<<endl;
                return tmp;
        }
        if(rows==1||columns==1)
        {       cout<<"Single value matrix, Can not estimate cofactor"<<endl;
                return tmp;
	}
	tmp.rows=rows;
	tmp.columns=columns;
	tmp.buf= new double[rows*columns];

	for(int i=0;i<rows;i++)
	{	for(int j=0;j<columns;j++)
		{	tmp.buf[i*columns+j]=Cofactor(i,j);
		}
	}

	return tmp;
}
double Matrix::Minor(int i, int j)//Minor Mij
{
       
        if(rows==0||columns==0)
        {       cout<<"Matrix is empty"<<endl;
                return false;
        }
        if(rows!=columns)
        {       cout<<"This is not a Square Matrix, can not estimate minor"<<endl;
                return false;
        }
        if(rows==1||columns==1)
        {       cout<<"Single value matrix, Can not estimate minor"<<endl;
                return false;
        }

	double tmp;
	int row=this->rows-1;
	int column=this->columns-1;
	Matrix M (row, column);
	for (int a=0;a<row;a++)
	{	for (int b=0;b<column;b++)
		{	if (a>=i && b>=j)
			{	M.buf[a*column+b]=this->buf[(a+1)*columns+b+1];
			}
			if (a<i && b<j)
			{	M.buf[a*column+b]=this->buf[a*columns+b];
			}
			if (a>=i && b<j)
			{	M.buf[a*column+b]=this->buf[(a+1)*columns+b];
			}
			if (a<i && b>=j)
			{	M.buf[a*column+b]=this->buf[a*columns+b+1];
			}
		}
	}
	tmp= M.det();
	return tmp;
}
bool Matrix::IsSingular()
{
	if (fabs(this->det()-0)<0.00000001)
	{	cout<<"Singular matrix"<<endl;
	}
	else
	{	cout<<"Not singular Matrix"<<endl;
	}
	return (fabs(this->det()-0)<0.00000001);
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
	return columns;
};
Matrix Matrix::Transpose()  //transpose
{
        Matrix tmp;
	if(rows==0||columns==0)
        {       cout<<"Matrix is empty"<<endl;
                return tmp;
        }
	tmp.rows=this-> columns;
	tmp.columns= this-> rows;
	tmp.buf=new double [rows*columns];
	for(int i=0;i<tmp.rows;i++)
	{	for(int j=0;j<tmp.columns;j++)
		{	tmp.buf[i*tmp.columns+j]=buf[tmp.rows*j+i];
		}
	}
	return tmp;
}
Matrix Matrix::Inverse()//Inverse Matrix
{
	Matrix tmp;
	return tmp;
}
Matrix Matrix::Null(int n) //make a "zero" Matrix, with a new dimension, change "this"
{
	buf=new double[n*n];
	for(int i=0;i<(n*n);i++)
	{	buf[i]=0;
	}
	return *this;
}
Matrix Matrix::Null()//make a "zero" Matrix, does not change the dimension, change "this"
{
	for(int i=0;i<(rows*columns);i++)
	{	buf[i]=0;
	}
	return *this;
}
Matrix Matrix::Identity( int n)//make a nxn identity matrix,change "this"
{
    
        buf = new double [n*n];
        for (int i=0; i<n;i++)
	{	for (int j=0; j<n;j++)
		{	if (i==j)
			{	 buf[i*n+j]=1;
			}
                	else 
			{	buf[i*n+j]=0;
			}
		}
	}

	return *this;
}
Matrix Matrix::Identity()//make a identity matrix, does not change the dimentsion, change "this"
{
	if(rows=columns)
	{	for(int i=0;i<rows;i++)
		{	for(int j=0;j<columns;j++)
			{	if(i==j)
				{	buf[i*columns + j]=1;
				}
				else
				{	buf[i*columns + j]=0;
				}
			}
		}
	}
	else
	{	cout<<"Matrix must be square"<<endl;
	}
	return *this;
}
bool Matrix::LU(Matrix& L, Matrix& U)//LU decomposition. return true if successful
{
	if (rows != columns)
	{	cout<<"Matrix must be square to decomposite"<<endl;
		return false;
	}
	L.rows=U.rows=rows;
	L.columns=U.columns=columns;
	L.buf=new double [rows*columns];
	U.buf=new double [rows*columns];

	for(int i=0; i<rows*columns; i++)
	{	U.buf[i]=buf[i]; // initialized L and U
		L.buf[i]=0;
	}

	for (int i=0;i<rows;i++)
	{	L.buf[i*columns+i]=1; //Do diagonal elements= 1
		for(int j=i+1;j<rows;j++)
		{	L.buf[j*columns+i]= U.buf[j*columns+i]/U.buf[i*columns+i];
			for(int k=0; k<rows;k++)
			{	U.buf[j*columns+k]=U.buf[j*columns+k]-(L.buf[j*columns+i]*U.buf[i*columns+k]);
			}
		}
	}
	
	for (int i=1;i<rows;i++) // Upper elements of Upper matrix = 0
	{	for (int j=0;j<i;j++)
		{	U.buf[i*rows+j]=0;
		}
	}
		return true;	
}
bool Matrix::QR(Matrix& Q, Matrix& R)
{
	return true;
}
double Matrix::det()//determinant(Matrix)
{
	double tmp;
	Matrix aux;
	aux=*this;
	Matrix L;
	Matrix U;
	aux.LU(L,U);
	for (int i=0; i<columns; i++)
	{	aux.buf[i]=L.buf[i*columns+i]*U.buf[i*columns+i];
	}
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
	Matrix M;
	Matrix inv;
	M.rows=rows;
	M.columns=columns;
	inv.rows=rows;
	inv.columns=columns;

	M=*this;
	inv=M.Inverse();
	tmp=inv*b;

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
	tmp*=a;
	return tmp;
};


Matrix operator * (const Matrix& A, double a ) //Matrix A*a, using *= .....
{
	Matrix tmp=A;
	//do A*a
	tmp*=a;
	return tmp;
};

Vector operator * (const Vector& b, const Matrix& A ) //Matrix A*a, using *= .....
{
	//do b*A
	int c= A.GetColumns();
	int r= A.GetRows();

	Vector tmp;
	if (b.Size()!=c)
	{	cout<<"Vector x Matrix can not be multiplied because of dimension issues"<<endl;
	}
	else
        {	for (int i=0;i<c;i++)
        	{	for(int j=0;j<r;j++)
                	{       tmp[i]=tmp[i]+b[j]*A(i,j);
			}
		}
	}
	return tmp;
};
Vector operator * (const Matrix& A, const Vector& b) //Matrix A*b, 
{
	Vector tmp;
	//do A*b
	int c= A.GetColumns();
	int r= A.GetRows();

	if (c!=1 && r!=1)
	{	cout<<"The matrix must be dimension 1x1 to generate a vector"<<endl;
	}
	else
        {	for (int i=0; i<r;i++)
        	{	for(int j=0;j<c;j++)
                	{	tmp[i]=tmp[i]+A(i,j)*b[i];
			}
		}
	} 
	return tmp;
}

