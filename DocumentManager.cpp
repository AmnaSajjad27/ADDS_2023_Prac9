#include "Document.h"
#include "Patron.h"
#include "DocumentManager.h"

using namespace std;

// constructor

DocumentManager::DocumentManager(){};

// destructor 

DocumentManager::~DocumentManager(){};

// Methods 
void DocumentManager::addDocument(string name, int id, int license_limit)
{
    Document* document = new Document(name, id, license_limit);
    name_document[name] = document;
    document_ID[id] = document;
}

void Document_Manager::addPatron(int PatronID)
{
    Patron* patron = new Patron(int patronID);
    patron[patronID] = patron;
}

int DocumentManager::search(string name)
{
    if (document_name.find(name) == document_name.end())
    {
        return 0;
    }
    return document_name[name]->getID();
}

bool DocumentManager::borrowDocument(int docid, int patronID)
{
    bool patron_limit;

    if (document_ID.find(docid) == document_if.end() || patrons.find(patronID) == patrons.end())
    {
        return false;
    }
    
    Document* document = document_ID[docid];
    Patron* patron = patrons[patronID];

    bool Borrow = document->borrow();

    if(Borrow){
        patron_limit = patron->addDoc(document);
    }
    return (Borrow & patron_limit);
}

void DocumentManager::returnDocument(int docid, int patronID){
    Patron* patron = patrons[patronID];
    patron->removeDoc();    
}