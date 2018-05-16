#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//procura todas as possíveis instâncias de um caractere dentro de uma string e retorna
//um vetor contendo a posição deles.
vector<int> charsAt(string str, char charAt)
{
    vector<int> charLocations;
    for(int i =0; i < str.size(); i++)
        if(str[i] == charAt)
            charLocations.push_back(i);
    return charLocations;
}
//
//remove todos os caracteres (que se queira) de uma string
string trim(const string& inputNumber, const string& charsToRemove)
{
  	string trimmedString = inputNumber;
	for(int i = 0; i < charsToRemove.size(); i++)
	{
		vector<int> charsLocation = charsAt(trimmedString, charsToRemove[i]);
		for(int j = 0; j < charsLocation.size(); j++) {
			trimmedString.erase((charsLocation[j]-j), 1);
		}
	}
	return trimmedString;
}
//
int validateCpf(string cpfNumber)
{
	string cpfDigits = trim(cpfNumber, ".-");
	string firstNineDigits = cpfDigits.substr(0, 9);
	string firstTenDigits = cpfDigits.substr(0, 10);
	string firstDigit = cpfDigits.substr(9, 1);
	string secondDigit = cpfDigits.substr(10, 1);

	int validateFirstDigit = 0;
	int validateSecondDigit = 0;
	
	for(int i = 0; i < 9; i++) {
        validateFirstDigit += (stoi(string(1, firstNineDigits[i])) * ((firstNineDigits.size() + 1) - i));
    }
        
    validateFirstDigit = (validateFirstDigit * 10) % 11; 
    
    if(validateFirstDigit == 10) {
        validateFirstDigit = 0;
    }  
    
    for(int j = 0; j < 10; j++) {
        validateSecondDigit += (stoi(string(1, firstTenDigits[j])) * ((firstTenDigits.size() + 1) - j));
    }
    
    validateSecondDigit = (validateSecondDigit * 10) % 11;
    
    if(validateSecondDigit == 10) {
        validateSecondDigit = 0;
    }

    if(validateFirstDigit == stoi(firstDigit) && validateSecondDigit == stoi(secondDigit)) 
        return 1;
    
    return 0;

}

int validateCnpj(string cnpjNumber)
{
	string cnpjDigits = trim(cnpjNumber, ".-/");
	string firstTwelveDigits = cnpjDigits.substr(0, 12);
	string firstThirteenDigits = cnpjDigits.substr(0, 13);
	string firstDigit = cnpjDigits.substr(12, 1);
	string secondDigit = cnpjDigits.substr(13, 1);
	int firstVerifiers[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
	int secondVerifiers[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

	int validateFirstDigit = 0;
	int validateSecondDigit = 0;
	
	for(int i = 0; i < firstTwelveDigits.size(); i++) {
        validateFirstDigit += (stoi(string(1, firstTwelveDigits[i])) * firstVerifiers[i]);
    }

    validateFirstDigit = validateFirstDigit % 11;
    
    if(validateFirstDigit < 2) {
        validateFirstDigit = 0;
    } else {
        validateFirstDigit = 11 - validateFirstDigit;
    }

    for(int j = 0; j < 13; j++) {
        validateSecondDigit += (stoi(string(1, firstThirteenDigits[j])) * secondVerifiers[j]);
    }
    
    validateSecondDigit = validateSecondDigit % 11;
    
    if(validateSecondDigit < 2) {
        validateSecondDigit = 0;
    } else {
        validateSecondDigit = 11 - validateSecondDigit;
    }

    if(validateFirstDigit == stoi(firstDigit) && validateSecondDigit == stoi(secondDigit)) 
        return 1;
    
    return 0;
}

int main()
{
	string cnpjTeste = "11.222.333/0001-81";
	int ehValido = validateCnpj(cnpjTeste);
	cout << ehValido << endl;
}