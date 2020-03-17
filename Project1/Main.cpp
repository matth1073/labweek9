#include "LibraryBook.h";
#include <vector>
#include <fstream>
#include <iostream>

void print(vector<LibraryBook> books); 

int main() {
	ifstream booksFin("books.txt");
	ifstream isbnFin("isbns.txt");
	ofstream fout("out.txt");
	vector<LibraryBook> books;
	string title; 
	string author; 
	string ISBN; 

	while (!booksFin.eof()) {
		getline(booksFin, title);
		getline(booksFin, author);
		getline(booksFin, ISBN);
		LibraryBook book(title, author, ISBN); 
		books.push_back(book); 
	}

	while (!isbnFin.eof()) {
		isbnFin >> ISBN; 
		for (auto&& i : books) {
			if (i.getISBN() == ISBN) {
				if (!i.isCheckedOut()) {
					i.checkOut();
				}
				else {
					i.checkIn(); 
				}
				break; 
			}
		}
	}
	fout << "Books checked out" << endl; 
	fout << "==================================" << endl; 
	fout << "Title\tAuthor\tISBN" << endl << endl;
	for (auto i : books) {
		if (i.isCheckedOut()) {
			fout << i.getTitle() << "\t"; 
			fout << i.getAuthor() << "\t";
			fout << i.getISBN() << endl << endl; 
		}

	}

	booksFin.close();
	isbnFin.close(); 
	fout.close();
}

void print(vector<LibraryBook> books)
{
	for (auto i : books) {
		cout << i.getTitle() << endl; 
		cout << i.getAuthor() << endl;
		cout << i.getISBN() << endl;
		cout << i.isCheckedOut() << endl; 
		cout << endl; 

	}
}

