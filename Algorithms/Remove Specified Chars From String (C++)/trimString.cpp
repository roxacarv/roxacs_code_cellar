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

string trim(const string& str, const string& charsToRemove)
{
  	string trimmedString = str;
	for(int i = 0; i < charsToRemove.size(); i++)
	{
		vector<int> charsLocation = findAllCharsAt(trimmedString, charsToRemove[i]);
		for(int j = 0; j < charsLocation.size(); j++) {
			trimmedString.erase((charsLocation[j]-j), 1);
		}
	}
	return trimmedString;
}

int main()
{
	string testStr = "thi*s i.s a t.est / string //";
	testStr = trim(testStr, "/.*");
	cout << testStr << endl;
}