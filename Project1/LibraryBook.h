#pragma once
#include <string>

using namespace std; 

class LibraryBook
{
public:
	LibraryBook();
	LibraryBook(string title, string author, string ISBN);
	string getTitle() { return title; };
	string getAuthor() { return author; };
	string getISBN(); 
	void checkOut() { this->checkedOutStatus = true; };
	void checkIn() { this->checkedOutStatus = false; };
	bool isCheckedOut() { return checkedOutStatus; }; 
	~LibraryBook();

private:
	string title;
	string author; 
	string ISBN; 
	bool checkedOutStatus;
};

