1) Some way of representing marbles (what makes up a marble in this program?)

A) In this program, marbles are represented by integers.

CODE) int bagfive[5] = {1, 2, 3, 4, 5};

2) A way to add new marbles into the bag (how do we interact with marbles and add them into the bag?)

A) The bag is represented by a C++ array. Marbles are added into the bag by being added into an array. 

CODE)
    bagfive[5] = 6;

    int n_new = sizeof(bagfive) / sizeof(int);

    cout << "the new array has a length of size: ";

    cout << n_new << endl;

3) A way to remove a marble out of the bag (perhaps a random marble taken out of the bag?)

A) For randomly chosen marble, indexing will be used to remove the marble at the indexed position. For a specifically chosen marble, we would find the index that corresponds to that marble and remove it. 

CODE) 
    cout << "this was the marble in index 3 before: ";

    cout << bagfive[3] << endl;

    // 4 should be printed out

    for(int i = 0; i < 5; i++) {

        if (i < 3) {

            bagfive[i] = bagfive[i];

        } else {

            bagfive[i] = bagfive[i + 1];

        }

    }

    bagfive[5] = NULL;

    int n_new_new = sizeof(bagfive) / sizeof(int);

    cout << "length of new array with 1 element removed: ";

    cout << n_new_new << endl;

4) A few ways that we could use to show that our implementation should be working correctly (tests)

A) 

    -Empty bag

        -Show that the bag is empty

            if (bagemp[0] == NULL){
                cout << "bag is empty!" << endl;
            }

        -Add a marble

            bagemp[0] = 0;
            cout << "seeing if 0 was added to array" << endl;
            cout << bagemp[0] << endl;

    -Start with bag with n marbles

        -Remove a marble

            Show that the marble removed is no longer there

             // removing one marble in the middle (index 3, value 4)

            cout << "this was the marble in index 3 before: ";
            cout << bagfive[3] << endl;
            // 4 should be printed out

            for(int i = 0; i < 5; i++) {
                if (i < 3) {
                bagfive[i] = bagfive[i];
            } else {
                bagfive[i] = bagfive[i + 1];
            }
        }

            bagfive[5] = NULL;

            int n_new_new = sizeof(bagfive) / sizeof(int);
            cout << "length of new array with 1 element removed: ";
            cout << n_new_new << endl;

            cout << "checking if marble was removed" << endl;
            for(int i = 0; i < n_new_new; i++) {
            cout << bagfive[i] << endl;
        }
        // 1, 2, 3, 5, 6 should be printed out

        -Add a marble

            Show that it’s the same one that was added in

            // add one marble at the end
            bagfive[5] = 6;
            int n_new = sizeof(bagfive) / sizeof(int);
            cout << "the new array has a length of size: ";
            cout << n_new << endl;

            cout << "checking new marble was added" << endl;
            for(int i = 0; i < n_new; i++) {
                cout << bagfive[i] << endl;
            }
            //  1, 2, 3, 4, 5, 6 should be printed out in separate lines

            cout << "this marble was added in: ";
            cout << bagfive[5] << endl;

        -Keep removing marbles until empty bag

            Show that after n removals, the bag is empty

            // keep removing the elements in bagfive until empty

            for(int i = 0; i < n_new_new; i++) {
            bagfive[i] = NULL;
            }

            // checking that bag is empty
            if (bagemp[0] == NULL){
                cout << "bag is empty!" << endl;
            }
            // the above should be printed out

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
