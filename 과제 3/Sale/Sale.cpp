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
double Sale::Savings(Sale& Other)  // �ش� ��ü�� price���� �󸶳� ���� ���
{
	return Other.GetPrice() - Price;
}
bool Sale::operator < (Sale& Other)
{
	return Price < Other.GetPrice();
}


DiscountSale::DiscountSale() : Sale()  // Sale Ŭ������ ���� �ʱ�ȭ
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
	double Bill_price = GetPrice() - (GetPrice() * Discount / 100);  // ���ε� ���� ����
	return Bill_price;
}

double DiscountSale::Savings(DiscountSale& Other)  // ���ε� ���� ��
{
	return Other.Bill() - Bill();
}