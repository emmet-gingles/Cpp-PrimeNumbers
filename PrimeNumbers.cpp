#include <iostream>			// For input/output
#include <limits>				// For validating numeric inputs
#include <vector>				// For vectors
#include <math.h>				// For maths functions

// Standard namespace
using namespace std;

int main(){
	// Initialize variables
	int min;
	int max;
	
	// Output message to user
	cout << "Enter two numbers to see all the primes between them: " << endl;
	
	// Continue loop while inputs are not valid
	while(true){
		// Output message to user
		cout << "Enter a minimum number: " << endl;
		// Get the user's input and save it to variable
		cin >> min;
		
		// If the input is not numeric then continue asking until it is
		while(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Please enter a number " << endl;
			cin >> min;
		}
		
		// Output message to user
		cout << "Enter a maximum number: " << endl;
		// Get user's input and save it to variable
		cin >> max;
		
		// If the input is not numeric then continue asking until it is
		while(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Please enter a number " << endl;
			cin >> max;
		}
		
		// Check that both numbers are greater than zero
		if(min < 0 || max < 0){
			cout << "Please enter a number greater than zero" << endl;
		}
		// Check that maximum is greater than the minimum
		else if(min >= max){
			cout << "Minimum cannot be greater than maximum" << endl;
		}
		// Else break out of loop
		else{
			break;
		}
	}

	
	// Vector to store the prime numbers between the minimum and the maximum
	vector<int> primeNumbers;
	// Loop through each number from the minimum up to the maximum
	for(int i=min;i<=max;i++){
		
		// Even number
		if(i % 2  == 0){
			// If it is 2 then add it to the vector
			if(i == 2){
				primeNumbers.push_back(i);
			}
		}
		// Odd Number
		else{
			// If it is 1 then add it to the vector
			if(i == 1){
				primeNumbers.push_back(i);
			}
			else{
				// Calculate the square root of the number
				double sqRoot = sqrt(i);
				// Check that the square root is not the square of another number eg. 9 or 25
				if(sqRoot != floor(sqRoot)){
					// Floor it to ensure it is a whole number
					sqRoot = floor(sqRoot);
					// Boolean variable to determine  whether or not number is prime
					bool isPrime = true;
					// Start loop at 3 and continue up to the square root
					for(int j=3;j<= sqRoot;j++){
						// Check that j is not a factor of i
						// If j divides evenly into i then it is not prime so change boolean value and break out of loop 
						if(i%j == 0){
							isPrime = false;
							break;
						}
					}
					// If number is still prime then add it to vector
					if(isPrime){
						primeNumbers.push_back(i);
					}
				}
			}
		}
	}
	
	// Show the number of prime numbers 
	cout << "There are " << primeNumbers.size() <<" prime numbers between " << min << " and " << max << endl;
	// Loop through each prime number
	for(int i=0;i < primeNumbers.size();i++){
		// If i is not at the final index in vector then print number followed by a comma
		if(i < primeNumbers.size()-1){
			cout << primeNumbers[i] << ", ";
		}
		// Else it is the final index so just print the number
		else{
			cout << primeNumbers[i] << endl;
		}		
	}
	
	// End program
	return 0;
}
