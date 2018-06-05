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

int main()
{
	vector<int> newVectorToSort(20);
	
	srand((unsigned)time(NULL));
	
	generate(newVectorToSort.begin(), newVectorToSort.end(), Randomizer);

 	printf("Un-sorted Vector: ");

	for(int i = 0; i < 20; i++)
		printf("%d ", newVectorToSort.at(i));

	vector<int> finalVector = BubbleSort(newVectorToSort);
		printf("\n\nSorted Vector: ");

	for(int i = 0; i < 20; i++)
    	printf("%d ", finalVector.at(i));

	return 0;
}