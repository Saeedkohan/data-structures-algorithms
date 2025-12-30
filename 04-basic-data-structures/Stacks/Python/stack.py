class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def push(self, data):
        node = Node(data)
        node.next = self.top
        self.top = node
        self.size += 1

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        else:
            data = self.top.data
            self.top = self.top.next
            self.size -= 1
            return data

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        else:
            return self.top.data

    def size(self):
        return self.size


def is_balanced(string):
    stack = Stack()
    dict = {
        "]": "[",
        "}": "{",
        ")": "(",
    }
    for i in string:
        if i in dict.values():
            stack.push(i)
        elif i in dict.keys() and stack.pop() !=dict[i]:
            return False


input = input()
is_balanced(input)
