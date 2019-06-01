/* File: PlayingFair.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "PlayingFair.h"
#include "Testing/PlayingFairTests.h"
#include "error.h"
using namespace std;

string aSequenceOfOrder(int n) {
    if(n < 0) {
        return "";
    } else if(n == 0) {
        return "A";
    } else {
        return aSequenceOfOrder(n - 1) + bSequenceOfOrder(n - 1);
    }
}

//string aSequenceOfOrder(int n) {
//    string result = "";
//    if(n < 0) {
//        return "";
//    } else if(n == 0) {
//        result.push_back('A');
//    } else if(n == 1) {
//        result.push_back('B');
//    } else {
//        result = aSequenceOfOrder(n - 1) + result;
//    }
//    return result;
//}

//string aSequenceOfOrder(int n) { // 2
//    if(n < 0) {
//        return "";
//    }
//    if(n == 0) { // base case
//        string result = "";
//        result.push_back('A');
//        return result;
//    } else {    // recursive case
//        string result = "";
//        result = aSequenceOfOrder(n - 1) + result;
//        return result;
//    }
//} // A + aSequenceOfOrder(1)

string bSequenceOfOrder(int n) {
    if(n < 0) {
        return "";
    } else if(n == 0) {
        return "B";
    } else {
        return bSequenceOfOrder(n - 1) + aSequenceOfOrder(n - 1);
    }
}






/* * * * * * Tests Below This Point * * * * * */

ADD_TEST("Sequences of order 3 are correct.") {
    /* Some very basic checks. */
    EXPECT(aSequenceOfOrder(3) == "ABBABAAB");
    //EXPECT(bSequenceOfOrder(3) == "BAABABBA");
}

ADD_TEST("Triggers error on negative inputs.") {
    /* The EXPECT_ERROR macro expects the given expression to call error(). Remember that
     * you need to guard against invalid inputs.
     */
    //EXPECT_ERROR(aSequenceOfOrder(-137));
    //EXPECT_ERROR(bSequenceOfOrder(-137));
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

