Name: Kaleab Alemu
Course: CSCE 3110 006.003
Project 2


This Program makes use of a stack and queue while implementing recursion to convert an infix expression to postfix and evaluate the value of a given expression 

The program accepts the infix expression as a string and then parses it to tokens separated by space. It checks the first element of the token and determines its type from the inputtalbe. An Input is either a number, operator, decimal, negative number or parentheses. It then uses a statetable array that holds the index of the appropriate functions for each state of the parsing. After the appropriate function index is extracted from the statetable array, the index is used in the statefunction array to call the appropriate function with the token passed as a parameter. There's a static bool that identifies whether the expression is being converted to postfix or being evaluated.

If the function is being converted to postfix. The function executes the following commands. If the token is a number, the function enqueues the token. On the contrary, if it's an operator, it compares the top elements operator precedence with the tokens precedence. If the token has a greater precedence than the top operator (greater than or equal to for exponent operator), the function pushes the token on to the stack. If the top is greater than or equal to the token (greater than for exponent operator), the function pops the stack and enqueues it, provided the top operator is greater than the token's precedence and the stack is not empty. The function keeps iterating through the infix expression and performing these commands until the expression comes to an end.

For evaluation, first the postfix expression is extracted from the queue and parsed like the one described above. When the function reads a number token it pushes it on to the stack. when it encounters an operator token, it pops two operands from the stack and performs the operator on those operands and pushes the result back on to the stack. The function keeps iterating through the postfix expression until the expression comes to an end.
