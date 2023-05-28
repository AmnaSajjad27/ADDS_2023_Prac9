#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <map>
#include <vector>

#include "Document.h"
#include "Patron.h"

class DocumentManager
{
    public:
    void addDocument(string name, int id, int licsense_limit);
    void addPatron(int patronID);
    // returns docid if name is in the document collection or 0 if the name is not in the collection
    int search(string name);
    // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

    DocumentManager();
    ~DocumentManager();

    private:
    // Map of document objects
    std::map<std::string, Document*> name_document;
    // Map of Patron ID's
    std::map<int> Patrons*> patrons;
    // Map of document ID's 
    std::map<int, Document*> document_ID;
    
};

#endif