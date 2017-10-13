#include "Vector.h"
#include "general.h"
#include <math.h>
//------------------------------ Implemenation  -----------------------------
Vector::Vector()
{
}
Vector::Vector(int s)
{
}
Vector::Vector(const Vector& a)
{
}
Vector::~Vector()
{
}

//Operator overloading
Vector& Vector::operator = (const Vector& B)
{
	return *this;
}
bool Vector::operator ==(const Vector& B)
{

}
bool Vector::operator !=(const Vector& B)
{
	return !(*this == B);
}
Vector Vector::operator +(const Vector& B)
{
	Vector tmp;
	return tmp;
}
Vector Vector::operator -(const Vector& B)
{
	Vector tmp;
	return tmp;
}
Vector Vector::operator *(double a) //vector A*a
{
	Vector tmp;
	return tmp;

}
double Vector::operator *(const Vector& B) //dot product
{
	double x=0;
	return x;
}
double& Vector::operator [](int i)//A[i];
{
	return buf[i]; //unsafe!
}
double& Vector::operator [](int i) const//A[i], read only;
{
	return buf[i]; //unsafe!
}
		
//Member functions
int Vector::Size() //get the size of the Vector
{
	return size;
}
bool Vector::Insert(double x, int location) //insert x at location
{
}
bool Vector::Remove(int location)//remove the value at location
{
	return true;
}
void Vector::Clear()//remove all data from the Vector.
{
}
void Vector::Sort(bool Ascending) //sorting.
{
}

ostream& operator << (ostream& output, const Vector& A)
{
	return output;
}
istream& operator >> (istream& input, Vector& A)
{
	return input;
}

Vector operator *(double a, const Vector&A)	// a*A, why global function overloading?	
{
	Vector tmp=A;

	return tmp;
}
