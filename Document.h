#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document
{
    private:
    std::string name;
    int ID;
    int license_limit;
    // copies left to be borrowed 
    int copies_left;

    public:
    // constructors 
    Document();
    ~Document();
    Document(std::string _name, int _id, int _license_limit);

    std::string getName();
    int getID();
    int getLicence_limit();
    bool borrow();
    bool Return();
};

#endif