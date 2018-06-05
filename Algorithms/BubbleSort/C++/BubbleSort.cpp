#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int Randomizer()
{
	int randomNumber = rand() % 100;
	return randomNumber;
}

vector<int> BubbleSort(vector<int> vectorToSort)
{
	bool change = false;
	for(unsigned int i = 0; i < (vectorToSort.size() - 1); i++)
	{
		if(vectorToSort.at(i) > vectorToSort.at(i+1))
		{
			int bufferElement = vectorToSort.at(i);
			vectorToSort.at(i) = vectorToSort.at(i+1);
			vectorToSort.at(i+1) = bufferElement;
			change = true;
		}
	}
	if(change)
		return BubbleSort(vectorToSort);
	else
		return vectorToSort;
}

//RECEIVES AN ARRAY BUT RETURNS A POINTER ->
//WILL RETURN A POINTER NOT AN ARRAY!
int * BubbleSortForArray(int *arrayToSort, size_t arrayLength)
{
	bool change = false;
	for(int i = 0; i < (arrayLength - 1); i++)
	{
		if(*(arrayToSort + i) > *(arrayToSort + (i+1)))
		{
			int bufferElement = *(arrayToSort + i);
			*(arrayToSort + i) = *(arrayToSort + (i+1));
		  	*(arrayToSort + (i+1)) = bufferElement;
			change = true;
		}
	}
	if(change)
		return BubbleSortForArray(arrayToSort, 20);
	else
		return arrayToSort;
}

int main()
{
  	//Vector to fill with 20 positions
	vector<int> newVectorToSort(20);
  	//Array to fill with 20 positions
	int newArrayToSort[20];
  	//Pointer to fill
  	int * newPointerElements = (int*)malloc(20*sizeof(int));
  	//Generate a random seed
	srand((unsigned)time(NULL));
  
  	//Sort Vector
  	for(int i = 0; i < 20; i++)
    	newArrayToSort[i] = Randomizer();

  	for(int i = 0; i < 20; i++)
    	*(newPointerElements + i) = Randomizer();
  
  	generate(newVectorToSort.begin(), newVectorToSort.end(), Randomizer);

 	printf("Un-sorted Vector: ");

	for(int i = 0; i < 20; i++)
		printf("%d ", newVectorToSort.at(i));

	vector<int> finalVector = BubbleSort(newVectorToSort);
		printf("\n\nSorted Vector: ");

	for(int i = 0; i < 20; i++)
    	printf("%d ", finalVector.at(i));


  	//Sort Array  
  	printf("\n\nUn-sorted Array: ");

  	for(int i = 0; i < 20; i++)
    	printf("%d ", newArrayToSort[i]);

  	int * SortedArray; //BubbleSortForArray(array, size) returns a pointer
  	//Is necessary to pass the array size. BubbleSortForArray receives an array and its size.
  	SortedArray = BubbleSortForArray(newArrayToSort, 20);

  	printf("\n\nSorted Array: ");

  	for(int i = 0; i < 20; i++)
    	printf("%d ", SortedArray[i]); //You can access a pointer with Array-style syntax

  	//Sort array-like pointer
  	printf("\n\nUn-sorted Array-like Pointer: ");

  	for(int i = 0; i < 20; i++)
    	printf("%d ", *(newPointerElements + i));

  	int * SortedPointerElements = BubbleSortForArray(newPointerElements, 20);

	printf("\n\nSorted Array-like Pointer: ");

  	for(int i = 0; i < 20; i++)
    	printf("%d ", *(SortedPointerElements + i));

    free(newPointerElements);

	return 0;
}