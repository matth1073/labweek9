#include "LibraryBook.h"



LibraryBook::LibraryBook()
{
	this->checkedOutStatus = false; 
}

LibraryBook::LibraryBook(string title, string author, string ISBN)
{
	this->title = title; 
	this->author = author; 
	this->ISBN = ISBN; 
	this->checkedOutStatus = false; 
}

string LibraryBook::getISBN() {
	return ISBN; 
}

LibraryBook::~LibraryBook()
{
}
