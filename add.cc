#include <iostream>
/*
 * practiceing with git
 */
int main(int argc, char *argv[])
{
	std::cout << "Hello"  << std::endl;
        // prompt user to enter two numbers
        std::cout << "Enter two integers:" << std::endl; 
        int v1 = 0, v2 = 0;
        std::cin >> v1 >> v2;   
        std::cout << "The sum of " << v1 << " and " << v2
                  << " is " << v1 + v2 << std::endl;
        return 0;
}


