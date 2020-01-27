/* Priyanshu kumar Kharwar
		19HCS4041 */
#include<iostream>
using namespace std;
class Polynomial
{
  private:
  	int size;
  	int *arr;
  	
    // Variables to store information about polynomial
  public:
    Polynomial()
    {
      // Behavior of default constructor
    }

    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      size=deg;
      arr=new int[size+1];
    }
    Polynomial(const Polynomial &m) 
	{
		size=m.size;
		arr=new int[size+1];
		for(int i=size;i>=0;i--)
		{
			arr[i]=m.arr[i];
		}
    } 
    ~Polynomial()
    {
      // Behavior of destructor Clear the allocation of memory
    }
  
    //  Overload copy constructor, +, - and = operators
    Polynomial operator +(Polynomial m1)
    {
    	int i,j;
    	Polynomial tmp;
    	if(size>m1.size)
    	{
    		tmp.size=size;
    		tmp.arr=new int[tmp.size+1];
    		for(i=size,j=m1.size;i,j>=0;)
    		{
    			if(i!=j)
    			{
    				tmp.arr[i]=arr[i];
    				i--;
				}
				else
				{
					tmp.arr[i]=arr[i]+m1.arr[j];
					i--;
					j--;
				}
			}
		}
		else
		{
			
			tmp.size=m1.size;
			tmp.arr=new int[tmp.size+1];
			for(i=m1.size;j=size;j>=0)
			  {
					if(i!=j)
    			   {
    				tmp.arr[i]=arr[i];
    				i--;
				   }
				else
				   {
					tmp.arr[i]=arr[i]+m1.arr[j];
					i--;
					j--;
				   }
			}
		}
		return tmp;
	}
	Polynomial operator -(Polynomial m2)
	{
		int i,j;
    	Polynomial tmp;
    	if(size>m2.size)
    	{
    		tmp.size=size;
    		tmp.arr=new int[tmp.size+1];
    		for(i=size,j=m2.size;i,j>=0;)
    		{
    			if(i!=j)
    			{
    				tmp.arr[i]=arr[i];
    				i--;
				}
				else
				{
					tmp.arr[i]=arr[i]-m2.arr[j];
					i--;
					j--;
				}
			}
		}
		else
		{
			tmp.size=m2.size;
			tmp.arr=new int[tmp.size+1];
			for(i=m2.size;j=size;j>=0)
			  {
					if(i!=j)
    			   {
    				tmp.arr[i]=arr[i];
    				i--;
				   }
				else
				   {
					tmp.arr[i]=arr[i]-m2.arr[j];
					i--;
					j--;
				   }
			}
		}
		return tmp;
	}
	void operator =(Polynomial m3)
	{
		size=m3.size;
		arr=new int[size+1];
		for(int i=size;i>=0;i--)
		{
			arr[i]=m3.arr[i];
		}
	}
  
    void storePolynomial()
    {
      //  Code to enter and store polynomial
      for(int i=size;i>=0;i--)
      {
      	cout<<"Enter the Coefficient of Polynomial x^"<<i<<" : ";
      	cin>>arr[i];
	  }
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      for(int i=size;i>0;i--)
      {
      	cout<<arr[i]<<"x^"<<i<<" + ";
	  }
	  cout<<arr[0];
    }
  
};

int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond 
  cout<<"Enter the degree of first polynomial "<<endl;
  cin>>degFirst;
  cout<<"Enter the degree of second polynomial "<<endl;
  cin>>degSecond;
  cout<<endl;
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  cout<<"Storing and Displaying the first Polynomial ";
  cout<<endl;
  firstPolynomial.storePolynomial();
  firstPolynomial.display();
  cout<<endl;
  cout<<"Storing and Displaying the second polynomial ";
  cout<<endl;
  secondPolynomial.storePolynomial();
  secondPolynomial.display();
  cout<<endl;
  cout<<"Performing Addition of both Polynomial ";
  cout<<endl;
  Polynomial thirdPolynomial;
  thirdPolynomial=firstPolynomial+secondPolynomial;
  thirdPolynomial.display();
  cout<<endl;
  cout<<"Performing Subtraction of both Polynomial ";
  cout<<endl;
  Polynomial fourthPolynomial;
  fourthPolynomial=firstPolynomial-secondPolynomial;
  fourthPolynomial.display();
  return 0;
}
