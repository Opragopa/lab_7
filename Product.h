#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include"MyString.h"

class Product
{
public:
	Product();//Конструктор без параметров
	Product(const MyString& productName, const MyString& marketName, const float& productCost);//конструктор с параметрами
	Product(const Product& other);//конструкторы копирования
	~Product();//деструктор
	bool operator==(const Product& firstVal) const;// Перегрузка одного из бинарных операторов как метод класса
	friend bool operator!=(const Product& secondVal, const Product& firstVal);//Перегрузка одного из бинарных операторов через дружественную функцию
	bool operator>(const Product& firstVal) const;//Перегрузка одного из операторов отношения как метод класса
	bool operator<=(const Product& firstVal) const;
	Product& operator++();//Перегрузка префиксного инкремента как метод класса
	friend Product operator++(Product& payment, int); //Перегрузка постфиксного инкремента через дружественную функцию
	friend std::istream& operator>>(std::istream& is, Product& payment); // Перегрузка операторов >> через дружественные функции
	friend std::ostream& operator<<(std::ostream& os, const Product& payment); // Перегрузка операторов << через дружественные функции
	bool operator<(Product& value);
	MyString getProductName() const;
	MyString getMarketName() const;
	float getProductCost() const;
	size_t getProductNameLength();
	size_t getMarketNameLength();
private:
	float productCost_; // цена товара
	MyString productName_; // имя товара
	MyString marketName_; // название магазина с товаром
};
#endif