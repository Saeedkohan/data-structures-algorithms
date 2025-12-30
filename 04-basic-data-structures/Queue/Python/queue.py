class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def is_empty(self):
        return self.front is None

    def enqueue(self, data):
        node = Node(data)
        if self.is_empty():
            self.front = node
            self.rear = node
            return
        self.rear.next = node
        self.rear = node
        return

    def dequeue(self):
        if self.is_empty():
            return
        data = self.front.data
        self.front = self.front.next
        return data

    def peek(self):
        if self.is_empty():
            return
        return self.front.data
 