#include "../0_headers/input_validation.h"

char Input_Validation::integers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
Input_Validation::Input_Validation()
{
	printf("non - parameterised consructor\n");
}

Input_Validation::Input_Validation(int argc, char *argv[])
{
	printf("parameterised consructor\n");
}

Input_Validation::~Input_Validation()
{
	printf("\ndestroyed\n");
}

bool Input_Validation::validate_Security_Code(char *SecurityCode)
{
	int len = 6;

	if (*(SecurityCode + len) != '\0')
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (SecurityCode[i] < '0' || SecurityCode[i] > '9')
		{
			return false;
		}
	}
	return true;
}

bool Input_Validation::date_validation(char *date)
{
	for (short int i = 0; i < 4; i++)
	{
		if (date[i] < '0' || date[i] > '9')
		{
			return false;
		}
	}
	if (date[4] != '-')
	{
		return false;
	}
	for (short int i = 5; i < 7; i++)
	{
		if (date[i] < '0' || date[i] > '9')
		{
			return false;
		}
	}
	if (date[7] != '-')
	{
		return false;
	}
	for (short int i = 8; i < 10; i++)
	{
		if (date[i] < '0' || date[i] > '9')
		{
			return false;
		}
	}

	return true;
}