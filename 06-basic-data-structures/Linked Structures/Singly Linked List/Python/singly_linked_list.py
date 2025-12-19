class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class SinglyLinkedList:
    def __init__(self):
        self.head=None

    def lenght(self):
        count=0
        current=self.head

        while current:
            current+=1
            current=current.next
        return count
    
    def prepend(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node
    def delete_head(self):
        if self.head is None:
            print("List is empty, cannot delete.")
            return
    
        self.head = self.head.next

    def append(self,data):
        new_node=Node(data)
        if not self.head:
            self.head=new_node
            return
        
        current=self.head
        while current.next :
            current=current.next

        current.next=new_node

    def insert_at_index(self,data,index):
        if index==0:
            self.prepend(data)
            return
        new_node=Node(data)
        current=self.head
        count=0

        while current and  count <index-1:
            current=current.next
            count+=1
        
        if current is None:
            print("Error: Index out of bounds.")
            return
        new_node.next=current.next
        current.next=new_node




    def remove(self, data):
        prev=None
        current=self.head
        while current and current.data!=data:
            prev=current
            current=current.next
        if current is None:
            return
        if prev is None:
            self.head=current.next
        else:
            prev.next=current.next
        
    def display(self):
        
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
        
    def search(self,data):
        current = self.head
        while current:
            if current.data == data:
                return True  
            current = current.next
        return False 
        
head=Node(10)
head.next=Node(20)
head.next.next=Node(30)
head.next.next.next=Node(40)


temp=head
while temp is not None:
    print(temp.data, end=" ")
    temp=temp.next
# ////////////////////////////////////
print("\n","////////////////////////////////////")
ll = SinglyLinkedList()
ll.append(10)
ll.append(20)
ll.append(30)
ll.display()   
ll.remove(20)
ll.display()   