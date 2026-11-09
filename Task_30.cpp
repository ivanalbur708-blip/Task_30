#include <iostream>
#include  <string>


class AgeException : public std::exception
{
private:
	int age;
public:
	explicit AgeException(int age):age(age) {}

	int getAge() const { return age; }
};

void vote(std::string candidate,int age)
{
	if (age < 18)
	{
		throw AgeException(age);
	}
	else if (age >= 18)
	{
		std::cout << candidate << " can vote!\n";
	}
}

void Checkpassword(const std::string& password)
{
	if (password.empty())
	{
		throw std::invalid_argument("Empty password");
	}
	if (password.length() < 8)
	{
		throw std::invalid_argument("Password is short");
	}

	bool hasdig = false;

	for (char s : password)
	{
		if (s >= '0' && s <= '9')
		{
			hasdig = true;
		}
	}

	if (!hasdig)
	{
		throw std::invalid_argument("Password must contain a digit");
	}
}


int toInt(const std::string& s)
{

	std::string digits = s;

    if (digits.empty())
	{
		throw  std::invalid_argument("Empty number");
	}

	if (s[0] == '-' || s[0] == '+')
	{
		digits = s.substr(1);
	}

	if (digits.empty())
	{
		throw std::invalid_argument("Empty number");
	}

	for (int i = 0; i < digits.length();i++)
	{
		if (digits[i] < '0' || digits[i] > '9')
		{
			throw std::invalid_argument("Not a number");
		}
	}
	return  std::stoi(s);
}

int main()
{
	//Task 1
	std::string text;

	std::cout << "Enter a number: ";
	std::getline(std::cin, text);

	try
	{
		int number = toInt(text);
		std::cout << "Number: " << number << '\n';
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Error: Number is out of range\n";
	}

	//Task 2
	std::string password;
	std::cout << "Password: ";
	std::getline(std::cin, password);
	try
	{
		Checkpassword(password);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	//Task 3
	try
	{
		int age;
		std::string candidate;

		std::cout << "Enter age: ";
		std::cin >> age;
		std::cout << "Enter candidate: \n";
		std::cin >> candidate;

		vote(candidate, age);
	}
	catch (const AgeException& e)
	{
		std::cout << "You must be at least 18 years old!\n";
	}
}

