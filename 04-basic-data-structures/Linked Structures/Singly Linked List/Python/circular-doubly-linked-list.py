class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None


class CircularDoublyLinkedList:
    def __init__(self):
        self.head=None

    def append(self,data):
        new_node=Node(data)
        if self.head is None:
            self.head=new_node
            self.head.next=self.head
            self.head.prev=self.head
            return
        
        last_node=self.head.prev

        last_node.next=new_node
        new_node.prev=last_node

        new_node.next=self.head
        self.head.prev = new_node