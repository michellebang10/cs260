1. Create a design before you begin to code that describes or shows how we can store data in a hash table and what kind of problem we could solve with a hash table.

Idea: we take in a string of values. Starting at a = 1, we add up the letters of the string together depending on its place on the alphabet. 

2. Create some tests (at least one per piece of functionality) before you begin coding that you want your hashtable to pass before you start coding.

3. Create a hashtable that resolves collisions by simply overwriting the old value with the new value, including at least:
- Describe the way that you decide on hashing a value
(this can be simple or complex based on how interesting you find the topic)
- An insert function that places the value at the appropriate location based on its hash value
- A contains function that returns whether the value is already in the hashtable
- (optional) A delete function that removes a value based on its hash and then returns that value…

4. Then create a smarter hashtable (double hashing or chaining) including at least the same functions as the simple hashtable

5. Compare some information relating to collisions (frequency) and their effect on complexity (of insert and contains methods)