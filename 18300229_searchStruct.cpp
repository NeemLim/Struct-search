// 18300229_SearchStruct - P2.1 Funcion de busqueda para estructura
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Node
{
public:
	Node() //Node class constructor
	{
		link = nullptr;
	}
	void* data = 0;
	Node* link;
	//Node() :link(nullptr) {}; | compact constructor
};

class List
{
	Node* beginning;
public:

	int elementCount = 0;

	List()
	{
		beginning = nullptr;
	}

	void addData(void* data)
	{
		elementCount++;
		Node* cursor;
		Node* NEW = new Node();
		NEW->data = data;

		if (beginning == nullptr)
			beginning = NEW;
		else
		{
			cursor = beginning;
			while (cursor->link != nullptr)
				cursor = cursor->link;
			cursor->link = NEW;
		}
	}

	void* findObject(void* value, int (*criteria)(void* value1, void* value2))
	{
		Node* cursor = beginning;
		while (cursor)
		{
			if (criteria(value, cursor->data))
			{
				return cursor->data;
			}
			cursor = cursor->link;
		}
		return nullptr;
	}
};

struct Coordinate
{
public:
	int x, y;
	Coordinate()
	{
		x = 0;
		y = 0;
	}
	Coordinate(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int criteriaCoordinate(void* value1, void* value2)
{
	int d1;
	Coordinate d2;

	d1 = *((int*)value1);

	d2 = *((Coordinate*)value2);

	if (d1 == d2.x) //Evaluates value equality between value in x and search input;
	{
		return 1;
	}
	return 0;
}

void convertResultC(void* rawData) //Casts void* to Coordinate type.
{
	if (rawData == nullptr)
		cout << "Value of X not present in the structure ";
	else
	{
		Coordinate convertData;
		convertData = *(Coordinate*)rawData;
		cout << ">Value of Y = " << convertData.y; //Pene + bola
	}
}

int main()
{
	List listStruct; //Instantiates structure.
	do
	{
		system("cls");
		char choice = 0;
		int dataValue = 0;
		Coordinate* inputCoord = new Coordinate;
		void* result;
		cout << "========Strucuture searching algorithm=========" << endl;

		do //Loop to choose an operation.
		{
			cout << endl << "Select the activity" << endl;
			cout << "[1] Create and fill structures." << endl;
			cout << "[2] Find Y value in structures." << endl;
			cout << "[3] Exit program." << endl;
			cout << ">Answer: "; choice = _getch();
			system("cls");
		} while (choice < 49 or choice > 51); //ASCII from 1 to 3.

		switch (choice)
		{ //Alternates between options.
		case '1':
			cout << endl << "*** Press <Left Control Key> on your last the data input to finish filling. ***" << endl;
			cout << "*** Data input will automatically stop after 100 elements." << endl << endl;
			cout << "Fill in the structures: " << endl;

			for (int i = 0; (GetAsyncKeyState(VK_LCONTROL)) == false and i < 100; i++)  //Fills the an aux strucutre using pointers;
			{
				if ((GetAsyncKeyState(VK_LCONTROL)) == false)
				{
					inputCoord = new Coordinate; //Gives inputCoord a new memory address;
					cout << endl;
					cout << "Struct #" << listStruct.elementCount << endl;
					cout << "Value in X: "; cin >> inputCoord->x;
					cout << "Value in Y: "; cin >> inputCoord->y;
					listStruct.addData(inputCoord);
				}
				GetAsyncKeyState; //Gets the current pressed key from the user.
			}
			break;

		case '2': //Finds and converts result.
			cout << "Input the value of X to get the value of Y." << endl;
			cout << "-Value of X = ";  cin >> dataValue;
			result = listStruct.findObject(&dataValue, criteriaCoordinate);
			convertResultC(result);
			break;

		case '3': //Exits program.
			cout << endl << endl << "\nThank you for using this program.";
			cout << endl;
			return 0;
			break;
		}
		cout << endl << endl;
		system("pause");
	} while (1);
}