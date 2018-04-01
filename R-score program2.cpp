#include <iostream> //Allows the program to use inputs and outputs
using namespace std; //Allows to omit writing std before each input and output
int main()
{
	int counter{ 0 }; //Variable that will count the number of high school classes
	double averagehs{ 0 }; // Variable that will store the high school class average (input)   
	double total{ 0 }; // Variable that will store the sum of the high school class averages
	double ISG{ 0 }; // Variable that will store the calculated ISG component of the R-score formula

	cout << "\nIn order to calculate your R-score, you are first asked to input all class \naverages of your Secondary IV and V courses.\n\n" << endl; //Message to the user
	cout << "Enter your high school class averages and press ENTER *after each input*. \nWhen you are done, input -1 to get to the next step.\n" << endl; //Message to the user
	while (averagehs != -1) //The user inputs -1 when he is done in order to exit the loop. Otherwise, the following statements will keep starting over.
	{
		cin >> averagehs; //The average is inputted by the user
		total = total + averagehs; //The average is added to the sum of the averages
		counter++; //Adds 1 to the number of averages
		cout << "\n" << endl; //Adds space between each input
	}

	counter--; //Subtracts 1 from the number of averages in order to compensate for the final input (-1) to exit the loop
	total = total + 1; //Adds 1 to the sum of averages in order to compensate for the -1
	total = total / counter; //Computes the average of the averages
	ISG = (total - 75) / 14; //Calculates the ISG component using the formula for ISG

	int x{ 0 }; //Variable that will let the user decide when to proceed to the next step
	double grade; //Variable that will store the grade of a College course (input)
	double average; //Variable that will store the class average of a College course (input)
	double stdev; //Variable that will store the standard deviation of a College course (input)
	double credits; //Variable that will store the number of credits of a College course (input)
	double zscore; // Variable that will store the calculated Z-score component of the R-score formula
	double CRCcourse;// Variable that will store the calculated R-score of a single class
	int semester; //Variable to determine if the course is taken during the first semester or otherwise
	double creditstotal{ 0 }; //Variable that will store the sum of the credits of all the courses
	double CRCfinal{ 0 }; //Variable that will store the sum of the R-score of all the courses
	const int C = 5; //Constant that is needed in the R-score formula
	const int D = 5; //Constant that is needed in the R-score formula

	cout << "The next step is to enter the grade, the average, the standard deviation, \nand the number of credits, for each of your Cegep courses.\n" << endl; //Message to the user
	while (x != -1) //The user will input -1 after entering the information of the last course in order to end the loop and to proceed to the next step.
		//Otherwise, the following statements will keep starting over
	{
		cout << "Provide the following information for a course:" << endl; //Message to the user
		cout << "Enter your grade: " << endl; //Message to the user
		cin >> grade; //The grade is inputted by the user
		cout << "Enter the average: " << endl; //Message to the user
		cin >> average; //The class average is inputted by the user
		cout << "Enter the standard deviation: " << endl; //Message to the user
		cin >> stdev; //The standard deviation is inputted by the user
		zscore = (grade - average) / stdev; //The Z-score of the course is calculated using its respective formula
		CRCcourse = (zscore + ISG + C)*D; //The R-score of the course is calculated using its respective formula
		cout << "Enter the number of credits: " << endl; //Message to the user
		cin >> credits; //The number of credits is inputted by the user

		if (grade < 60) //This statement launches if the user has failed the course, in order to impose a correction factor
		{
			cout << "If this course was taken during the first semester, input 1. Otherwise, input 0." << endl; //Message to the user
			cin >> semester; //The user lets the program know if the course was taken in the first semester or not
			if (semester != 1)
				credits = credits*0.5; //This correction is applied if the course is not taken during the first semester
			else
				credits = credits*0.25; //This correction is applied if the course is taken during the first semester
		}

		CRCcourse = CRCcourse*credits; //The R-score of the course is multiplied by its number of credits. 
									   //(*The variable is still called CRCcourse but its value is not equal to CRC anymore as it is multiplied by the number of credits. 
									   //The same variable is only recycled in order for the program not to have to manage an unnecessary variable.*)
		CRCfinal = CRCfinal + CRCcourse; //The R-score of the course is added to the sum of the R-scores of all the courses
		creditstotal = creditstotal + credits;//The number of credits of the course is added to the total number of credits of all courses
		cout << "If you have another course to consider, input 1. Otherwise, input -1 \nand press ENTER to finalize the process." << endl; //Message to the user
		cin >> x; //The user decides whether to restart the loop of to end it
	}

	CRCfinal = CRCfinal / creditstotal; //the sum of the R-scores of all the courses is divided by the total number of credits of all courses

	int DECAandS; //Variable to determine if the user is completing a DEC in Arts and Sciences or an IB degree
	cout << "Will or did you graduate with a DEC in Arts and Sciences? \nInput 1 if yes, or 2 otherwise." << endl; //Message to the user
	cin >> DECAandS; //The user lets the program know if he/she is completing a DEC in Arts and Sciences or an IB degree
	if (DECAandS == 1)
		CRCfinal = CRCfinal + 0.5; //This correction is applied if the user is completing such a DEC

	if (CRCfinal > 0, CRCfinal < 50) //Determines if the R-score respects the possible boundaries
		cout << "Your R-score is " << CRCfinal << endl; //The calculated R-score is revealed to the user 
	else
		cout << "A mistake must have occured, because the R-score calculated is impossible." << endl; //This message appears if the R-score 
	//calculated does not respect the possible boundaries
}