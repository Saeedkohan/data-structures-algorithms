class Array:
    def __init__(self, size,type=int):
        self.size = size
        self.type = type
        self.data = [None] * size

        def _cheack_index(index):
            if index < 0 or index >= size:
                raise IndexError("index out of range")


        def __len__(self):
            return self.size

        def __getitem__(self, index):
            _cheack_index(index)
            return self.data[index]
        def __setitem__(self, index, value):
            _cheack_index(index)
            if not isinstance(value, self.type):
                raise TypeError("value must be of type '%s'" % self.type)
            self.data[index] = value

        def __iter__(self):
            for item in self.data:
                yield item

        def __repr__(self):
            return str(self.data)

        def insert(self, index, value):  # physical size ≥ logical size + 1
            _cheack_index(index)
            if not isinstance(value, self.type):
                raise TypeError("value must be of type '%s'" % self.type)
            for i in range(self.size-1,index,-1):
                self.data[i] = self.data[i-1]

            self.data[index] = value
        
        def delete(self, index):
            _cheack_index(index)
            for i in range(index,self.size-1):
                self.data[i] = self.data[i+1]
            self.data[self.size-1] = None


