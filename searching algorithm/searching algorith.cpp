#include <iostream>

using namespace std;

int seqSearch(int);
int binSearch(int);

int const length=10;
int element[length]={1,2,3,4,5,6,7,8,9,10};

int main()
{
	
	int a=9;
	cout << seqSearch(a) << endl;
	cout << binSearch(a);
}

int seqSearch(int item)
{
	int counter;
	bool found = false;
	
	for(counter=0;counter<length;counter++ )
	{
		if(element[counter]==item)
		{
			cout << "yes it is in the array\n";
			found=true;
			break;
		}	
	}
	if(found)
		{
			return counter;
		}
		else
		{
			return -1;
		}
}

int binSearch(int item)
{
	int first = 0; //first index
	int last = length-1; //last index
	int mid; //middle index
	bool found=false;
	
	while(first<=last&&!found)
	{
		mid = (first+last)/2;
		
		if(element[mid]==item)
		{
			found = true;
		}else if(element[mid]>item)
		{
			last = mid-1;
		}else
		{
			first=mid+1;
		}
	}
	if(found)
	{
		return mid;
	}
	else
	{
		return -1;
	}
}
