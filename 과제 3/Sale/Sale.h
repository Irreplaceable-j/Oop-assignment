#pragma once

class Sale
{
private:
	double Price;

public:
	Sale();
	Sale(double ThePrice);
	~Sale();

	double GetPrice() ;
	virtual double Bill();
	double Savings(Sale& Other);
	bool operator < (Sale& Qther);

};

class DiscountSale : public Sale
{
private:
	double Discount;
public:
	DiscountSale();
	DiscountSale(double ThePrice, double theDiscount);
	~DiscountSale();
	double GetDiscount();
	void SetDiscount(double theDiscount);
	double Bill() override; 
	double Savings(DiscountSale& Other); 
};