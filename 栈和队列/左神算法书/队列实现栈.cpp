#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1, q2;

public:
    void push(int value) {
        q1.push(value);
    }

    int pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedValue = q1.front();
        q1.pop();

        // Swap q1 and q2 to keep q1 as the primary queue for pushing.
        std::swap(q1, q2);

        return poppedValue;
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topValue = q1.front();
        q2.push(topValue);
        q1.pop();

        // Swap q1 and q2 to keep q1 as the primary queue for pushing.
        std::swap(q1, q2);

        return topValue;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.top() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.top() << std::endl;

    return 0;
}
