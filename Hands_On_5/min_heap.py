class BinaryHeap:
    def __init__(self, capacity, cmp_func):
        self.capacity = capacity
        self.size = 0
        self.arr = [None] * capacity
        self.cmp = cmp_func 
        print(f"Initialized heap with capacity {capacity}")

    def parent(self, i):
        return (i - 1) >> 1

    def left(self, i):
        return (i << 1) | 1

    def right(self, i):
        return (i + 1) << 1

    def swap(self, i, j):
        self.arr[i], self.arr[j] = self.arr[j], self.arr[i]

    def heapify(self, i):
        smallest = i
        left = self.left(i)
        right = self.right(i)

        if left < self.size and self.cmp(self.arr[left], self.arr[smallest]) < 0:
            smallest = left
        if right < self.size and self.cmp(self.arr[right], self.arr[smallest]) < 0:
            smallest = right

        if smallest != i:
            self.swap(i, smallest)
            print(f"Heap after swapping index {i} with index {smallest}: {self.arr[:self.size]}")  # Print state after swap
            self.heapify(smallest)

    def build_min_heap(self, array):
        self.size = len(array)
        self.arr = array
        for i in range((self.size // 2) - 1, -1, -1):
            self.heapify(i)
        print(f"Min heap built: {self.arr[:self.size]}")

    def extract_min(self):
        if self.size <= 0:
            print("Heap is empty, cannot extract min")
            return None
        if self.size == 1:
            self.size -= 1
            return self.arr[0]

        root = self.arr[0]
        self.arr[0] = self.arr[self.size - 1]
        self.size -= 1
        self.heapify(0)
        print(f"Extracted min value: {root}")
        print(f"New heap after min value extracted: {self.arr[:self.size]}")
        return root

    def print_heap(self):
        print(f"Current heap: {self.arr[:self.size]}")

def int_compare(x, y):
    return x - y

if __name__ == "__main__":
    user_input = input("Enter the elements of the array separated by spaces: ")
    array = list(map(int, user_input.split()))

    heap = BinaryHeap(len(array), int_compare)
    heap.build_min_heap(array)
    min_value = heap.extract_min()
    print(f"Final heap after extracting min: {heap.arr[:heap.size]}")
