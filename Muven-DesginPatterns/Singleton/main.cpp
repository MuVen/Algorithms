#include <iostream>

using namespace std;

/*
    Make the class (singleton) responsible for its own global pointer
    and "initialization on first use" (by using a private static pointer
    and a public static accessor method).

    The client uses only the public accessor method.(getInstance)
*/

class singleton{
    int value;
    static singleton* instance_ptr;
public:
    singleton(){
        value = 0;
    }

    void setValue(int val){
        value = val;
    }

    int getValue(){
        return value;
    }

    static singleton* getInstance(){
        if(!instance_ptr)
            instance_ptr = new singleton();
        return instance_ptr;
    }
};

singleton* singleton::instance_ptr = 0; // global pointer.

int main()
{
    cout<<"Value before setting is : "<<singleton::getInstance()->getValue()<<endl;
    singleton::getInstance()->setValue(10);
    cout<<"Value after setting is : "<<singleton::getInstance()->getValue()<<endl;
    return 0;
}
