// formatting nightmare, i need explaination on what the skeleton code from earlier
// is suggesting with multiple functions for the printT as in the function for
// printing the token? also with semicolon vs semicolonT?

// Question on how the emitting is happening and if i make a call where its commented

// is the use of stack useless as of now. there is no need for the actual calculations or useful
// later on

// tips on how to process "add nsw" as code to run in COMPILER... very confusing
// i know this means add in llvmir but am i processing the add or, am i printing
// the llvmir "ADD TEXT" then doing the adding behind the scenes. -- explained alittle in notes for proj 0
// they are arithmetic instructions for the type of operands

// is the variable creation handled in the template or am i responisble for printing
// %t1 = something. -- i am responisble and is in the code.. need help understanding it
// walkthough would be nice

// if i am responisble how am i supposed to print in the template...
// ^^ dumb Question but out of time to not ask.. -- answered above

// noticed OP1 and OP2 in statement, are those using the global variables and
// whats the deal with those variables.. i know they are taken out of future
// projects? -- used for token printing is my best guess...

// the token processing functions use c = fgetc(file) alot and not sure why its used so much
// Is it because its apart of method#2?

// why are we calling fgetc in this project, and where is the file being implemented?
// argument from command line in testing in clang??

// Hope i dont sound way too dumb.. remind that the goal is to get at least project 2 done / pass the class C or up
// by the project due date.



#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <template.h>
#include <string.h>

int global;
int pos;

#define EMPTY_STACK_ERR INT_MIN
typedef struct Stack{
	// THESE ARE THE ELEMENTS!!
	int *array;
	// How many elements are in the stack?
	int size;
	// How big is the array?
	int capacity;
} Stack;
	// Creates a stack with an internal array of length 'capacity'.
	Stack *createStack(int capacity){
		Stack *s;
		if ((s = malloc(sizeof(Stack))) == NULL)
			return NULL;
		if ((s->array = malloc(sizeof(int) * capacity)) == NULL)
		{
			free(s);
			return NULL;
		}
		s->size = 0;
		s->capacity = capacity;
		return s;
	}
	// Destroy stack; coded defensively to avoid segfaults.
	Stack *destroyStack(Stack *s){
		 if (s == NULL)
		 	return NULL;

		 free(s->array);
		 free(s);
		 return NULL;
	 }
	 // Return 1 if the stack is empty, 0 otherwise.int
	 isEmpty(Stack *s)
	 {
		 return (s == NULL || s->size == 0);
	 }
	 // Return 1 if the stack is full, 0 otherwise.int
	 isFull(Stack *s)
	 {
		 return (s == NULL || s->size == s->capacity);
	 }
	 // Push a new element onto the top of the stack.
	 void push(Stack *s, int data){
		 if (isFull(s)){
			 fprintf(stderr, "\n   Error: Stack is full in push().\n");
			 return;
	 }
	 // post-increment
	 s->array[ s->size++ ] = data;
 }
	 // Remove the top element from the stack and return its value.
	 int pop(Stack *s){
		 if (isEmpty(s)){fprintf(stderr, "\n   Error: Stack is empty in pop().\n");
		 		return EMPTY_STACK_ERR;}

			return s->array[ --s->size ];
			}
				// Peek at, but do not remove, the top element on the stack.
			int peek(Stack *s){
					if (isEmpty(s)){fprintf(stderr, "\n   Error: Stack is empty in peek().\n");
					return EMPTY_STACK_ERR;
				}
				return s->array[ s->size-1 ];
			}
			createStack(capacity);
// Stolen from Szumlanski.....
// one function per token
// one function for statement
// save lexemes
// emit LLVM IR, filling in the template
// going to remove spaces and make strcmp function useful in finding "print"
// as a command

// convert characters to the ints using ascii codes
//int lengthofBuffer(buffer[i]){
//		int i = 0;
//		for(i = 0; j < ){

//}

// use stack for project one... i need to make a stack to push values into
// a string then those values are processed in a correct precedence
string precedence(buffer[i], Stack->array[i])
{
	if(isdigit(buffer[i]))
	{
			(int)buffer[i] = buffer[i] - '0';
			push(Stack->array, buffer[i]);
	}
	else if(buffer[i] == '+')
	{
		push(Stack->array, '+');
	}
	else if(buffer[i] == '-')
	{
		push(Stack->array, '-');
	}
	else if(buffer[i] == '/')
	{
		push(Stack->array, '/');
	}
	else if(buffer[i] == '*')
	{
		push(Stack->array, '*');
	}
	else if(buffer[i] == '(')
	{
	// should create new stack to then push and solve for value in the
	// parenthesis,
		int j = 0,k = i;
		while(buffer[i] != ')') // gets number of things in parenthesis for new stack
		{
			j++;
			i++;
		}
		Stack *newOne= createStack(j);
		precedence(buffer[k] , j);
		// after recursion destroys the stack
		newOne = destroyStack(newOne);
	}
}


/*
int* push(int Stack[i])
{
  	if(Stack[0] == NULL)
		Stack[i] = Stack[i];
		else if(Stack[i])
}
// checks the top of the stack
int* peek(int Stack[i])
{
	if(Stack[i] == '\n')
	{
		return Stack[i - 1];
	}
	while(Stack[i+1] != '\n')
	{
		i++;
		if(Stack[i + 1] == '\n')
		{
			return Stack[i];
		}
	}
}
// does the math operations
void pop(int Stack[i], char op)
{
	// call peek then malloc a new array for the operations
	// then put in new values back into "old stack"
	// deallocate the new array/ stack
	// for parenthesis you can make mulitple calls to  the
	// function probably, and dont worry about abunch of operations
	// cuz the pop is called on a open parenthesis and an operations
	// or will be

	int* new_Stack[i] = malloc(sizeof(Stack[i]));
	for(i = 0; i < ;i++)
		new_Stack[i] = peek(Stack[i]);

	Stack[i - 1] op Stack[i - 2];
}

int* Stack = malloc(sizeof(buffer));
*/


/*		// method #2 read one character at a time and check
if ('p' == c) {
}
c = fgetc();
if ('r' == c) {
} else {
 // do error handling
 return false;
}
'i'
// etc..
}

 // Chose method 1
semicolon(buffer){
	int j = 0; // number of newlines
	// allows for seperation and sequences newline characters
	for(int i = 0; i < strlen(buffer);i++)
	{
		if(buffer[i] == ';')
		{
			buffer[i] = '\n';
			j++;
		}
	}
}
*/
// Start of project 2
// watch lecture video and connect these functions into the current parser
// TODO:
// define and finish all of declaration()
// make a consume function as intended below
// make a lookup function to find the address of a things-- findout the thing
// define and finish read()
// make emit compatable or make a print call for these functions
// make factor changes to correctly implement the things.
// define next is identifer in elif checker...
declaration(){
	assert consume() == 'int'; // =============== int as a token or as a string ? prolly string
	String ident == consume();
	assert consume == ';';
	if(contains(ident))
		error();
	String result = newtemp();
	emit("%s = alloca" , result);
	put(ident, result);
}

read(){
	assert consume() == 'read';
 	String ident = consume();
	assert consume == ';';
	String addr = lookup(ident); // or Error
	String result = newtemp();
	emit("%s = read_integer()", result);
	emit("store %s, %s", result, addr);
 }

assign(){
	String ident = consume();
	assert consume() == '='; // not sure about assert consumes and what they mean ??? ===================================
	String result = expression();
	assert consume() == ';';
	String addr = lookup(ident);// or Error
	emit("store %s, %s", result, addr);
}

// change factor to allow memory lookups;

String FACTORCHANGES(){
	elif(next is identifer){
		String ident = consume();
		String addr = lookup(ident); // or Error
		String result = newtemp();
		emit("%s = load %s", result, addr);
		return result;
	}
}
//=======================================================================
// project 1 TODO list
// findout if correctly implemented
// make Lparent and rparent finished and complete
// make a malloc for the tree nodes with malloc(sizeof(root->right// left or whwawtever))
// make numberT print the - in the - numbers or force it's print then call the print on it


// true if recognized, false otherwise --- do i need to do the check through the defines below or a main function check? -----------------------------------
// global variables?
// also use of void parameters and returns are up to me?
int printT(void) {
  buffer[i] = fgetc(c);
  // malloc a buffer
	char* b = malloc(sizeof(c)); // ------------------------ im sure i do this continiously for the string length
	int i = 0;
  while(isalpha(buffer[i]))
	{
		//  add each c to the buffer
		b[i] = buffer[i];
		i++;
	}
	if(strcmp("print", b)) // might not work cuz its not listed as a full string
		{
			// print PRINT token? -----------------
			return 1;
		}
}
// lexeme string or NULL
String numberT(void) {
	buffer[i] = fgetc(c);
  // is it a minus sign?
  if(isdigit(buffer[i]))
  	ungetc(buffer[i], c);
	else
		return buffer[i];
}
// going to make precedence by use of simplyfying the
// numberT function values and correctly storing
// new positions via nesting.

// used in project 1
// handles parenthesis in function

// need to define a language for handling
// Expressions -- term op term
// 							|| exp op exp
struct root{
String* left;
String* right;
String* result;
}typedef root;
// MALLOC THE TREE? ====================================================================

root expression(root r){
 r->left =	term();
 r->result = expression_prime(r->left);
 return r->result;
}
root expression_prime(root r->left){
	// how to get next place in buffer for c
	c = fgetc(buffer[pos + 1]);
	if(c == '+'){
		plusToken(buffer[pos + 1]);
		r->right = term();
		r->result = newtemp();
		// emit
		Emit(r->right, r->left, r->result, counter());
		expression_prime(r->result);
	}
	else if(c == '-'){
		minusToken(buffer[pos + 1]);
		r->right = term(); // ============================================================
		r->result = newtemp();
		// emit
		Emit(r->right, r->left, r->result, counter());
		expression_prime(r->result);
	}
	else
		return r->left;
}
root term(root* r){
	r->left = factor();
	r->result = term_prime(r->left);
	return r->result;
}
root term_prime(root r->left){
	c = fgetc(buffer[pos + 1]);
	if(c == '*'){
		multToken(buffer[pos + 1]);
		root r->right = factor();
		root r->result = newtemp();
		Emit(root r->right, root r->left, root r->result, counter());
		term_prime(root->result);
	}
	else if(c == '/'){
		divToken(buffer[pos + 1]);
		root r->right = factor(); // what to put here? =============================================
		root r->result = newtemp();
		Emit(r->right, r->left, r->result, counter());
		term_prime(r->result);
	}
	else if(c == '%'){
		modToken(buffer[pos + 1]);
		r->left = factor(); // =========================================================
		r->result = newtemp(); // ======================================================
		Emit(r->right, r->left, r->result, counter());
		term_prime(r->result);
	}
	else
		return r->left;
}
// Terms -- Factor op Factor
// 						||TERM OP Factor
// dont care for epsilon as it does nothing
// Factors -- NUMBER
root factor(root r){
	char c = fgetc(buffer[pos]);
	if(c == '('){
		Lparent(); // What is the purpose of Lparent and Rparent
		expression(r);
		Rparent();
	}
	else if(c == '-'){
		printf('-');
		// needs to print - in -7
		// could force print the - here?
		numberT();
	}
	else if(isDigit(c))
		numberT();
	else
		return -1;
}
// ASK HOW you handle op in recursive right tree parsing
// do you make a list of op checkers and then do the
// op in printing like  + = add nsw i32
// if op char read in is +

/*
String Lparent(char buffer[i]){
	int l = 0;

	// finds the number of characters until Rparent
	while(buffer[i] != ')'){
		if(buffer[i] == '('){
			Lparent(buffer[pos]);
		}
		i++;
		l++;
	}
	// make a new array for the chars/ strings for llvmir
	char a[] = malloc(sizeof(buffer[l]));
	int j = 0;

	while(j != l){
		// dont remember this purpose??
		// fill a new array for no reason?
		a[j] = buffer[j];
		j++;
	}
	string num1 = numberT();
	string op = operatorT(a[l]);
	string num2 = numberT();

}*/
//
String operatorT(char c){
	if(c == '('){
		return Lparent(buffer[pos]);
	}
	else if(c == '*' || c == '/' || c == '%'){
		if(c == '*')
			return "mul nsw";
		else if(c == '/')
			return "sdiv";
		else
			return "srem";
	}
	else if(c == '+' || c == '-'){
		if(c == '+')
			return "add nsw";
		else
			return "sub nsw";
	}
}

// called for formatting of a semi to make into a newline
semicolonT(){
	printf("\n");
}

// counter for the variable registers
int counter(void){
	global++;
	return global;
}



// made them into checkers nascially to check if they were called as a
// certain token
// do this for lparent and rparent and call expression on this postion? ========== lparent / rparent idea
void plusToken(char buffer[i]){
	buffer[i] = 'p';// makes sure that the token is consumed and has c to check
}
void minusToken(char buffer[i]){
	buffer[i] = 'm';
}
void multToken(char buffer[i]){
	buffer[i] = 'M';
}
void divToken(char buffer[i]){
	buffer[i] = 'D';
}
void modToken(char buffer[i]){
 buffer[i] = 'R';
}

// Emitter
void Emit(root->right, root->left, root->result, int global){
	printf("\%t%d = %s i32 %s, %s", global, root->result, root->left, root->right);
	semicolonT();
}
void callF(int global){
	printf("call void @print_integer(i32 \%t%d)", global);
	semicolonT();
}
// function orderer ====
void statement(void) {
  // at the beginning of the file
  int j = printT();
	// if print isnt there its false
	if(j != 1)
		return;
	root* r = malloc(sizeof(root));
	expression(r);
	// used in project 0 and not complete with 1 and ready to delete yet
  // check if recognized
/*  string exp1 = numberT();
  buffer[pos] = fgetc(c);
  if((isDigit(buffer[pos]))){
  	string opS = operatorT(buffer[pos]);
    // convert from simplec operator to LLVM operator, e.g., '+' "add nsw"
    string exp2 = numberT();
		int l = counter();
    printf("\%t%d = %s i32 %s, %s", l, opS, exp1, exp2);
    // VARNAME = OPNAME i32 exp1, exp2
		// emit LLVM instruction
		semicolonT();
    // emit the call to print
		printf("call void @print_integer(i32 \%t%d)", l);
		semicolonT();
*/
}
program(File *c){
	while(c != EOF)
		statement();
}

#define NUMBER 1
#define PRINT 2

// not needed as we are going to use the strings and llvmir formatting
struct token {
  char *lexeme; // +
  int tokenid; // ascii value of +?
};

// takes a file, returns an array of tokens --- is the main function call for the work above? or a seperate function?
// may need to be a double pointer to be passed through out the complier.
char* lex(File *c){
	// reads file into an array of chars/String
	// do we scan here or what? are we reading in a file for the inputs or is this for test cases?
	File *c;
	c = fopen("SimpleC.c","r");
	if(c == NULL){
		printf("Error in SimpleC\n");
		return 0;
	}
	char buffer[pos] = malloc(sizeof(c));
	while(c != EOF){
		buffer[i] = fgetc(c);
		i++;
	}
	return buffer[];
}

// GOALS:

// for proj 0 need to complete proj 0, complete the file IO for compling.
// for proj 1 need to add precedence and complete function to read Lparent
// for proj 2 need to add allocation for varibles

int main(int argc, char* argv[2])
{
	int i = 0;
	pos = 0;
	printf(PROLOGUE);
  printf("    %%t1 = call i32 @read_integer()\n");
  printf("    call void @print_integer(i32 %%t1)\n");

	File *c;
	c = fopen(argv[2], "r"); // ask if this is correctly implemented because argv is finiky and needs overview
	if(c == NULL)
		return 0;
	char buffer[] = lex(c);
	program(c);
	printf(EPILOGUE);
	return 0;
}
/*
%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque

@stderr = external dso_local global %struct._IO_FILE*, align 8
@.str.1 = private unnamed_addr constant [25 x i8] c"please enter an integer\0A\00", align 1
@.str.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.3 = private unnamed_addr constant [6 x i8] c"scanf\00", align 1
@.str.4 = private unnamed_addr constant [24 x i8] c"no matching characters\0A\00", align 1

declare i32* @__errno_location() #2
declare i32 @__isoc99_scanf(i8*, ...) #1
declare void @perror(i8*) #1
declare void @exit(i32) #3
declare i32 @fprintf(%struct._IO_FILE*, i8*, ...) #1

define i32 @read_integer() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = call i32* @__errno_location() #4
  store i32 0, i32* %3, align 4
  %4 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  %5 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %4, i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str.1, i32 0, i32 0))
  %6 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.2, i32 0, i32 0), i32* %1)
  store i32 %6, i32* %2, align 4
  %7 = load i32, i32* %2, align 4
  %8 = icmp eq i32 %7, 1
  br i1 %8, label %9, label %11

; <label>:9:                                      ; preds = %0
  %10 = load i32, i32* %1, align 4
  ret i32 %10

; <label>:11:                                     ; preds = %0
  %12 = call i32* @__errno_location() #4
  %13 = load i32, i32* %12, align 4
  %14 = icmp ne i32 %13, 0
  br i1 %14, label %15, label %16

; <label>:15:                                     ; preds = %11
  call void @perror(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.3, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

; <label>:16:                                     ; preds = %11
  %17 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  %18 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %17, i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str.4, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable
}

define i32 @main() #0 {
  ; //EMIT CODE FROM YOUR COMPILER HERE
  ret i32 0
}
}
*/
