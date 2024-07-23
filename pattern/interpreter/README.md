## Interpreter Design Pattern 

- Interpreter design pattern is used to design a interpreter for a language defined on top of a recursive grammar. 
- Creating class hierarchies on the grammar and provide the interface for the execute method. 

- Example : Let's design a simple grammar for a expression interpreter.

```
<expression> ::= <term> (('+'|'-') <term>)*
<term> ::= <factor> (('*'|'/') <factor>)*
<factor> ::= <number> | <variable> | '(' <expression> ')'
<number> ::= [0-9]+ 
<variable> ::= [a-zA-Z][a-zA-Z0-9]*  
```

- For example: 

```
3 + (2 * 12 / 6 + 1) * (3 - 9)
Tokenize: <3 , + , ( , 2 , * , 12 , / , 6 , + , 1 , ) , * , ( , 3 , - , 9 , )>  
Parse: 
		<term> -> <factor> -> 3 
		+ 
		<term> -> <factor> -> (<expression>) 
						            -> 2*12/6+1
						            -> ...
		...
 ```

- So first build a tokenizer which breaks the expression into tokens.
- Follow the grammar rule and build a interpreted AST. 
- Uses `Composite` structural pattern to build the AST.