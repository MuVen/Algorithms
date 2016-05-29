#include <iostream>

using namespace std;

class widget {
public:
    virtual void draw() = 0;
};

class linuxButton : public widget {
public:
    void draw(){
        cout<<"Linux Button Draw"<<endl;
    }
};

class linuxCheckBox : public widget {
    void draw(){
        cout<<"Linux CheckBox Draw"<<endl;
    }
};

class windowsButton : public widget {
    void draw(){
        cout<<"Windows Button Draw"<<endl;
    }
};

class windowsCheckBox : public widget {
    void draw(){
        cout<<"Windows CheckBox Draw"<<endl;
    }
};

class Factory {
public:
    virtual widget* createButton() = 0;
    virtual widget* createCheckBox() = 0;
};

class LinuxWidgetFactory : public Factory {
public:
    widget* createButton(){
        return new linuxButton();
    }

    widget* createCheckBox(){
        return new linuxCheckBox();
    }
};

class WindowsWidgetFactory : public Factory {
public:
    widget* createButton(){
        return new windowsButton();
    }

    widget* createCheckBox(){
        return new windowsCheckBox();
    }
};

Factory* fac_ptr = 0;

int main()
{
    #ifdef LINUX

    fac_ptr = new LinuxWidgetFactory();
    fac_ptr->createButton()->draw();
    fac_ptr->createCheckBox()->draw();

    #else

    fac_ptr = new WindowsWidgetFactory();
    fac_ptr->createButton()->draw();
    fac_ptr->createCheckBox()->draw();

    #endif // LINUX
    return 0;
}
