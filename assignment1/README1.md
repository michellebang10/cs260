1) Some way of representing marbles (what makes up a marble in this program?)

A) In this program, marbles are represented by integers.

2) A way to add new marbles into the bag (how do we interact with marbles and add them into the bag?)

A) The bag is represented by a C++ array. Marbles are added into the bag by being added into an array. 

3) A way to remove a marble out of the bag (perhaps a random marble taken out of the bag?)

A) For randomly chosen marble, indexing will be used to remove the marble at the indexed position. For a specifically chosen marble, we would find the index that corresponds to that marble and remove it. 

4) A few ways that we could use to show that our implementation should be working correctly (tests)

A) 

    -Empty bag

        -Remove a marble

            want to show that there is a error
        -Add a marble

            Remove the marble and show it's the same one that was added in.

    -Start with bag with n marbles

        -Remove a marble

            Show that the marble removed is no longer there

        -Add a marble

            Remove the marble and show that it’s the same one that was added in

        -Keep removing marbles until empty bag

            Show that after n removals, the bag is empty

Notes:

-This is my first time using C++, so I've been looking at a lot of random online resources to get help. Here's some I've looked at:

1) https://www.w3schools.com/cpp/cpp_arrays.asp 

2) https://cplusplus.com/forum/beginner/152125/ 

3) https://linuxhint.com/cpp-check-array-empty/#:~:text=Use%20array%3A%3Aempty(),if%20the%20array%20is%20empty%3A&text=Instead%2C%20it%20examines%20if%20an,returns%200%20which%20means%20false. 

4) https://stackoverflow.com/questions/315948/c-catching-all-exceptions

5) https://www.w3schools.com/cpp/cpp_for_loop.asp

6) https://www.w3schools.com/cpp/cpp_conditions_elseif.asp 

7) https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones#:~:text=In%20C%2B%2B11%2C%20use,end(array)%2C%203)%3B 

8) https://www.geeksforgeeks.org/delete-an-element-from-array-using-two-traversals-and-one-traversal/

-It's been pretty hard to get used to the basic C++ rules :( Even though my program may not seem perfect, I did spend a lot of time looking at different online material! 
