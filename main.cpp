//#include <array>
#include <stack>
#include <iostream>
#include <list>
#include <set>

using namespace std;

int main ()
{

    int nums[1000];
    stack <int> stack;
    list <int> list;
    set <int> set;
    int findMe;

    for (int x = 0; x < 999 ; x++ ) {
        nums[x] = x;
    }

    random_shuffle(std::begin(nums), std::end(nums));

    for (int x = 0; x < 999 ; x++ ) {
        stack.push(nums[x]);
        list.push_back(nums[x]);
        set.insert(nums[x]);
    }

    cin >> findMe;

    int stack_count = 1;
    int list_count = 1;
    int set_count = 1;


    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();

    while (stack.top() != findMe) {
        stack.pop();
        stack_count++;
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();

    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Stack:: the number " << findMe << " was found in position " << stack_count << endl;
    cout << "total time = " << elapsedTime.count() << endl;

//    while (list.front() != findMe) {
//        list.pop_back();
//        list_count++;
//    }

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time2 = std::chrono::high_resolution_clock::now();

    for (int x = 0; x < 999; x++) {
        if (list.front() == findMe ) {
            break;
        }
        list_count++;
        list.pop_front();
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time2 = std::chrono::high_resolution_clock::now();

    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "List:: the number " << findMe << " was found in position " << stack_count << endl;
    cout << "total time = " << elapsedTime2.count() << endl;

    std::set<int>::iterator it;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time3 = std::chrono::high_resolution_clock::now();

    for (it=set.begin(); it!=set.end(); ++it) {
        if (*it == findMe) {
            break;
        }
        set_count++;
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time3 = std::chrono::high_resolution_clock::now();

    auto elapsedTime3 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Set:: the number " << findMe << " was found in position " << stack_count << endl;
    cout << "total time = " << elapsedTime3.count() << endl;


    return 0;
}