#include<iostream>
#include <iomanip>
#include"Product.h"
#include"MyString.h"
#include"MyException.h"


Product::Product() 
{
    size_t productCost_ = 0;
    MyString productName_ = MyString();
    MyString marketName_ = MyString();
}

Product::Product(const MyString& productName, const MyString& marketName, const float& productCost)
{
    productName_ = productName;
    marketName_ = marketName;
    productCost_ = productCost;
}

Product::Product(const Product& other)
{
    this->productCost_ = other.productCost_;
    this->marketName_ = other.marketName_;
    this->productName_ = other.productName_;
}

Product::~Product() = default;

bool Product::operator==(const Product& firstVal) const
{
    if (this->productCost_ == firstVal.productCost_ 
        && this->productName_ == firstVal.productName_
        && this->marketName_ == firstVal.marketName_)
        return true;
    return false;
}

bool operator!=(const Product& secondVal, const Product& firstVal)
{
    return !(firstVal == secondVal);
}

Product& Product::operator++()
{
    this->productCost_++;
    return *this;
}

Product operator++(Product& payment, int)
{
    Product temp(payment);
    ++payment;
    return temp;
}

std::istream& operator>>(std::istream& is, Product& payment)
{
    is >> payment.marketName_;
    is >> payment.productName_;
    is >> payment.productCost_;
    if ((!is) && (payment.productCost_ < 0)) throw "Cost error\n";
    return is;
}

std::ostream& operator<<(std::ostream& os, const Product& payment) // TODO : исп. вывод на экран
{
    os  /*<< "productCost_: "*/ << payment.productCost_ << '\t'
        /*<< " marketName_: "*/ << payment.marketName_ << '\t'
        /*<< " productName_: "*/ << payment.productName_;
    return os;
}

bool Product::operator<(Product& value)
{
    return (this->productCost_ < value.productCost_);
}

bool  Product::operator>(const Product& firstVal) const
{
    return (this->productCost_ > firstVal.productCost_);
}

bool Product::operator<=(const Product& firstVal) const
{
    return (this->productCost_ <= firstVal.productCost_);
}

MyString Product::getProductName() const
{
    return productName_;
}

MyString Product::getMarketName() const
{
    return marketName_;
}

float Product::getProductCost() const
{
    return productCost_;
}

size_t Product::getProductNameLength()
{
    return this->productName_.length();
}

size_t Product::getMarketNameLength()
{
    return this->marketName_.length();
}

//size_t Product::getProductCostLength()
//{
//    size_t test = productCost_.size();
//    return 0;
//}