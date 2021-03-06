/*********************************************************************
	Lottery  Winners

	A lottery  ticket buyer purchases  ten tickets a week, always playing the same ten five-digit 
	�lucky� combinations. Write  a program that  initializes  an array  with  these numbers  and then  
	lets  the  player  enter  this  week�s  winning  five-digit  number.   The  program should perform  
	a linear search through the list of the player�s numbers  and report  whether  or not one of the 
	tickets is a winner  this week. Here are the numbers:

	13579         26791         26792         33445         55555
	62483         77777         79422         85647         93121



	Lottery  Winners  Modification

	Modify  the  program you  wrote  for  Programming Challenge  2  (Lottery  Winners)  so  it
	performs  a binary search instead of a linear search.
*********************************************************************/
#include <iostream>
using namespace std;

void linearSearch(int dataArray[], int size, int valueArray[])
{
	bool winning = false;
	int counter = 0;

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (valueArray[x] == dataArray[y])
			{
				winning = true;
				counter++;
			}
		}
	}

	if (winning)
	{
		cout << "You have " << counter << " winning numbers for this week" << endl;
	}
	else
	{
		cout << "You do not have a winning number for this week" << endl;
	}
}




void binarySearch(int array[], int size, int value[])
{
	bool found;
	int index, count = 0;
	int mid, last, first;

	for (int x = 0; x < size; x++)
	{
		last = size - 1;
		first = 0;
		found = false;

		while (!found && first <= last)
		{
			mid = (last + first) / 2;

			if (array[mid] == value[x])
			{
				found = true;
				count++;
			}
			else if (array[mid] > value[x])
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		
	}



	if (count)
	{
		cout << "You have " << count << " winning numbers for this week" << endl;
	}
	else
	{
		cout << "You do not have a winning number for this week" << endl;
	}

}


int main()
{
	int lucky[10] = {	13579, 26791, 26792, 33445, 55555,
						62483, 77777, 79422, 85647, 93121 };

	int player[10];



	for (int x = 0; x < 10; x++)
	{
		cout << x + 1 << ". Enter a five digit number: ";
		cin >> player[x];
	}

	// Linear Search
	linearSearch(lucky, 10, player);
	
	cout << endl << endl;
	
	// Binary Search
	binarySearch(lucky, 10, player);


	return 0;
}