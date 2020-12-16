#include<iostream>
#include<fstream>
#include <iomanip>
#include"MyString.h"
#include"Product.h"
#include"MyArray.h"

void output(Array<Product>& products);

int findMax(Array<Product>& value);

template <class T>
void sort(Array <T>& array);

int main()
{
	setlocale(LC_ALL, "Rus");
	MyString fileName;
	std::ifstream inProgram;
	try
	{
		std::cout << "Please, entry name of your file (.txt format): ";
		std::cin >> fileName;
		inProgram.open(fileName.getStr());
		if (!inProgram.is_open())
		{
			throw "Error! File does not exist!";
		}
		if (inProgram.get() == EOF)
		{
			throw "Error! File is empty!";
		}
		inProgram.unget();
		Array<Product> products;
		while (inProgram.peek() != EOF)
		{
			Product inputStudent;
			char symbol = inProgram.get();
			if (symbol == ' ' || symbol == '\n' || symbol == '\t')
			{
				symbol = inProgram.get();
			}
			inProgram.unget();
			inProgram >> inputStudent;
			products.push_back(inputStudent);
		}
		std::cout << "Программа успешно завершилась! Создана таблица, помещенная в файл вывода\n";
		output(products);
		inProgram.close();
	}
	catch (const char* exception)
	{
		inProgram.close();
		std::cerr << exception;
	}
}

template <class T>
void sort(Array <T>& array)
{
	int length = array.getSize();

	for (int i = 0; i < length - 1; ++i)
	{
		int min = i;

		for (int curr = i + 1; curr < length; ++curr)
		{
			if (array[curr] < array[min])
				min = curr;
		}
		std::swap(array[i], array[min]);
	}
}

int findMax(Array<Product>& value)
{
	Product temp;
	int maxIndex = 0;
	for (int i = 0; i < value.getSize(); ++i)
	{
		if (temp < value[i])
		{
			temp = value[i];
			maxIndex = i;
		}
	}
	return maxIndex + 1;
}

void output(Array<Product>& products)
{
	sort(products);
	MyString border = "";
	MyString marketHeader = "Название магазина";
	MyString productHeader = "Название продукта";
	MyString costHeader = "Цена";
	MyString index = "Индекс";
	size_t marketHeaderLength = marketHeader.length();
	size_t productHeaderLength = productHeader.length();
	size_t costHeaderLength = costHeader.length();
	size_t maxLengthMarketColumn = 0;
	size_t maxLengthProductColumn = 0;
	size_t maxLengthCostColumn = 0;
	std::ofstream out;
	out.open("output.txt");
	for (size_t i = 0; i < products.getSize(); ++i)
	{
		maxLengthMarketColumn = (products[i].getMarketNameLength() > maxLengthMarketColumn) ? products[i].getMarketNameLength() : maxLengthMarketColumn;
		maxLengthProductColumn = (products[i].getProductNameLength() > maxLengthProductColumn) ? products[i].getProductNameLength() : maxLengthProductColumn;
	}
	maxLengthMarketColumn = (marketHeaderLength > maxLengthMarketColumn) ? marketHeaderLength : maxLengthMarketColumn;
	maxLengthProductColumn = (productHeaderLength > maxLengthProductColumn) ? productHeaderLength : maxLengthProductColumn;
	maxLengthCostColumn = (costHeaderLength > maxLengthCostColumn) ? costHeaderLength : maxLengthCostColumn;
	size_t linesLength = 16 + maxLengthMarketColumn + maxLengthProductColumn - 2 + index.length();
	for (size_t i = 0; i < linesLength; ++i)
	{
		border += "-";
	}
	out << '\n';

	size_t setwMarketName = maxLengthMarketColumn + 1;
	size_t setwProductName = maxLengthProductColumn + 1;
	size_t setwCost = maxLengthCostColumn + 1;

	out << border << '\n' << '|' << std::setw(index.length()) << index << '|' << std::setw(setwMarketName) << marketHeader << std::setw(2) << '|' << std::setw(setwProductName) << productHeader << std::setw(2) << '|'
		<< std::setw(setwCost) << costHeader << std::setw(2) << '|' << '\n' << border << '\n';

	//

	for (int i = 0; i < products.getSize(); ++i)
	{
		out << '|' << std::setw(index.length()) << i << '|' << std::setw(setwMarketName) << products[i].getMarketName() << std::setw(2) <<
			   '|' << std::setw(setwProductName) << products[i].getProductName() << std::setw(2) <<
			   '|' << std::setw(setwCost) << products[i].getProductCost() << std::setw(2) << '|' << '\n' << border << '\n';
	}

	out << '\n' << "Индекс самого дорогого товара - " << findMax(products);
}