#include <iostream>
using namespace std;



void merge(int arr1[], int arr2[], int sizeArr1, int* med1, int* med2)
{
	int size = sizeArr1 * 2;
	int* final = new int[size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if(arr1[j] < arr2[k] && j < (size / 2) && k < (size / 2) )
		{
			*(final+i) = arr1[j];
			j++;
		}
		else if (arr1[j] > arr2[k] && k >= (size / 2) && j <= size / 2)
		{
			*(final+i) = arr1[j];
			j++;
		}

		else if (arr1[j] > arr2[k] && j >= (size / 2) && k <= size / 2)
		{
			*(final+i) = arr2[k];
			k++;
		}
		else
		{
			*(final+i) = arr2[k];
			k++;
		} 
	}
	k = size / 2;
	j = k - 1;
	*med1 = final[j];
	*med2 = final[k];
	delete final;
}


int main()
{
	int arr1[4] = {11, 88, 96, 100};
	int arr2[4] = {5, 6, 9, 10};
	int final[8];
	int size = 4;
	int med1;
	int med2;
	merge(arr1, arr2, size, &med1, &med2);
	cout<<endl<<med1<<" "<<med2<<endl;
	return 0;
}