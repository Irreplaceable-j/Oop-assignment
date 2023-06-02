#include"Sale.h"

Sale::Sale()
{
	Price = 0.0;
}
Sale::Sale(double ThePrice)
{
	Price = ThePrice;
}
Sale::~Sale() {}

double Sale::GetPrice() 
{
	return Price;
}
double Sale::Bill()
{
	return Price;
}
double Sale::Savings(Sale& Other)  // 해당 객체의 price값이 얼마나 싼지 계산
{
	return Other.GetPrice() - Price;
}
bool Sale::operator < (Sale& Other)
{
	return Price < Other.GetPrice();
}


DiscountSale::DiscountSale() : Sale()  // Sale 클래스도 같이 초기화
{
	Discount = 0.0;
}
DiscountSale::DiscountSale(double ThePrice, double theDiscount) : Sale(ThePrice)
{
	Discount = theDiscount;
}
DiscountSale::~DiscountSale() {}

double DiscountSale::GetDiscount()
{
	return Discount;
}
void DiscountSale::SetDiscount(double theDiscount)
{
	Discount = theDiscount;
}
double DiscountSale::Bill()
{
	double Bill_price = GetPrice() - (GetPrice() * Discount / 100);  // 할인된 가격 저장
	return Bill_price;
}

double DiscountSale::Savings(DiscountSale& Other)  // 할인된 가격 비교
{
	return Other.Bill() - Bill();
}