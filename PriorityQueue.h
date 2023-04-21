#include <vector>

using std::vector;

class PriorityQueue {
private:
    vector<int> elements;
    void shift_up(int pos);
    void shift_down(int pos);

public:
    PriorityQueue();
    ~PriorityQueue();

    void push(int value);

    void pop();

    int top();

    void clear();

    void printAsArray();

    void printAsTree(int i, int level);
};
