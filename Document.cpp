#include "Document.h"

using namespace std;

Document::Document()
{
    name = "";
    ID = 0;
    license_limit = 0;
    copies_left = 0;
}

Document::Document(string _name, int _ID, int _licence_limit)
{
    name = _name;
    ID = _ID;
    license_limit = _licence_limit;
    copies_left = _licence_limit;
}

Document::~Document()
{

}

std::string Document::getName()
{
    return name;
}

int Document::getID()
{
    return ID;
}

int Document::getLicence_limit()
{
    return license_limit;
}

// this function reduced the index of the borrowed variable every time its run and returns true if its is above 0 and if its below zero the false
bool Document::borrow()
{
    // decremnet as each copy is borrowed
    copies_left -= 1;
    // reset if less than 0, doesnt let anyone borrow another copy
    if(copies_left < 0)
    {
        copies_left = 0;
        return false;
    }
    return true;
}

bool Document::Return()
{
    // incremnet the number avialble to borrow 
    copies_left += 1;

    if(copies_left > license_limit)
    {
        copies_left = license_limit;
        // made change here 
        return true;
    }
    return false;
}

