#include "Patron.h"

// default constructor 
Patron::Patron()
{
    ID = 0;
    Borrowed = false;
    document = new Document();
}
// constructor 
Patron::Patron(int _ID)
{
    ID = _ID;
    Borrowed = false;
    document = new Document();
}
// destructor 
Patron::~Patron()
{

}

// does the patron already have a document borrowed 
bool Patron::addDoc(Document* _doc)
{
    if(!Borrowed)
    {
        document = _doc;
        // set the method to true to reflect that there is a object borrowed 
        Borrowed = true;
        return true;
    }
    // else return false 
    return false;
}

Document* Patron::getDoc()
{
    return document;
}

void Patron::removeDoc()
{
    // set borrowed to false 
    Borrowed = false;
    document = new Document();
}

int Patron::getID()
{
    return ID;
}

