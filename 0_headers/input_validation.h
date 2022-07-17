#include <string>
class Input_Validation
{
private:
	static char integers[10];

public:
	Input_Validation();
	Input_Validation(int argc, char *argv[]);

	~Input_Validation();
	bool validate_Security_Code(char *SecurityCode);
	bool date_validation(char *date); // YYYY-MM-DD

protected:
};