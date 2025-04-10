#include <iostream>

using namespace std;
class Complex{
  
  double real, img;
  
  public:
  Complex(double r, double i){
      real=r;
      img=i;
  }
  
  double getReal() const {return real;}
  double getImg() const {return img;}
  
  friend ostream& operator<<(ostream& out,Complex x){
      if(x.real==0 && x.img==0){
        out<<"0";
        return out;
      }
      
      if(x.real!=0) out<< x.real;
      
      if(x.img==0)
        return out;
        
      if(x.real!=0 && x.img>0) out<<"+";
      if(x.img==-1) out<<"-";
      
      if(x.img!=0 && x.img!=1 && x.img!=-1) out<<x.img;
      if(x.img!=0) out<<"i";
    
    return out;
  }
  
  Complex operator+(Complex x) const {
      return Complex(real+x.real, img+x.img);
  }
  
  Complex operator-(Complex x) const {
      return Complex(real-x.real, img-x.img);
  }
    
  Complex operator*(Complex x) const {
      return Complex(real*x.real - img*x.img, real*x.img + img*x.real);
  }
};