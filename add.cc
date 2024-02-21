#include <iostream>
//#Thu Feb 15 10:21:01 PM EST 2024
//# studying the book Pro Git example
int main()
{
	std::cout << "Hello"  << std::endl;
        // prompt user to enter two numbers
        std::cout << "Enter two integes:" << std::endl; 
        int v1 = 0, v2 = 0;
        std::cin >> v1 >> v2;   
        std::cout << "The sum of " << v1 << " and " << v2
                  << " is " << v1 + v2 << std::endl;
        return 0;
}


