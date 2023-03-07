1. Create a design before you begin to code that describes or shows how we can store data in a hash table and what kind of problem we could solve with a hash table.

Idea: we take in a string of values. Starting at a = 1, we add up the letters of the string together depending on its place on the alphabet. Then we divide that value by the capacity of the table. The remainder of that operation is the place in the table that value goes. 

Hash tables in general take in a key, perform a hash function, and stores that key in a value corresponding to the hash function's output in a table. Hash tables can be useful when you want to store, retrieve and delete data efficiently. Real life examples include phone books, library books, and dictionaries. 

2. Create some tests (at least one per piece of functionality) before you begin coding that you want your hashtable to pass before you start coding.

- For insert function: Make a print statement on whether or not was added. Use a search function to see if value is in the list. Print the entire table and see if value was added into appropriate spot in the table.

- For a search function: Test a value in the table and test a value not in the table. (Could test a value that exceed the bounds of the capacity... but hard to choose a string that will actually have a value outside bounds...)

- For a delete function: Remove a value in the table. Have a print statement to see if removal was successful. Use a search function to show that value is no longer in the table. Remove a value that is not in the table. Have a print statement to see if the removal was unsuccessful. 

3. Create a hashtable that resolves collisions by simply overwriting the old value with the new value, including at least:
- Describe the way that you decide on hashing a value
    As said before, we take in a string of values. Starting at a = 1, we add up the letters of the string together depending on its place on the alphabet. Then we divide that value by the capacity of the table. The remainder of that operation is the place in the table that value goes. 

(this can be simple or complex based on how interesting you find the topic)
- An insert function that places the value at the appropriate location based on its hash value
- A contains function that returns whether the value is already in the hashtable
- (optional) A delete function that removes a value based on its hash and then returns that value…

Function for the above can be found in chain_hash.cpp and hash_table.cpp :DD

4. Then create a smarter hashtable (double hashing or chaining) including at least the same functions as the simple hashtable

I used a chain hashing for a smarter hashtable. In chain hashing, multiple elements with the same value can be stored using a linked list. You can see my work for this implementation in chain_hash.h, chain_hash.cpp, and chain_driver.cpp. 

5. Compare some information relating to collisions (frequency) and their effect on complexity (of insert and contains methods)

For collisions, the frequency of collisions are the same in both methods. A collision is counted anytime more than one key is mapped to the same value. However, the method of taking care of the collisions are different: for simple hashing, the old key is replaced by the new key... in chain hashing, the new key is added to the linked list with the old key(s)... 

For time complexity.... 
o(1) for insert, search, delete in simple hash--we go to a specific location in the table for these functions (length doesn't matter)
o(1 + n/m) for search, insert, and delete in chain hash (n is number of elements, m is size of table)--since this applied a linked-list structure, we have to go through all the elements in the linked-list (can't go to specific location).

6. Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).

For simple hash outputs: 

ht.getCapacity(): 16

hash("aaa"): 3

hash("ace"): 9

hash("joe"): 14

hash("bob"): 3

hash("jj"): 4

insert("aaa"): no collision detected

search("aaa"): "aaa"

search("ab"): "aaa"

search("ace"): ""

search("jj"): ""

insert("ab"): collision detected

search("ab"): "ab"

remove("jj"): removal failed

insert("jj"): insert failed

remove("jj"): removal succeeded

remove("aaa"): removal failed

remove("ab"): removal succeeded

search("ab"): ""

ht2.getFullness(): -1

search("joe"): "joe"

ht.getSize(): 4

ht.getCapacity(): 16

ht.getFullness(): 0.25

ht.getCollisionCount(): 2

[(3, bob)(8, cat)(9, ace)(14, joe)]

Numerators on possibly useful statistics:

	insert count: 8

	size: 4

Denominator on possibly useful statistics:

	collision count: 2

Possibly useful statistics:

	size / collision count: 2

	insert count / collision count: 4

end of program, have a nice day!

For chain hash outputs:

ht.getCapacity(): 16

hash("aaa"): 3

hash("ace"): 9

hash("joe"): 14

hash("bob"): 3

insert("aaa"): insert succeeded; no collision

we have: aaa in our hash

this value is not in our hash

remove("ab"): removal failed

remove("aaa"): removal succeeded

search("joe"): "joe"

insert("ab"): insert succeeded; collision 

search("ab"): "ab"

ht.getSize(): 6

ht.getCapacity(): 16

ht.getFullness(): 0.375

ht.getCollisionCount(): 2

0

1

2

3 --> aaa --> bob --> ab

4

5

6

7

8 --> cat

9 --> ace

10

11

12

13

14 --> joe

15

Numerators on possibly useful statistics:

	insert count: 7

	size: 6

Denominator on possibly useful statistics:

	collision count: 2

Possibly useful statistics:

	size / collision count: 3

	insert count / collision count: 3.5

end of program, have a nice day!