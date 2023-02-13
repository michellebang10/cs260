For this assignment, I used a linked list structure to create an auto-sort list. 

1) Automatically inserts values depending on some sort of sorting. 
    -Values are sorted from smallest to largest value. 
    -Start comparing from the beginning (as we only add one element at a time). If element is bigger than first value, it moves on to the next position and so on until it is smaller than or equal to the value at that position. 
1.1) Removes values given a specific value to search for. 
    -Compares values at each position, if given value equals the value at a position, that value is removed and the list is connected again. 
    -If the list empty, does not delete any value... returns -2... 
2) Efficiently searches for elements.
    -at() function that takes in index/position of list and returns value at that position. 
    -if nothing exists at position, returns -1...

Testing!!
-Please look into test_auto_sort.cpp for all the tests I did :D
Expected outputs:
my_auto_sort.to_string(): 
my_auto_sort.at(1): -1
my_auto_sort.to_string(): 1, 
my_auto_sort.at(0): -1
my_auto_sort.to_string(): 1, 5, 
my_auto_sort.at(2): 5
my_auto_sort.to_string(): 1, 3, 5, 
my_auto_sort.at(2): 3
my_auto_sort.to_string(): 0, 1, 3, 5, 
my_auto_sort.at(1): 0
my_auto_sort.to_string(): 0, 0, 1, 3, 5, 
my_auto_sort.at(2): 0
my_auto_sort.to_string(): 0, 0, 1, 3, 3, 5, 
my_auto_sort.at(3): 1
my_auto_sort.at(4): 3
my_auto_sort.to_string(): 0, 0, 1, 3, 5, 
my_auto_sort.at(4): 3
my_auto_sort.to_string(): 0, 0, 1, 3, 
my_auto_sort.at(5): -1
my_auto_sort.to_string(): 0, 1, 3, 
my_auto_sort.at(1): 0
my_auto_sort.to_string(): 1, 3, 
my_auto_sort.at(1): 1
my_auto_sort.to_string(): 3, 
my_auto_sort.to_string(): 
my_auto_sort.to_string(): 

Algorithmic complexity:
add(), remove(), at(), find_previous_node(), to_string() all O(n) complexity. Starts from beginning and walks through a straight line up to n. 

Auto_sort() has O(1) complexity. Length of list does not matter, the front is always nullptr. 