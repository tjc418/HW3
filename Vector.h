//Matrix.h

#ifndef Vector_h
#define Vector_h

#include <iostream>
//#include <exception>
using namespace std;
//----------------------------Definition of a Vector class-----------------------------------------------

class Vector 
 {
	public:
		Vector(); //default constructor
		Vector(int s);//constructor
		Vector(const Vector& a); //Copy Constructor

		~Vector(); //destructor

		//Operator overloading
		Vector& operator = (const Vector& B);
		bool operator ==(const Vector& B);
		bool operator !=(const Vector& B);
		Vector operator +(const Vector& B);
		Vector operator -(const Vector& B);
		Vector operator *(double a); //vector A*a
		double operator *(const Vector& B); //dot product
		double& operator [](int i);//A[i];
		double& operator [](int i) const;//A[i], read only;
		
		//Member functions
		int Size() const; //get the size of the Vector
		bool Insert(double x, int location); //insert x at location
		bool Remove(int location);//remove the value at location
		void Clear();//remove all data from the Vector.
		void Sort(bool Ascending=true); //sorting.

 private:
		int size;
		double* buf;



	//I/O   << and >>
	friend ostream& operator << (ostream& output, const Vector& A);
	friend istream& operator >> (istream& input, Vector& A);

};
	Vector operator *(double a, const Vector& A);// a*A, why global function overloading?	


#endif
