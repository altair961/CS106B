/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "Testing/OnlyConnectTests.h"
#include "strlib.h"
#include <cctype>
using namespace std;

string onlyConnectize(string phrase) {
    if(phrase.length() == 0) {
        return "";
    } else {
        string lastChar = "";
        lastChar.push_back(toUpperCase(phrase[phrase.length() - 1]));
        string substr = phrase.substr(0, phrase.length() - 1);
        if (isalpha(lastChar[0])) {
            switch (lastChar[0]) {
            case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
                lastChar = "";
                break;
            default:
                break;
            }
        } else {
            lastChar = "";
        }
        return onlyConnectize(substr) + lastChar;
    }
}

/* * * * * * Test Cases * * * * * */

ADD_TEST("Converts lower-case to upper-case.") {
    EXPECT(onlyConnectize("lowercase") == "LWRCS");
    EXPECT(onlyConnectize("uppercase") == "PPRCS");
}

ADD_TEST("Handles non-letter characters properly.") {
    EXPECT(onlyConnectize("2.718281828459045") == "");
    EXPECT(onlyConnectize("'Hi, Mom!'") == "HMM");
}

ADD_TEST("Handles single-character inputs.") {
    EXPECT(onlyConnectize("A") == "");
    EXPECT(onlyConnectize("+") == "");
    EXPECT(onlyConnectize("Q") == "Q");
}

ADD_TEST("Handles two-word input.") {
    EXPECT(onlyConnectize("Elena Kagan") == "LNKGN");
    EXPECT(onlyConnectize("Antonin Scalia") == "NTNNSCL");
}

ADD_TEST("Handles multiple-word input.") {
    EXPECT(onlyConnectize("For sale: baby shoes, never worn.") == "FRSLBBSHSNVRWRN");
}

ADD_TEST("Handles alphabetic but non-word input.") {
    EXPECT(onlyConnectize("EE 364A") == "");
}

ADD_TEST("Handles multiple-word input with parenthesis.") {
    EXPECT(onlyConnectize("Thank you, next (next)") == "THNKNXTNXT");
}

ADD_TEST("Handles multiple-word input with non-alphabetic symbols.") {
    EXPECT(onlyConnectize("Annie Mae, My Sea Anemone Enemy!") == "NNMMSNMNNM");
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
