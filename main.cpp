#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "./0_headers/input_validation.h"
#include "./0_headers/utility.h"
Input_Validation validator;
Utility util;
int main(int argc, char *argv[])
{
	short int file_name = 0;	 // optional
	short int limit = 0;		 // optional
	short int security_code = 0; // mandatory
	short int begin_date = 0;	 // optional, suggested
	short int end_date = 0;		 // optional, suggested

	bool send_req = true;

	for (int i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'f')
			{
				file_name = i + 1;
			}
			else if (argv[i][1] == 'l')
			{
				limit = i + 1;
			}
			else if (argv[i][1] == 'b')
			{
				begin_date = i + 1;
			}
			else if (argv[i][1] == 'e')
			{
				end_date = i + 1;
			}
			else if (argv[i][1] == 'c')
			{
				security_code = i + 1;
			}
		}
	}
	if (security_code == 0)
	{
		if (validator.validate_Security_Code(argv[1]))
		{
			security_code = 1;
			printf("%s %d", argv[security_code], validator.validate_Security_Code(argv[security_code]));
		}
		else
		{
			printf("\nINVALID ARGUMENT(S):\n	");
			printf("INVALID SECURITY CODE: Security Code needs to be a 6 digit number");
			send_req = false;
		}
	}
	else
	{
		printf("%s %d", argv[security_code], validator.validate_Security_Code(argv[security_code]));
	}
	if (begin_date != 0)
	{
		validator.date_validation(argv[begin_date]);
	}
	else
	{
		printf("\nWARNING:\n	");
		printf("BEGIN DATE NOT SPECIFIED: Will serve all data since inception");
	}
	if (end_date != 0)
	{
		validator.date_validation(argv[end_date]);
	}
	else
	{
		printf("\nWARNING:\n	");
		printf("END DATE NOT SPECIFIED: Will serve all data till most recent update");
	}

	printf("\n\n\nCONFIRM YOUR REQUEST\n");
	printf("	%-15s:  %s\n", "SECURITY CODE", argv[security_code]);
	printf("	%-15s:  %s\n", "BEGIN DATE", (begin_date == 0 ? "-NA-" : argv[begin_date]));
	printf("	%-15s:  %s\n", "END DATE", (end_date == 0 ? "-NA-" : argv[end_date]));
	printf("	%-15s:  %s\n", "LIMIT", (limit == 0 ? "-NA-" : argv[limit]));
	printf("\n");

	util.confirmation();
}
