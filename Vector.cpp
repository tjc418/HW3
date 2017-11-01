#include "Vector.h"
#include "general.h"
#include <math.h>
#include <cmath>
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

        this->size=A.size; // "this" the pointer points the object it self
	cout<<"size is "<<size<<endl;
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
	double er;
        if(size!=B.size) return false;
        for(int i=0;i<size;i++)
        {       
		er=(abs(buf[i] -  B.buf[i]))/((buf[i]+B.buf[i])/2);
		if(er>.00001) return false;
	}
	return true;
}
bool Vector::operator !=(const Vector& B)
{

	return !(*this == B);
}
Vector Vector::operator +(const Vector& B)
{

	Vector tmp(size);
	if(size!=B.size)
	{
		cout<<"Vectors cannot be added"<<endl;
		return tmp;
	}

	for(int i=0;i<size;i++)
	{	tmp.buf[i] = buf[i] + B.buf[i];
	}
	return tmp;
}
Vector Vector::operator -(const Vector& B)
{
	Vector tmp(size);
        if(size!=B.size)
        {
                cout<<"Vectors cannot be subtracted, don't you know?"<<endl;
                return tmp;
        }



        for(int i=0;i<size;i++)
        {       tmp.buf[i] = buf[i] - B.buf[i];
	}
	return tmp;
}
Vector Vector::operator *(double a) //vector A*a
{
	Vector tmp(size);
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
	{	x  = x+ buf[i]*B.buf[i];
	}
	return x;
}
double& Vector::operator [](int i)//A[i];
{
        if(i<0 || i>=size)
        {//error...
	cout<<"well that didn't work"<<endl;
	return buf[0];
        }

	return buf[i]; //unsafe!
}
double& Vector::operator [](int i) const//A[i], read only;
{
        if(i<0 || i>=size)
        {//error..
		cout<<"Wrong i"<<endl;
		return buf[0];
        }

	return buf[i]; //unsafe!
}

//Member functions
int Vector::Size() const  //get the size of the Vector
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
	if(location>=size)
	{	cout<<"Location is not in the Vector"<<endl;
		return false;
	}
	else
	{	cout<<"Vector after removing location"<<endl;
                for(int i=0;i<location;i++) //insert in buf all the values until location
		{       cout<<buf[i]<<" ";
                }
		for(int i=location+1;i<size;i++)
		{	buf[i-1]=buf[i];
			cout<<buf[i]<<" ";
		}
		cout<<endl;
		size= size-1;
	}
                return true;

}
void Vector::Clear()//remove all data from the Vector.
{
	if(buf) delete[] buf;
	size=0;
}
void Vector::Sort(bool Ascending) //sorting.
{
                if (Ascending==true) 
                {
                int i;
                int j;
                int aux;
                cout<<"Sorted vector(Ascending)"<<endl;
                for (int i=size-1; i>=0; i=i-1)
                {
                        for (int j=0; j<size-1;j++)
                        {
                                if (buf[j]<buf[j+1])
                                {
                                        aux=buf[j];
                                        buf[j]=buf[j+1];
                                        buf[j+1]=aux;
                                }
                        }
                                cout<<buf[i]<<" ";
                }
                        cout<<endl;
                }
                else
                {
                        int i;
                        int j;
                        int aux;
                        for (int i=size-1; i>=0; i=i-1)
                        {
                                for (int j=0; j<size-1;j++)
                                {
                                        if (buf[j]>buf[j+1])
                                        {
                                                aux=buf[j];
                                                buf[j]=buf[j+1];
                                                buf[j+1]=aux;
                                        }
                                }
                                cout<<buf[i]<<" ";
                        }
                        cout<<endl;
                }

}

ostream& operator << (ostream& output, const Vector& A)
{	
	cout<<"[";
        for(int i=0; i<A.size;i++)
        {        output<<A[i]<<" ";
	}
	cout<<"]"<<endl;
	return output;
}
istream& operator >> (istream& input, Vector& A)
{
        if(A.buf) delete[] A.buf;
	BypassComment (input);//Eliminate the blank spaces in the input file
	input>>A.size;
        A.buf=new double[A.size];
        for(int i=0;i<A.size;i++)
        {	input>>A[i];
	}
	return input;
}

Vector operator *(double a, const Vector& A)	// a*A, why global function overloading?	
{
        Vector tmp(A);
        for(int i=0; i<A.Size();i++)
                tmp[i]=a*A[i];
        return tmp;

}
