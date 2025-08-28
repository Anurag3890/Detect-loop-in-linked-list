class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

def detect_loop(head):
    slow=fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
        if slow==fast:return True
    return False

head=Node(10)
second=Node(20)
third=Node(30)
head.next=second
second.next=third
third.next=second  # loop
print("Loop Detected" if detect_loop(head) else "No Loop")
