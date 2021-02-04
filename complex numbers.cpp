#include<iostream>
#include<math.h>

class Complex{
     float real;
     float img;
    public:
      Complex()
      {
          real=0.0;
          img=0.0;
      }
      void input();
      void display();
      void add(Complex,Complex);
      void subtract(Complex,Complex);
      void multiply(Complex,Complex);
      int divide(Complex,Complex);    //returns -1 if divison is not possible
      ~Complex(){}     
};

using namespace std;

int main()
{
    Complex C1,C2,C3;
    cout<<"\nEnter first complex number: \n";
    C1.input();
    cout<<"\nEnter second real number :\n";
    C2.input();
    C3.add(C1,C2);
    cout<<"\nSum : ";
    C3.display();
    C3.subtract(C1,C2);
    cout<<"\nDifference : ";
    C3.display();
    C3.multiply(C1,C2);
    cout<<"\nProduct : ";
    C3.display();
    if(C3.divide(C1,C2)!=-1)
      {
        cout<<"\nDivision : ";
        C3.display();
      }
    return 0;
}

void Complex::input()
{
    cout<<"\nEnter real part : ";
    cin>>real;
    cout<<"\nEnter imaginary part : ";
    cin>>img;
}

void Complex::display()
{
    cout<<"\n"<<real<<" + ("<<img<<"i)";
}

void Complex::add(Complex C1,Complex C2)
{
      real=C1.real+C2.real;
      img=C1.img+C2.img;
}

void Complex::subtract(Complex C1,Complex C2)
{
    real=C1.real-C2.real;
    img=C1.img-C2.img;
}

void Complex::multiply(Complex C1,Complex C2)
{
   real=(C1.real * C2.real) - (C1.img * C2.img);
   img=(C1.real * C2.img) + (C2.real * C1.img);
}

int Complex::divide(Complex C1,Complex C2)
{ 
    float mod;
    mod = pow(C2.real,2)  + pow(C2.img,2);
    if(!mod)
      {
          cout<<"\nCannot perform divison for this input";
          return -1;
      }
    real=((C1.real * C2.real) + (C1.img * C2.img))/mod;
    img=((C1.img * C2.real) - (C1.real * C2.img))/mod;
}