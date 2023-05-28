#ifndef PATRON_H
#define PATRON_H

#include "Document.h"

class Patron
{
    private:
    int ID;
    Document* document;
    bool Borrowed;

    public:
    // constructor 
    Patron();
    Patron(int _ID);
    // destrutcor 
    ~Patron();

    // Methods (get methods)
    bool addDoc(Document* _doc);
    Document* getDoc();
    void removeDoc();
    int getID();
};

#endif