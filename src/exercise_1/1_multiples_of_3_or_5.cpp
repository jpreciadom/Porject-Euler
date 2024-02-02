#include <iostream>
#include <string>

using namespace std;

int main() {
    string exercise_name = "Multiples of 3 or 5";
    long answer = 0;

    // Your code goes here
    int limit = 1000;
    for (int i = 3; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            answer+=i;
        }
    }
    // Your code ends here

    cout << exercise_name << endl;
    cout << "Answer: " << answer << endl;
    return 0;
}
