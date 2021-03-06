/* File: Sandpile.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "Sandpiles.h"
#include "Testing/SandpileTests.h"
using namespace std;

void dropSandOn(Grid<int>& world, int row, int col) {
    if(!world.inBounds(row, col)) {
        return;
    }

    if(world[row][col] < 3) { // base case
        world[row][col] ++;
    } else if(world[row][col] == 3) {
        world[row][col] ++;
        dropSandOn(world, row, col);
    } else { // recoursive case
        world[row][col] = 0;
        dropSandOn(world, row+1, col);
        dropSandOn(world, row, col+1);
        dropSandOn(world, row-1, col);
        dropSandOn(world, row, col-1);
    }
}

/* * * * * * Tests Below This Point * * * * * */

ADD_TEST("Dropping into an empty cell only changes that cell.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 3, 3, 3 },
        { 3, 0, 3 },
        { 3, 3, 3 }
    };
    Grid<int> after = {
        { 3, 3, 3 },
        { 3, 1, 3 },
        { 3, 3, 3 }
    };

    dropSandOn(before, 1, 1);
    EXPECT(before == after); // The above call changes 'before.'
}

ADD_TEST("Non-chaining topples work.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 0, 0, 0 },
        { 1, 3, 1 },
        { 0, 2, 0 }
    };
    Grid<int> after = {
        { 0, 1, 0 },
        { 2, 0, 2 },
        { 0, 3, 0 }
    };

    dropSandOn(before, 1, 1);
    EXPECT(before == after); // The above call changes 'before.'
}

ADD_TEST("Two topples chain.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 0, 0, 0, 0 },
        { 0, 3, 3, 0 },
        { 0, 0, 0, 0 }
    };
    Grid<int> after = {
        { 0, 1, 1, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 1, 0 }
    };

    dropSandOn(before, 1, 1);
    EXPECT(before == after); // The above call changes 'before.'
}

ADD_TEST("Dropping out of vector bounds.") {
    Grid<int> before = {
        { 0, 0, 0 },
        { 1, 3, 1 },
        { 0, 2, 0 }
    };
    Grid<int> after = {
        { 0, 0, 0 },
        { 1, 3, 1 },
        { 0, 2, 0 }
    };

    dropSandOn(before, 3, 3);
    EXPECT(before == after); // The above call doesn't change 'before.'
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
