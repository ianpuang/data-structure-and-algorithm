#include <iostream>

using namespace std;

int const size = 20;
int arr[size];
int first=0;
int last=size-1;

void bubbleSort(int arr[],int);
void selectionSort(int arr[]);
void swap(int first,int second);
int minLocation();
void mySelectionSort(int arr[]);
void displayAll();

int main()
{
//populate array
	for(int c=0;c<size;c++)
	{
		arr[c]=rand()%100;
	}
	displayAll();
	mySelectionSort(arr);
	cout << "\n\t Sorted: \n";
	displayAll();
	cout << "\n\t sorted with selection sort: \n";
	selectionSort(arr);
	displayAll();

}

void displayAll()
{
	for(int c=0;c<size;c++)
	{
		cout << arr[c] << " ";
	}
}

void bubbleSort(int arr[])
{
	for(int iteration=1;iteration < size;iteration++)
	{
		for(int index=0;index<size;index++)
		{
			if(arr[index] > arr[index+1]) //if one bigger that another
			{//swap
				int temp=arr[index];
				arr[index]=arr[index+1];
				arr[index+1]=temp;
			}
		}
	}
}

void selectionSort(int arr[])
{
	int minIndex;
	
	for(int loc=0;loc<size-1;loc++)
	{
		minIndex=minLocation();
		swap(loc,minIndex);
	}
}

void swap(int first,int second)
{
	int temp;
	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int minLocation()
{
	int minIndex;
	minIndex=first;
	for(int loc=first+1;loc<=last;loc++)
	{
		minIndex=loc;
	}
	return minIndex;
}

void mySelectionSort(int arr[])
{
	int low;
	
	for(int i=0;i<(size-1);i++)
	{
		low=i; //set first element as lowest element 
		for(int j=i+1; j<size;j++)
		{
			if(arr[j]<arr[low])
			{
				low=j; 
			}
		}
		swap(low,i);
	}
}
