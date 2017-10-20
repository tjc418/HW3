#include "Vector.h"
#include "general.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;
//------------------------------ Implemenation  -----------------------------
Vector::Vector()
{
	cout<<"default constructing vector..."<<endl; // Standard constructor 
        size=0;
        buf=NULL;
}

Vector::Vector(int s)
{
	cout<<"constructing vector with "<<s<<" component(s)"<<endl;
        size=s;
        buf= new double[s];

}

Vector::Vector(const Vector& A)
{
	cout<<"copy constructor..."<<endl;
        this->size=A.size; // "this" the pointer points the object it self
        buf=new double [size];
        for(int i=0;i<size;i++)
        {	buf[i]=A.buf[i];
	}
}

Vector::~Vector()
{
        cout<<"Destructor: cleaning up...."<<endl;
        size=0;
        if(buf)
	{       delete[] buf;
        	buf=NULL;
	}
}

//Operator overloading
Vector& Vector::operator = (const Vector& B)//Bector B is const, I want to change Vector A
{
	if(buf) delete[] buf;//delete buffer of A
	{	size = B.size;
		buf = new double[B.size];
		for (int i=0; i<size; i++)
		{	buf[i]=B.buf[i];
		}
	}
	return *this;
}

bool Vector::operator ==(const Vector& B)
{
        if(size!=B.size) return false;
        for(int i=0;i<size;i++)
        {       if(buf[i] != B.buf[i]) return false;
	}
	return true;
}
bool Vector::operator !=(const Vector& B)
{

	return !(*this == B);
}
Vector Vector::operator +(const Vector& B)
{
	Vector tmp;
	for(int i=0;i<size;i++)
	{	tmp.buf[i] = buf[i] + B.buf[i];
	}
	return tmp;
}
Vector Vector::operator -(const Vector& B)
{
	Vector tmp;
        for(int i=0;i<size;i++)
        {       tmp.buf[i] = buf[i] - B.buf[i];
	}
	return tmp;
}
Vector Vector::operator *(double a) //vector A*a
{
	Vector tmp;
	for(int i=0;i<size;i++)
	{	tmp.buf[i] = buf[i]*a;
	}
	return tmp;

}
double Vector::operator *(const Vector& B) //dot product
{
	if(size!=B.size) return false; 
	
	double x=0;
	for(int i=0;i<size;i++)
	{	x  = buf[i]*B.buf[i];
	}
	return x;
}
double& Vector::operator [](int i)//A[i];
{
        if(i<0 || i>=size)
        {//error...
        }

	return buf[i]; //unsafe!
}
double& Vector::operator [](int i) const//A[i], read only;
{
        if(i<0 || i>=size)
        {//error...
        }

	return buf[i]; //unsafe!
}
		
//Member functions
int Vector::Size() //get the size of the Vector
{
	return size;
}
bool Vector::Insert(double x, int location) //insert x at location
{
	if(location>size+1)
        {
        	return false;
        }
        else
        {
		cout<<"Vector after inserting location"<<endl;
		double*p = buf;
		buf=new double [size+1];
		size= size+1;
		for(int i=0;i<location;i++) //insert in buf all the values until location
		{	buf[i]=p[i];
			cout<<buf[i]<<" ";
		}
		buf[location]=x; //Insert the value of x, for the location selected
		cout<<buf[location]<<" ";

		for(int i=location+1;i<size;i++) // inser in buf the values after location
		{	buf[i]=p[i-1];
			cout<<buf[i]<<" ";
		} 
		cout<<" "<<endl;
		delete[]p;
	}
	return true;
}

bool Vector::Remove(int location)//remove the value at location
{
	return true;
}
void Vector::Clear()//remove all data from the Vector.
{
	if(buf) delete[] buf;
	size=0;
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
