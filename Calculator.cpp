#include <iostream>
#include <string>

class Calculator
{
public:
	float calculation(float integer1, float integer2, const std::string& response) const
	{
		float result{ 0 };
		if (response == "+")
		{
			result = add(integer1, integer2);
		}
		else if (response == "-")
		{
			result = subtract(integer1, integer2);
		}
		else if (response == "*")
		{
			result = multiply(integer1, integer2);
		}
		else if (response == "/")
		{
			result = divide(integer1, integer2);
		}
		else
		{
			throw std::runtime_error("Invalid operation"); // Throw an exception for invalid operations
		}
		return result;
	}

	float add(float integer1, float integer2) const
	{
		return integer1 + integer2;
	}

	float subtract(float integer1, float integer2) const 
	{
		return integer1 - integer2;
	}

	float multiply(float integer1, float integer2) const
	{
		return integer1 * integer2;
	}

	float divide(float integer1, float integer2) const
	{
		return integer1 / integer2;
	}
};

int main()
{
	Calculator calc;
	std::string response;

	while (true)
	{
		// Get desired operation to perform from the user
		std::cout << "Enter the desired operation:\n| + | - | * | / | quit | ";
		std::cin >> response;

		if (response == "quit")
		{
			std::cout << "Exiting program..." << std::endl;
			break; // Exit the loop if user chooses to quit
		}

		// Get two integers from the user
		std::cout << "Enter two integers: ";
		float integer1{};
		float integer2{};
		std::cin >> integer1 >> integer2;

		if (std::cin.fail())
		{
			std::cin.clear(); // Clear the error state of the input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
			std::cout << "Invalid input. Please enter valid integers." << std::endl;
			continue; // Restart the loop for another iteration
		}

		try
		{
			float result = calc.calculation(integer1, integer2, response);
			std::cout << "Result: " << result << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}