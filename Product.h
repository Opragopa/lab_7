#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include"MyString.h"

class Product
{
public:
	Product();//����������� ��� ����������
	Product(const MyString& productName, const MyString& marketName, const float& productCost);//����������� � �����������
	Product(const Product& other);//������������ �����������
	~Product();//����������
	bool operator==(const Product& firstVal) const;// ���������� ������ �� �������� ���������� ��� ����� ������
	friend bool operator!=(const Product& secondVal, const Product& firstVal);//���������� ������ �� �������� ���������� ����� ������������� �������
	bool operator>(const Product& firstVal) const;//���������� ������ �� ���������� ��������� ��� ����� ������
	bool operator<=(const Product& firstVal) const;
	Product& operator++();//���������� ����������� ���������� ��� ����� ������
	friend Product operator++(Product& payment, int); //���������� ������������ ���������� ����� ������������� �������
	friend std::istream& operator>>(std::istream& is, Product& payment); // ���������� ���������� >> ����� ������������� �������
	friend std::ostream& operator<<(std::ostream& os, const Product& payment); // ���������� ���������� << ����� ������������� �������
	bool operator<(Product& value);
	MyString getProductName() const;
	MyString getMarketName() const;
	float getProductCost() const;
	size_t getProductNameLength();
	size_t getMarketNameLength();
private:
	float productCost_; // ���� ������
	MyString productName_; // ��� ������
	MyString marketName_; // �������� �������� � �������
};
#endif