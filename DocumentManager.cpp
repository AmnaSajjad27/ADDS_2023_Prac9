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

void DocumentManager::addPatron(int patronID)
{
    Patron* patron = new Patron(patronID);
    // made changes here
    patrons[patronID] = patron;
}

int DocumentManager::search(string name)
{
    if (name_document.find(name) == name_document.end())
    {
        return 0;
    }
    return name_document[name]->getID();;
}

bool DocumentManager::borrowDocument(int docid, int patronID)
{
    bool patron_limit;

    if (document_ID.find(docid) == document_ID.end() || patrons.find(patronID) == patrons.end())
    {
        return false;
    }
    
    Document* document = document_ID[docid];
    Patron* patron = patrons[patronID];

    bool Borrow = document->borrow();

    if(Borrow)
    {
        patron_limit = patron->addDoc(document);
    }
    return (Borrow & patron_limit);
}

void DocumentManager::returnDocument(int docid, int patronID){
    Patron* patron = patrons[patronID];
    Document* document = document_ID[docid];
    patron->removeDoc();  
    document->Return();  
}