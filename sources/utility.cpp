#include "../0_headers/utility.h"

void Utility::confirmation()
{
	printf("Confirm your Request ([Y]/N)? ");
	{
		char confirmation = 'Y';
		scanf("%c", &confirmation);
		if (confirmation == 'N')
		{
			exit(0);
		}
		else if (confirmation == 'Y')
		{
		}
		else
		{
			fflush(stdin);
			Utility::confirmation();
		}
	}
}

Utility::Utility()
{
}

Utility::~Utility() {}