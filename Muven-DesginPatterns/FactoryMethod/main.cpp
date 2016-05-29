#include <iostream>

using namespace std;
/*
    Factory Design Pattern.

    Factory method returns the class based on the choice you pass to the factory.
    Factory method is a static method which asks for choice.
*/

class Animal{
public:
    static Animal* createAnimal(int choice);
    virtual void speak() = 0;
};

class Lion : public Animal{
public:
    void speak(){
        cout<<"LION SPEAK : ROAR ROAR"<<endl;
    }
};

class Dog : public Animal{
public:
    void speak(){
        cout<<"DOG SPEAK : BOW BOW"<<endl;
    }
};

class Cat: public Animal{
 public:
     void speak(){
         cout<<"CAT SPEAK : MEOW MEOW"<<endl;
     }
};

Animal* Animal::createAnimal(int choice){

    switch(choice){
        case 1: return new Lion();
        case 2: return new Dog();
        case 3: return new Cat();
    }

}

int main()
{
    int i;
    Animal* ani[3];

    for(i = 0; i <3; i++)
        ani[i] = Animal::createAnimal(i+1);

    for(i = 0; i < 3; i++)
        if(ani[i])
            ani[i]->speak();

    for(i = 0; i < 3; i++)
        delete ani[i];

    return 0;
}
