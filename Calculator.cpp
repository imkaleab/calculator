#include "Calculator.h"
#include "Queue.h"
#include "Stack.h"
#include <cmath>
#include <iostream>

//static variable initialization
Queue 	Calculator::Q;
Stack 	Calculator::ST;
int		Calculator::NumPar = 0;
bool	Calculator::Evaluate;
double	Calculator::Result;

void Calculator::Delete()
{
	ST.Delete();
	Q.Delete();
}

//input type array that returns the type of input in enum value
Calculator::InputType Calculator::InputTable[] = {
												InputUnknown,		// 00
												InputUnknown,		// 01
												InputUnknown,		// 02
												InputUnknown,		// 03
												InputUnknown,		// 04
												InputUnknown,		// 05
												InputUnknown,		// 06
												InputUnknown,		// 07
												InputUnknown,		// 08
												InputUnknown,		// 09
												InputUnknown,		// 0A
												InputUnknown,		// 0B
												InputUnknown,		// 0C
												InputUnknown,		// 0D
												InputUnknown,		// 0E
												InputUnknown,		// 0F
												InputUnknown,		// 10
												InputUnknown,		// 11
												InputUnknown,		// 12
												InputUnknown,		// 13
												InputUnknown,		// 14
												InputUnknown,		// 15
												InputUnknown,		// 16
												InputUnknown,		// 17
												InputUnknown,		// 18
												InputUnknown,		// 19
												InputUnknown,		// 1A
												InputUnknown,		// 1B
												InputUnknown,		// 1C
												InputUnknown,		// 1D
												InputUnknown,		// 1E
												InputUnknown,		// 1F
												InputSpace,			// 20
												InputUnknown,		// 21
												InputUnknown,		// 22
												InputUnknown,		// 23
												InputUnknown,		// 24
												InputModulo,		// 25
												InputUnknown,		// 26
												InputUnknown,		// 27
												InputLeftPar,		// 28
												InputRightPar,  	// 29
												InputMultiply,		// 2A
												InputPlus,			// 2B
												InputUnknown,		// 2C
												InputMinus,			// 2D
												InputDecimal,		// 2E
												InputDivide,		// 2F
												Input0,				// 30
												Input1,				// 31
												Input2,				// 32
												Input3,				// 33
												Input4,				// 34
												Input5,				// 35
												Input6,				// 36
												Input7,				// 37
												Input8,				// 38
												Input9,				// 39
												InputUnknown,		// 3A
												InputUnknown,		// 3B
												InputUnknown,		// 3C
												InputUnknown,		// 3D
												InputUnknown,		// 3E
												InputUnknown,		// 3F
												InputUnknown,		// 40
												InputUnknown,		// 41
												InputUnknown,		// 42
												InputUnknown,		// 43
												InputUnknown,		// 44
												InputUnknown,		// 45
												InputUnknown,		// 46
												InputUnknown,		// 47
												InputUnknown,		// 48
												InputUnknown,		// 49
												InputUnknown,		// 4A
												InputUnknown,		// 4B
												InputUnknown,	    // 4C
												InputUnknown,		// 4D
												InputUnknown,		// 4E
												InputUnknown,		// 4F
												InputUnknown,		// 50
												InputUnknown,		// 51
												InputUnknown,		// 52
												InputUnknown,		// 53
												InputUnknown,		// 54
												InputUnknown,		// 55
												InputUnknown,		// 56
												InputUnknown,		// 57
												InputUnknown,		// 58
												InputUnknown,		// 59
												InputUnknown,		// 5A
												InputUnknown,		// 5B
												InputUnknown,		// 5C
												InputUnknown,		// 5D
												InputExponent,		// 5E
												InputUnknown,		// 5F
												InputUnknown,		// 60
												InputUnknown,		// 61
												InputUnknown,		// 62
												InputUnknown,		// 63
												InputUnknown,		// 64
												InputUnknown,		// 65
												InputUnknown,		// 66
												InputUnknown,		// 67
												InputUnknown,		// 68
												InputUnknown,		// 69
												InputUnknown,		// 6A
												InputUnknown,		// 6B
												InputUnknown,		// 6C
												InputUnknown,		// 6D
												InputUnknown,		// 6E
												InputUnknown,		// 6F
												InputUnknown,		// 70
												InputUnknown,		// 71
												InputUnknown,		// 72
												InputUnknown,		// 73
												InputUnknown,		// 74
												InputUnknown,		// 75
												InputUnknown,		// 76
												InputUnknown,		// 77
												InputUnknown,		// 78
												InputUnknown,		// 79
												InputUnknown,		// 7A
												InputUnknown,		// 7B
												InputUnknown,		// 7C
												InputUnknown,		// 7D
												InputUnknown,		// 7E
												InputUnknown,		// 7F
												InputUnknown,		// 80
												InputUnknown,		// 81
												InputUnknown,		// 82
												InputUnknown,		// 83
												InputUnknown,		// 84
												InputUnknown,		// 85
												InputUnknown,		// 86
												InputUnknown,		// 87
												InputUnknown,		// 88
												InputUnknown,		// 89
												InputUnknown,		// 8A
												InputUnknown,		// 8B
												InputUnknown,		// 8C
												InputUnknown,		// 8D
												InputUnknown,		// 8E
												InputUnknown,		// 8F
												InputUnknown,		// 90
												InputUnknown,		// 91
												InputUnknown,		// 92
												InputUnknown,		// 93
												InputUnknown,		// 94
												InputUnknown,		// 95
												InputUnknown,		// 96
												InputUnknown,		// 97
												InputUnknown,		// 98
												InputUnknown,		// 99
												InputUnknown,		// 9A
												InputUnknown,		// 9B
												InputUnknown,		// 9C
												InputUnknown,		// 9D
												InputUnknown,		// 9E
												InputUnknown,		// 9F
												InputUnknown,		// A0
												InputUnknown,		// A1
												InputUnknown,		// A2
												InputUnknown,		// A3
												InputUnknown,		// A4
												InputUnknown,		// A5
												InputUnknown,		// A6
												InputUnknown,		// A7
												InputUnknown,		// A8
												InputUnknown,		// A9
												InputUnknown,		// AA
												InputUnknown,		// AB
												InputUnknown,		// AC
												InputUnknown,		// AD
												InputUnknown,		// AE
												InputUnknown,		// AF
												InputUnknown,		// B0
												InputUnknown,		// B1
												InputUnknown,		// B2
												InputUnknown,		// B3
												InputUnknown,		// B4
												InputUnknown,		// B5
												InputUnknown,		// B6
												InputUnknown,		// B7
												InputUnknown,		// B8
												InputUnknown,		// B9
												InputUnknown,		// BA
												InputUnknown,		// BB
												InputUnknown,		// BC
												InputUnknown,		// BD
												InputUnknown,		// BE
												InputUnknown,		// BF
												InputUnknown,		// C0
												InputUnknown,		// C1
												InputUnknown,		// C2
												InputUnknown,		// C3
												InputUnknown,		// C4
												InputUnknown,		// C5
												InputUnknown,		// C6
												InputUnknown,		// C7
												InputUnknown,		// C8
												InputUnknown,		// C9
												InputUnknown,		// CA
												InputUnknown,		// CB
												InputUnknown,		// CC
												InputUnknown,		// CD
												InputUnknown,		// CE
												InputUnknown,		// CF
												InputUnknown,		// D0
												InputUnknown,		// D1
												InputUnknown,		// D2
												InputUnknown,		// D3
												InputUnknown,		// D4
												InputUnknown,		// D5
												InputUnknown,		// D6
												InputUnknown,		// D7
												InputUnknown,		// D8
												InputUnknown,		// D9
												InputUnknown,		// DA
												InputUnknown,		// DB
												InputUnknown,		// DC
												InputUnknown,		// DD
												InputUnknown,		// DE
												InputUnknown,		// DF
												InputUnknown,		// E0
												InputUnknown,		// E1
												InputUnknown,		// E2
												InputUnknown,		// E3
												InputUnknown,		// E4
												InputUnknown,		// E5
												InputUnknown,		// E6
												InputUnknown,		// E7
												InputUnknown,		// E8
												InputUnknown,		// E9
												InputUnknown,		// EA
												InputUnknown,		// EB
												InputUnknown,		// EC
												InputUnknown,		// ED
												InputUnknown,		// EE
												InputUnknown,		// EF
												InputUnknown,		// F0
												InputUnknown,		// F1
												InputUnknown,		// F2
												InputUnknown,		// F3
												InputUnknown,		// F4
												InputUnknown,		// F5
												InputUnknown,		// F6
												InputUnknown,		// F7
												InputUnknown,		// F8
												InputUnknown,		// F9
												InputUnknown,		// FA
												InputUnknown,		// FB
												InputUnknown,		// FC
												InputUnknown,		// FD
												InputUnknown,		// FE
												InputUnknown		// FF
};
//state function array keeps track of input and returns index of apporopriate function for input
Calculator::UChar Calculator::StateTable[NumInputs][NumStates] = {
	//							StartGettingInput	AfterNumber		AfterOperator		AfterLeftPar	AfterRightPar		AfterExponent			
	/*	Input0			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input1			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input2			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input3			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input4			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input5			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input6			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input7			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input8			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	Input9			*/	{			1,				 1,				 1,					 1,		 		 1,					 1,			},
	/*	InputPlus		*/	{			2,				 2,				 2,					 2,		 		 2,					 2,			},
	/*	InputMinus		*/	{			2,				 2,				 2,					 2,		 		 2,					 2,			},
	/*	InputMultiply	*/	{			3,				 3,				 3,					 3,		 		 3,					 3,			},
	/*	InputDivide		*/	{			3,				 3,				 3,					 3,		 		 3,					 3,			},
	/*	InputModulo		*/	{			3,				 3,				 3,					 3,		 		 3,					 3,			},
	/*	InputExponent	*/	{			4,				 4,				 4,					 4,		 		 4,					 4,			},
	/*	InputLeftPar	*/	{			5,			     5,				 5,					 5,		 		 5,					 5,			},
	/*	InputRightPar	*/	{			6,			     6,				 6,					 6,		 		 6,					 6,			},
	/*	InputDecimal	*/	{			7,			     7,				 7,					 7,		 		 7,					 7,			},
	/*	InputUnkown		*/	{			0,			     0,				 0,					 0,		 		 0,					 0			},
};

//array of functions
Calculator::CalcFunc Calculator::StateFunction[]{
									NotYetDone,		//0
									GotANumber,		//1
									GotASOperator,	//2
									GotMDOperator,	//3
									GotExponent,	//4
									GotLPar,		//5
									GotRPar,		//6
									GotDecimal		//7
};

void Calculator::ReadInput(string x) //converts infix to postfix
{
	InFix = x;
	UChar LastChar;
	int i = 0;
	Evaluate = false;
	ReadState CurrentState = StartReading;
	for (unsigned int j = 0; j < InFix.length(); j++) //loop through till the end of the file and extract tokens
	{
		string temp;
		bool x = false;
		while ( !x && (i < InFix.length())) //extract a single token
		{
			temp += InFix[i];
			i++;
			x = isspace(InFix[i]);
		}
		if (i <= InFix.length()) //uncover the type of token and run appropriate function
		{
			LastChar = temp[0];
			CurrentState = StateFunction[StateTable[InputTable[LastChar]][CurrentState]](temp);
		}	
		i++;
	}
	while (!ST.IsEmpty()) //pop any operators left in stack and add to queue
	{
		Node* temp = ST.Pop();
		if (temp->Type != Calculator::LeftParentheses)
			{
				Q.Enqueue((temp->Data + " "), temp->Type);
			}
		temp->next = NULL;
		delete temp;
	}	
}
void 	Calculator::Eval() //evaluate method
{
	if(!Q.IsEmpty()) //check if queue is not empty and empty it
		Q.Delete();
	
	if (!ST.IsEmpty()) //check if stack is not empty and empty it
		ST.Delete();

	Evaluate = true;
	UChar LastChar;
	int i = 0;
	ReadState CurrentState = StartReading;
	for (unsigned int j = 0; j < PostFix.length(); j++) //loop through each token in postfix expression
	{
		string temp;
		bool x = false;
		while ( !x && (i < PostFix.length())) //extract a single token
		{
			temp += PostFix[i];
			i++;
			x = isspace(PostFix[i]);
		}
		if (i <= PostFix.length()) //uncover the type of token and execute appropriate function
		{
			LastChar = temp[0];
			CurrentState = StateFunction[StateTable[InputTable[LastChar]][CurrentState]](temp);
		}	
		i++;
	}
}
void	Calculator::Convert()
{
	while(!Evaluate && !Q.IsEmpty())
	{
		if ((Q.front)->Type != LeftParentheses && (Q.front)->Type != RightParenthesis)
			PostFix += Q.front->Data;
		Q.Dequeue();
	}
	PostFix.pop_back();
}
Calculator::ReadState Calculator::GotANumber(string& str)
{
	if (!Evaluate) //check if its evaluate method calling this function or convert method
	{
		Q.Enqueue((str + " "), 5); //it's not evaluate so enqueue the number 
		return AfterNumber;
	}
	else 
	{
		ST.Push(str, 0); //evaluate is calling the function so push to stack
		return AfterNumber;
	}
	
}
Calculator::ReadState Calculator::GotDecimal(string& str)
{
	if (!Evaluate && str.length() > 1) //check if its evaluate method calling this function or convert method
	{
		Q.Enqueue(("0" + str + " "), 5); //it's not evaluate so add 0 to the front of the number and enqueue
	}
		return AfterNumber;
}
Calculator::ReadState Calculator::GotASOperator(string& str)
{
	if (!Evaluate) //check if its evaluate method calling this function or convert method
	{
		if (str.length() > 1) // check if the token is a negative number if so enqueue 
		{
			Q.Enqueue((str + " "), 5);
			return AfterNumber;
		}
/*push operator to stack if it has higher precedence than the top element of the stack or pop the top operator and enqueue it provided that its precedence is
 greater than or equal to AS operator and stack is not empty*/		
 		else if (ST.IsEmpty()) 
			ST.Push(str, Calculator::AddSubtract);

		else if ((*ST.top).Type < Calculator::AddSubtract)
			ST.Push(str, Calculator::AddSubtract);

		else
		{
			bool y = true;
			while (y && ((*ST.top).Type >= Calculator::AddSubtract))
			{
				if ((*ST.top).next == NULL)
				{
					Node* temp = ST.Pop();
					Q.Enqueue((temp->Data + " "), temp->Type);
					ST.Push(str, Calculator::AddSubtract);
					y = false;
					temp->next = NULL;
					delete temp;
				}
				else
				{
					Node* temp = ST.Pop();
					Q.Enqueue((temp->Data + " "), temp->Type);
					temp->next = NULL;
					delete temp;
				}
			}
			if (y != false)
			{
				ST.Push(str, Calculator::AddSubtract);
			}
		}

		return AfterOperator;
	}
	else //evaluate method is calling the function
	{
		if (str.length() > 1) //check if its a negative number and push to stack if it is
		{		ST.Push(str, 0);
				return AfterNumber;
		}
		Node* temp = ST.Pop(); //push the top operands from the stack and perform desired operation and push back the value to the stack
		Node* temp2 = ST.Pop();
		switch(str[0])
		{
			case('+'):
			Result = std::stod(temp2->Data) + std::stod(temp->Data);
			temp->Data = std::to_string(Result);
			break;
			case('-'):
			Result = std::stod(temp2->Data) - std::stod(temp->Data);
			temp->Data = std::to_string(Result);
		}
		ST.Push(temp->Data, temp->Type);
		temp->next = NULL;
		temp2->next = NULL;
		delete temp;
		delete temp2;
		return AfterOperator;
	}

}
Calculator::ReadState Calculator::GotMDOperator(string& str)
{
	if (!Evaluate) //check if its evaluate method calling this function or convert method
	{
/*push operator to stack if it has higher precedence than the top element of the stack or pop the top operator and enqueue it provided that its precedence is
 greater than or equal to MD operator and stack is not empty*/
		if (ST.IsEmpty())
			ST.Push(str, Calculator::MultiplyDivide);

		else if ((*ST.top).Type < Calculator::MultiplyDivide)
		{
			ST.Push(str, Calculator::MultiplyDivide);
		}

		else
		{
			bool y = true;
			while (y && ((*ST.top).Type >= Calculator::MultiplyDivide))
			{
				if ((*ST.top).next == NULL)
				{
					Node* temp = ST.Pop();
					Q.Enqueue((temp->Data + " "), temp->Type);
					temp->next = NULL;
					delete temp;
					ST.Push(str, Calculator::MultiplyDivide);
					y = false;
				}
				else 
				{
					Node* temp = ST.Pop();
					Q.Enqueue((temp->Data + " "), temp->Type);
					temp->next = NULL;
					delete temp;
				}
			}	
			if (y != false)
			{
				ST.Push(str, Calculator::MultiplyDivide);
			}
		}
		return AfterOperator;
	}
	else //evaluate method is calling the function
	{	
	//push the top operands from the stack and perform desired operation and push back the value to the stack
		Node* temp = ST.Pop();
		Node* temp2 = ST.Pop();
		switch(str[0])
		{
			case('*'):
			Result = std::stod(temp2->Data) * std::stod(temp->Data);
			temp->Data = std::to_string(Result);
			break;
			case('/'):
			Result = std::stod(temp2->Data) / std::stod(temp->Data);
			temp->Data = std::to_string(Result);
			break;
			case('%'):
			Result = std::stoi(temp2->Data) % std::stoi(temp->Data);
			temp->Data = std::to_string(Result);
		}
		ST.Push(temp->Data, temp->Type);
		temp->next = NULL;
		temp2->next = NULL;
		delete temp;
		delete temp2;
		return AfterOperator;
	}
	
}
Calculator::ReadState Calculator::GotLPar(string& str)
{
	//increment number of parentheses found and push operator to stack
	NumPar++;
	ST.Push(str, Calculator::LeftParentheses);
	return AfterLeftPar;
}
Calculator::ReadState Calculator::GotRPar(string& str)
{
	//got right parentheses, pop top operator until left parentheses is found. enqueue the operators 
	int x = NumPar;
	bool y = true;
	if (NumPar == 0)
		NumPar--;
	while (y && NumPar != x-1)
	{
		if ((*ST.top).next == NULL)
			y = false;
		if ((*ST.top).Type == Calculator::LeftParentheses)
		{
			NumPar--;
			Node* temp = ST.Pop();
			temp->next = NULL;
			delete temp;
		}
		else
		{
			Node* temp = ST.Pop();
			Q.Enqueue((temp->Data + " "), temp->Type);
			temp->next = NULL;
			delete temp;
		}

	}
	return AfterRightPar;

}
Calculator::ReadState Calculator::GotExponent(string& str)
{
	if (!Evaluate) //check if eval method is calling this function
	{
		/*push operator to stack if exponent has higher precedence than top operator, or pop operators and enqueue 
		them provided that the top's precedence is greater than exponent and the stack is not empty*/
		if (ST.IsEmpty())
		ST.Push(str, Calculator::Exponent);

		else if ((*ST.top).Type <= Calculator::Exponent)
		{
			ST.Push(str, Calculator::Exponent);
		}

		else
		{
			bool y = true;
			while (y && ((*ST.top).Type > Calculator::Exponent))
			{
				if ((*ST.top).next == NULL)
				{
					std::cout << "From exp: " << std::endl;
					Node* temp = ST.Pop();
					Q.Enqueue((temp->Data + " "), temp->Type);
					ST.Push(str, Calculator::Exponent);
					y = false;
					temp->next = NULL;
					delete temp;
				}
				else
				{
					Node* temp = ST.Pop();
					Q.Enqueue((temp->Data + " "), temp->Type);
					temp->next = NULL;
					delete temp;
				}
			}
			if (y != false)
			{
				ST.Push(str, Calculator::Exponent);
			}
		}
		return AfterExponent;
	}
	else //eval is calling this function
	{
		//pop two operands from stack and perform desired operation and push the value back to the stack
		Node* temp = ST.Pop();
		Node* temp2 = ST.Pop();
		Result = std::pow(std::stod(temp2->Data), (std::stod(temp->Data)));
		temp->Data = std::to_string(Result);
		
		ST.Push(temp->Data, temp->Type);
		temp->next = NULL;
		temp2->next = NULL;
		delete temp;
		delete temp2;
		return AfterExponent;
	}
}

Calculator::ReadState Calculator::NotYetDone(string& str)
{
	std::cout << "not yet done" << std::endl;
	return StartReading;
}

void Calculator::Display()
{
	std::cout << "The resulting postfix expression is: " << PostFix << std::endl;
	if (NumPar == 0)
		std::cout << "The result is: " << Result << std::endl;
	else
		std::cout << "Error: Mismatched Parentheses! Program Terminated." << std::endl;
	
}