#include <iostream>
#include <string>
#include <stdlib.h>
/*
  Encontre este ejemplo en internet
  sin virtual
       A
      / \
    B     C
     \   /
       D
    CON virtual
    A    A
    |    |
    B    C
     \  /
      D
*/

using namespace std;
class Animal{
  protected://protected para que los hijos hereden las funciones
  string tipo;
  int edad;
  public:
    Animal(const string & _tipo, const int _edad):tipo(_tipo) , edad(_edad){}
  const string getDesc () const
  {
   return tipo + " con edad: " + to_string(edad);
  }
 const string & getTipo () const 
  { 
   return tipo ;
  }
 const int getEdad () const 
  { 
    return edad ;
  }
};

class Gallina : virtual public Animal{//virtual es la solucion al problema ya que al usar virtual es como si la herencia se hiciera en un solo camino
  protected:
  int patas;
  public:
    Gallina( const string & _tipo , const int _edad , const int _patas ) : Animal ( _tipo , _edad ), patas ( _patas ) {}
    const int getPatas() const
    {
      return patas;
    }
};

class Perro : virtual public Animal{
  protected://uso protected ya que me permite que las hijas de mi clase hija hereden las caracteírsticas iguales a mi
  bool cola;
  public:
    Perro( const string & _tipo , const int _edad , const bool _cola ) : Animal ( _tipo , _edad ), cola ( _cola ) {}
    const bool getCola() const
    {
      return cola ;
    }
};

class PerroGallina : virtual public Perro , virtual public Gallina{
  float peso;
  public:
    PerroGallina( const string & _tipo , const int _edad , const bool _cola , const int _patas , const float _peso) : Animal (_tipo , _edad),  Perro ( _tipo , _edad , _cola ), Gallina ( _tipo , _edad , _patas ), peso ( _peso){}
    const bool getPeso() const
    {
      return peso;
    }
    virtual const string getDesc() const
    {
      return tipo + " con edad: " + to_string(edad);
    }
    const string getTipo() const
    {
      return tipo;
    }
    const int getPatas() const
    {
      return edad;
    }
    const bool getCola() const
    {
      return cola;
    }
    const int getEdad() const
    {
      return edad;
    }
};

int main(){
  PerroGallina dogi("alado" , 45 , 1 , (rand() % 4) + 2 , 23.5);
  cout << dogi.getTipo() << endl;
  cout << dogi.getEdad() << endl;
  cout << dogi.getPatas() << endl;
  cout << dogi.getCola() << endl;
  cout << dogi.getPeso() << endl;
  cout << dogi.getDesc() << endl;
  
  
  return 0;
}