#include "Matrix.h"
#include <fstream>
using namespace std;

//#######################################################################################################
//___________________________----------------Inputs-----------------------------------------------------#
// ./test (file Matrix a*b)	(file Matrix a*b)	(file Matrix b*a)	(file Matrix c*c)	#
//#######################################################################################################

int main(int argc, char* argv[])
{
	Matrix x;
	Matrix T;
	Matrix A;
	Matrix B;
	Matrix C;
	ifstream ins(argv[1]);
	ins>>A;
	ins.close();
	ifstream ins2(argv[2]);
	ins2>>B;
	ins2.close();
        ifstream ins3(argv[3]);
        ins3>>T;
        ins3.close();

	//Testing....
	int err=0;
	ofstream errf("error.txt");
	Matrix L,U;

	//Test copy constructor;
	Matrix D(A);
	if(A!=D)
		{
			errf<<"Failure: Copy constructor"<<endl;
			err++;
		}
	//Test GetRows() & GetColumns:
	if((A.GetRows()!=D.GetRows()) || (A.GetColumns()!=D.GetColumns()))
                {
                        errf<<"Failure: GetRows/Columns()"<<endl;
                        err++;
                }
	cout<<A.GetRows()<<" rows in A"<<endl<<endl<<endl<<endl<<"Columns in D"<<D.GetColumns()<<"_____________"<<endl;



	//Testing assignment
	C=B;
	if(C!=B)
		{
			errf<<"Failure: Assignment"<<endl;
			err++;
		}
	//Test Addition
	C=A+B;
	D=B+A+B;
	if(C!=(D-B))
		{	if((A.GetRows())==(B.GetRows()) && (A.GetColumns())==(B.GetColumns()))
			{
				errf<<"Failure: Addition"<<endl;
				err++;
			}
		}
	//More.........................
	//Test Unary -
	C=-A;
	D=B;
	if((-C)!=A)
                {
                        errf<<"Failure: Unary - "<<endl;
                        err++;
                }

	//Test M*b
	C=C*(-1);
	if((C)!=A)
                {
                        errf<<"Failure: M*b"<<endl;
                        err++;

                }
	C=C*(-2);
	//Test b*M
        if((C)!=(-2*A))
                {
                        errf<<"Failure: b*M"<<endl;
                        err++;

                }
	if((1.2*C)!=(C*1.2))
                {
                        errf<<"Failure: b*M vs M*b"<<endl;
                        err++;

                }
	//Test BC's
	double dub=(A(-1,1));		//Should return A(0,0) as error output
		if(dub!=A(0,0))
                {
                        errf<<"Failure: BC"<<endl;
                        err++;

                }
	//Test  BC's
        dub=(A(1,1000));           //Should return A(0,0) as error output
                if(dub!=A(0,0))
                {
                        errf<<"Failure: BC"<<endl;
                        err++;

                }

        //Test  A(i,j)
        dub=(A(1000000000,1));           //Should return A(0,0) as error output
                if((B(1,1))!=(D(1,1)))
                {
                        errf<<"Failure: Index Number Grabber"<<endl;
                        err++;

                }



//	cout<<"dub A(2,3) is"<<dub<<endl;
//	cout<<"B(12) is "<<B(1,2)<<"Buttttttttttttt D(12) is"<<D(1,2)<<endl<<endl;

//Test Assignent With Different Dimensions
	D=T;
	if(D!=T)
                {
                        errf<<"Failure: Assignment Dimensions"<<endl;
                        err++;

                }
//Test Many Vector Addition
	D=D+T+T+T+T+T+T+T+T+T+T+T+T+T+T;
	C=15*T;
	if(C!=D)
                {
                        errf<<"Failure: Large Addition or b*M"<<endl;
                        err++;

                }

//Matrix Multiplication M*M
	C=A*T;		//Individually checked these for 2*4 & 4*2 Matrices
	D=T*A;		//Ran with  100*1 & 1*100 matrices
	if(A!=T)
	{
		if(C==D)
                {
			errf<<"Failure: M*M"<<endl;
			err++;
		}
	}
//FINISHED TESTING OPERATORS
//output current vector status
	cout<<"After testing operators the vectors so far are:"<<endl<<endl<<endl<<endl;
        cout<<"Vector A: "<<A<<endl;
        cout<<"Vector B: "<<B<<endl;
        cout<<"Vector C: "<<C<<endl;
        cout<<"Vector D: "<<D<<endl;
        cout<<"Vector T: "<<T<<endl;
        cout<<"Total Errors: "<<err<<endl;


//Use 4th input to make D a square Matrix
        ifstream ins4(argv[4]);
        ins4>>D;
        ins4.close();
	cout<<"Square Matrix D starts as"<<D<<endl;

//Test Cofactor
	C=D.Cofactor();		//Cofactors seems to work (tested 3*3). 
//Test Minor
	double m11=D.Minor(1,1);
	cout<<"The M11  of D is    "<<m11<<endl;
        m11=D.Minor(1,2);
        cout<<"The M12  of D is    "<<m11<<endl;
        m11=D.Minor(1,3);
        cout<<"The M11  of D is    "<<m11<<endl;
//Test Determinant
	double deter= D.det();				//Fixed Determinant and seemed to work well. Need to fix +/- issue.
	cout<<"The Determinant of D is"<<deter<<endl<<endl;

//Test LU Decomposition
				//Tested on limited 3b3 matrix, returned correct result. Should run with larger Matrix
	D.LU(L,U);
	cout<<"L is:"<<endl<<L<<endl;
	cout<<"U is:"<<endl<<U<<endl;





	//Display testing results: YOu can find all the errors in the file

	cout<<"Vector A: "<<A<<endl;
	cout<<"Vector B: "<<B<<endl;
	cout<<"Vector C: "<<C<<endl;
	cout<<"Vector D: "<<D<<endl;
        cout<<"Vector T: "<<T<<endl;
	cout<<"Total Errors: "<<err<<endl;
	errf<<"Total errors: "<<err<<endl;
	errf.close();

	return 0;
}

//__________Need to test
/*
Transpose
Inverse
Null
Null
Identity
Identity
Fix det()
Root
All Vector Calulations
All vector overloading
_________Need to work on
Handling Null vectors
Memory Allocation
Making More durable
_____________________
Everything after brief testing and fixes seems to be working great!
*/
