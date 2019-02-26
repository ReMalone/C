/* Robert Malone
 * RobertMalone@my.unt.edu
 * Program 3 CSCE 3110
 * October 14th, 2017
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;


//void isOperator(char op){
//   switch(op){
//    case '+': return true;
//     case '-': return true;
//     case '*': return true;
//     case '/': return true;
//     case '(': return true;
//     case ')': return true;
//     case '^': return true;
//    
// }
//}

//grab operators
int isOperator(char op){
  switch(op)
   {
        case '(':
        case ')':
       return 0;
        case '+':
        case '-':
       return 1;
        case '*':
        case '/':
        case '^':
       return 2;
 }
}


//infix to Postfix function
void inToPost(string expr){


  int x;
  int y = 0;

  char Post[50];
  char op;

 stack<char>infix;
 infix.push(' ');


 for(x=0; expr[x]!='\0'; x++)
    {
        op = expr[x];


        if(op == '(')
        {
            infix.push(op);
        }
        else if (op==')')
        {
            while(infix.top()!='(')
            {
                Post[y++]=infix.top();
                infix.pop();
            }
            infix.pop();

        }
        else if (op=='+' || op=='-' || op=='*' || op=='/' || op=='%')
        {
            while (isOperator(op)<=isOperator(infix.top()))
            {
                if(infix.top()!=' ')
                {
                    Post[y++]=infix.top();
                }
                infix.pop();

            }

            infix.push(op);
        }
        else
        {
            Post[y++]=op;
        }

    }
    while(!infix.empty())
    {
            Post[y++]=infix.top();
            infix.pop();
    }
    Post[y]='\0';

    cout<<"Postfix: ";
    for(int x=0; Post[x]!='\0'; x++)
    {
        cout << Post[x];
    }
    cout << endl;
}


int main(){

 string expr;

 cout << "Enter your expression here: ";
 cin >>expr;

 inToPost(expr);


 return 0;
}