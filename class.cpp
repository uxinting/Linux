#include <iostream>
using namespace std;

class Sales_item {
	public:
		// operations on Sales_item objects
		double avg_price() const;
		bool same_isbn(const Sales_item &rhs) const	{ 
			return isbn == rhs.isbn; }
		// default constructor needed to initialize members of built-in type
		Sales_item() : units_sold(0), revenue(0.0) {
			cout << "constructor" << endl; }
		Sales_item(Sales_item& item);
		void pIsbn() const;
		void setIsbn(string isbn);
		int getP() const;
	private:
		std::string isbn;
		unsigned units_sold;
		double revenue;
		static int price;
};

Sales_item::Sales_item(Sales_item& item) {
	isbn = item.isbn;
	cout << "copy constructor" << endl;
}

double Sales_item::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int Sales_item::getP() const {
	return price;
}

void Sales_item::pIsbn() const {
	cout << isbn << endl;
}

void Sales_item::setIsbn(string isbn) {
	this->isbn = isbn;
}

int Sales_item::price = 12;

int main() {
	Sales_item item;
	item.setIsbn("wuxinting");
	item.pIsbn();
	cout << item.getP() << endl;
	return 0;
}
