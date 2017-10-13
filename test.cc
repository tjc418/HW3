#include "Matrix.h"
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	Matrix x;
	Matrix A;
	Matrix B;
	Matrix C;
	ifstream ins(argv[1]);
	ins>>A;
	ins.close();
	ifstream ins2(argv[2]);
	ins2>>B;
	ins2.close();
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
	//Testing assignment
	C=B;
	if(C!=B)
		{
			errf<<"Failure: Assignment"<<endl;
			err++;
		}	
	//Test Addition
	C=A+B;
	D=B+A;
	if(C!=D)
		{
			errf<<"Failure: Addition"<<endl;
			err++;

		}
	//More.........................




	//Display testing results: YOu can find all the errors in the file
	cout<<"Total Errors: "<<err<<endl;
	errf<<"Total errors: "<<err<<endl;
	errf.close();

	return 0;
}

