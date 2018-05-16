#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findAllCharsAt(string str, char charAt)
{
    vector<int> charLocations;
    for(int i =0; i < str.size(); i++)
        if(str[i] == charAt)
            charLocations.push_back(i); //return all the positions of the specified char
    return charLocations;
}

int main()
{
	string testStr = "this is a test / string //";
	vector<int> slashes = findAllCharsAt(testStr, '/');
	for(int i = 0; i < slashes.size(); i++)
		cout << slashes[i] << endl;
}