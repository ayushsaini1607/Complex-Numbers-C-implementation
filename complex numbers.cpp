#include<iostream>
#include<math.h>

using namespace std;
class Complex{
     float real;
     float img;
    public:
      Complex()   //default constructor to initialise real and imaginary to 0
      {
          real=0.0;
          img=0.0;
      }

      Complex(float a)        //parametarized constructor to initialize real and imaginary with an equal value
       {
         real=a;
         img=a;
       }
      Complex(float r,float i)     //parametarized constructor to initialize real and imaginary with different values
       {
         real=r;
         img=i;
       }

       Complex(const Complex&C)
        {
          real=C.real;
          img=C.img;
        }

      void display();
      friend Complex add(Complex,Complex);
      ~Complex(){}     
};

using namespace std;

void Complex::display()
{
    cout<<real<<" + ("<<img<<"i)";
}

Complex add(Complex C1,Complex C2)
{
      Complex C;
      C.real=C1.real+C2.real;
      C.img=C1.img+C2.img;
      return C;
}

Complex input()
{
    int opt;
    while(1)
    {
      cout<<"\n\t\t****MENU****"<<endl;
      cout<<"1. Initialise real and imaginary to 0";
      cout<<"\n2. Equal real and imaginary parts";
      cout<<"\n3. Different real and imaginary parts";
      cout<<"\n\nEnter choice: ";
      cin>>opt;
      switch(opt)
      {
        case 1:
          {
            //Complex C  //default constrcutor is called
            return Complex();
          }
        case 2:
          { 
            float r;       
            cout<<"\nEnter value : ";
            cin>>r;
          //Complex C(r);
            //return C;
            return Complex(r);                    //parametarized constructor with single argument is called
          }
        case 3:
          {
            float r,c;
            cout<<"\nEnter real part : ";
            cin>>r;
            cout<<"\nEnter imaginary part : ";
            cin>>c;
            //Complex C(r,c);
            //return C;
            return Complex(r,c);                 //parametarized constructor with two arguments is called
          }
          default:
            cout<<"\nInvalid choice!";

      }
    }
}

int main()
{
    cout<<"\nEnter first complex number : ";
    Complex C1=input();
    cout<<"\nEnter second complex number : ";
    Complex C2=input();
    cout<<"\nPerforming addition : ";
    Complex C3=add(C1,C2);
    Complex T=C3;
    cout<<"\nComplex number 1: ";
    C1.display();
    cout<<"\nComplex number 2: ";
    C2.display();
    cout<<"\nAddition of number 1 and number 2 : ";
    C3.display();
    cout<<"T\n";
    T.display();
    return 0;
}
