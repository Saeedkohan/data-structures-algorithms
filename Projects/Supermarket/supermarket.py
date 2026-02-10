import random

class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        return None

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)


class Customer:
    def __init__(self, arrival_time, service_time):
        self.arrival_time = arrival_time
        self.service_time = service_time
        self.remaining_time = service_time


class CheckoutLine:
    def __init__(self):
        self.queue = Queue()
        self.current_customer = None
        self.max_queue_length = 0
        self.served_customers = 0
        self.total_waiting_time = 0

    def add_customer(self, customer):
        self.queue.enqueue(customer)
        self.max_queue_length = max(self.max_queue_length, self.queue.size())

    def process_minute(self, current_time):
        if self.current_customer is None and not self.queue.is_empty():
            self.current_customer = self.queue.dequeue()
            wait_time = current_time - self.current_customer.arrival_time
            self.total_waiting_time += wait_time

        if self.current_customer:
            self.current_customer.remaining_time -= 1
            if self.current_customer.remaining_time == 0:
                self.served_customers += 1
                self.current_customer = None


def simulate_checkout(num_checkouts,simulation_time,arrival_probability,service_time_range):

    checkouts = [CheckoutLine() for _ in range(num_checkouts)]
    total_customers = 0

    for minute in range(simulation_time):


        if random.random() < arrival_probability:
            service_time = random.randint(service_time_range[0],service_time_range[1])
            customer = Customer(minute, service_time)
            total_customers += 1


            shortest_line = min(checkouts, key=lambda x: x.queue.size())
            shortest_line.add_customer(customer)

        for checkout in checkouts:
            checkout.process_minute(minute)

    print("\nSimulation Report")

    print(f"Total customers arrived: {total_customers}")

    total_served = sum(c.served_customers for c in checkouts)
    print(f"Total customers served: {total_served}")

    for i, c in enumerate(checkouts):
        avg_wait = (c.total_waiting_time / c.served_customers) if c.served_customers else 0
        print(f"\nCheckout Line {i + 1}:")
        print(f"Customers served: {c.served_customers}")
        print(f"Average waiting time: {avg_wait:.2f}")
        print(f"Maximum queue length: {c.max_queue_length}")



num_checkouts = int(input("Enter number of checkout lines: "))
simulation_time = int(input("Enter simulation time (minutes): "))
arrival_probability = float(input("Enter customer arrival probability (0 to 1): "))
min_service = int(input("Enter minimum service time: "))
max_service = int(input("Enter maximum service time: "))
simulate_checkout(num_checkouts,simulation_time,arrival_probability,(min_service, max_service))