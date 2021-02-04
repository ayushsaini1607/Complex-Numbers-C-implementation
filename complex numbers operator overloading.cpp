#include<iostream>
#include<math.h>
#include<process.h>

using namespace std;

class Complex{
     float real;
     float img;
    public:
      Complex()
      {
          real=0.0;
          img=0.0;
      }
      Complex(float r,float i)
      {
          real=r;
          img=i;
      }
      friend ostream& operator <<(ostream &,Complex &);
      friend istream& operator >>(istream &,Complex &);
      Complex operator + (Complex&);   
      Complex operator - (Complex&);
      Complex operator * (Complex&);
      Complex operator / (Complex&);
      Complex operator ++ ();
      Complex operator ++(int);
      Complex operator -- ();
      Complex operator --(int);
      bool operator == (Complex&);
      bool operator > (Complex&);
      bool operator < (Complex&);
      ~Complex(){}     
};


int main()
{
    Complex C1,C2,C3,temp;
    int choice;
    cout<<"\nEnter first complex number: \n";
    cin>>C1;
    cout<<"\nEnter second real number :\n";
    cin>>C2;
    while(true)
     {
        cout<<"\n****MENU****";
        cout<<"\n1.Sum";
        cout<<"\n2.Difference";
        cout<<"\n3.Product";
        cout<<"\n4.Division";
        cout<<"\n5.Pre-Increment operator";
        cout<<"\n6.Post increment operator";
        cout<<"\n7.Pre Decrement operator";
        cout<<"\n8.Post Decrement operator";
        cout<<"\n9.Equality check";
        cout<<"\n10.Greater than";
        cout<<"\n11.Less than";
        cout<<"\n12.Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
          {
              case 1:
                 C3=C1+C2;
                 cout<<"\nComplex number 1: "<<C1;
                 cout<<"\nComplex number 2: "<<C2;
                 cout<<"\nSum : "<<C3;
                 break;
            
              case 2:
                 C3=C1-C2;
                 cout<<"\nComplex number 1: "<<C1;
                 cout<<"\nComplex number 2: "<<C2;
                 cout<<"\nDifference : "<<C3;
                 break;
               
              case 3:
                 C3=C1*C2;
                 cout<<"\nComplex number 1: "<<C1;
                 cout<<"\nComplex number 2: "<<C2;
                 cout<<"\nProduct : "<<C3;
                 break;
            
              case 4:
                  C3=C1/C2;
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  cout<<"\nDivision : "<<C3;
                  break;
            
              case 5:
                  cout<<"\n\nBefore increment : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;;
                  ++C1;
                  ++C2;
                  cout<<"\n\nAfter increment : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  break;
                
              case 6:
                  cout<<"\nExecuting:temp=C1++, and C2++, then display C1, C2,temp";
                  cout<<"\n\nBefore increment : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;;
                  temp=C1++;
                  C2++;
                  cout<<"\n\nAfter increment : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\ntemp : "<<temp;
                  cout<<"\nComplex number 2: "<<C2;
                  break;
                  
              case 7:
                  cout<<"\n\nBefore decrement : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  --C1;
                  --C2;
                  cout<<"\n\nAfter decrement : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  break;

               case 8:
                  cout<<"\nExecuting:temp=C1-- and C2--, then display C1, C2,temp";
                  cout<<"\n\nBefore increment : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;;
                  temp=C1--;
                  C2--;
                  cout<<"\n\nAfter increment : ";
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\ntemp : "<<temp;
                  cout<<"\nComplex number 2: "<<C2;
                  break;

              case 9:
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  if(C1==C2)
                    cout<<"\nNumbers are equal";
                  else
                     cout<<"\nNumbers are not equal";  
                  break;
              
              case 10:
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  if(C1>C2)
                     cout<<"\nAbsolute value of number 1 is greater";
                  else
                     cout<<"\nAbsolute value of number 2 is greater or both are equal";
                  break;
              case 11:
                  cout<<"\nComplex number 1: "<<C1;
                  cout<<"\nComplex number 2: "<<C2;
                  if(C1<C2)
                     cout<<"\nAbsolute value of number 1 is less than number 2";
                  else
                     cout<<"\nAbsolute value of number 2 is less or both are equal";
                  break;  
            
              case 12:
                   cout<<"\nExiting...";
                   exit(0);
          }
    }
    return 0; 
}

istream& operator >>(istream &input,Complex &c)
{
    cout<<"\nEnter real part : ";
    input>>c.real;
    cout<<"\nEnter imaginary part : ";
    input>>c.img;
    return input;
}

ostream& operator <<(ostream &output,Complex &c)
{
    output<<c.real<<" + ("<<c.img<<"i)";
    return output;
}

Complex Complex::operator +(Complex &c)
{
  return Complex(real+c.real,img+c.img);
}

Complex Complex::operator - (Complex &C)
{
    return Complex(real-C.real,img-C.img);
}

Complex Complex::operator * (Complex &C)
{
   return Complex((real * C.real) - (img * C.img) , (real * C.img) + (real * C.img));

}

Complex Complex::operator / (Complex &C)
{ 
    Complex temp;
    float mod;
    mod = pow(C.real,2)  + pow(C.img,2);
    if(!mod)
        cout<<"\nCannot perform divison for this input";
    temp.real=((real * C.real) + (img * C.img))/mod;
    temp.img=((img * C.real) - (real * C.img))/mod;
    return temp;
} 

Complex Complex::operator ++ ()
{
    return Complex(++real,++img);
}

Complex Complex::operator ++(int)
{
    return Complex(real++,img++);
}

Complex Complex::operator -- ()
{
    return Complex(--real,--img);
}

Complex Complex::operator --(int)
{
    return Complex(real--,img--);
}

bool Complex::operator == (Complex &C)
{
    if((C.real==real) && (C.img==img))
       return true;
    else
       return false;   
}

bool Complex::operator > (Complex &C)
{
     float mod1,mod2;
     mod2 = pow(C.real,2)  + pow(C.img,2);
     mod1 = pow(real,2)  + pow(img,2);   
     if(mod1>mod2)
        return true;
     else
        return false;
}

bool Complex::operator < (Complex &C)
{
     float mod1,mod2;
     mod1 = pow(real,2)  + pow(img,2);
     mod2 = pow(C.real,2)  + pow(C.img,2);
     if(mod1<mod2)
       return true;
     else
       return false;
}