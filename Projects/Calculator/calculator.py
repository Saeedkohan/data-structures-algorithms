import math

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        raise IndexError("pop from empty stack")

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        return None

    def is_empty(self):
        return len(self.items) == 0


class Calculator:
    precedence = {
        '+': 1,
        '-': 1,
        '*': 2,
        '/': 2,
        '^': 3
    }

    functions = {
        'sin': lambda x: math.sin(math.radians(x)),
        'cos': lambda x: math.cos(math.radians(x)),
        'tan': lambda x: math.tan(math.radians(x)),
        'arcsin': lambda x: math.degrees(math.asin(x)),
        'arccos': lambda x: math.degrees(math.acos(x)),
        'arctan': lambda x: math.degrees(math.atan(x)),
        'ln': lambda x: math.log(x),
        'log': lambda x: math.log10(x),
        'exp': lambda x: math.exp(x),
        'sqrt': lambda x: math.sqrt(x),
        'abs': lambda x: abs(x)
    }

    def is_number(self, s):
        try:
            float(s)
            return True
        except ValueError:
            return False

    def apply_operator(self, op, a, b):
        if op == '+': return a + b
        if op == '-': return a - b
        if op == '*': return a * b
        if op == '/': return a / b
        if op == '^': return a ** b

    def tokenize(self, expression):
        tokens = []
        i = 0
        while i < len(expression):
            if expression[i].isspace():
                i += 1
                continue
            if expression[i] in '+-*/^()':
                tokens.append(expression[i])
                i += 1
            elif expression[i].isalpha():
                func = ''
                while i < len(expression) and expression[i].isalpha():
                    func += expression[i]
                    i += 1
                tokens.append(func)
            else:
                num = ''
                while i < len(expression) and (expression[i].isdigit() or expression[i] == '.'):
                    num += expression[i]
                    i += 1
                tokens.append(num)
        return tokens

    def infix_to_postfix(self, tokens):
        output = []
        stack = Stack()
        for token in tokens:
            if self.is_number(token):
                output.append(token)
            elif token in self.functions:
                stack.push(token)
            elif token in self.precedence:
                while not stack.is_empty() and stack.peek() in self.precedence:
                    top = stack.peek()
                    if (self.precedence[token] <= self.precedence[top] and token != '^') or \
                       (self.precedence[token] < self.precedence[top] and token == '^'):
                        output.append(stack.pop())
                    else:
                        break
                stack.push(token)
            elif token == '(':
                stack.push(token)
            elif token == ')':
                while not stack.is_empty() and stack.peek() != '(':
                    output.append(stack.pop())
                stack.pop()
                if not stack.is_empty() and stack.peek() in self.functions:
                    output.append(stack.pop())
        while not stack.is_empty():
            output.append(stack.pop())
        return output

    def evaluate_postfix(self, tokens):
        stack = Stack()
        for token in tokens:
            if self.is_number(token):
                stack.push(float(token))
            elif token in self.functions:
                a = stack.pop()
                stack.push(self.functions[token](a))
            else:
                b = stack.pop()
                a = stack.pop()
                stack.push(self.apply_operator(token, a, b))
        return stack.pop()

    def calculate(self, expression):
        tokens = self.tokenize(expression)
        postfix = self.infix_to_postfix(tokens)
        return self.evaluate_postfix(postfix)



calc = Calculator()
expr = input("Enter expression: ")
try:
    result = calc.calculate(expr)
    print("Result:", result)
except Exception as e:
    print("Error:", e)
