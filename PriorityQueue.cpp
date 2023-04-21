#include "PriorityQueue.h"
#include <iostream>
#include <string>
#include <cmath>

using std::cout;

PriorityQueue::PriorityQueue() = default;

PriorityQueue::~PriorityQueue() {
    clear();
}

void PriorityQueue::shift_up(int pos) {
    if (elements.size() > 1) {
        int i = pos;
        int parent = (i - 1) / 2;
        while (elements[i] > elements[parent] || i > 0) {
            std::swap(elements[i], elements[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}

void PriorityQueue::shift_down(int pos)
{
    int i = pos;
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < elements.size() && elements[i] < elements[left])
            largest = left;
        if (right < elements.size() && elements[largest] < elements[right])
            largest = right;
        
        if (largest == i)
            return;
        std::swap(elements[i], elements[largest]);
        i = largest;

    }
}

void PriorityQueue::push(int value) {
    elements.push_back(value);
    shift_up(elements.size() - 1);
}

void PriorityQueue::pop()
{
    if (elements.size() > 0)
    {
        elements[0] = elements[elements.size() - 1];
        elements.resize(elements.size() - 1);
        shift_down(0);
    }
}

int PriorityQueue::top()
{
    return elements[0];
}

void PriorityQueue::clear()
{
    elements.resize(0);
}

void PriorityQueue::printAsArray()
{
    for (int i = 0; i < elements.size(); i++)
        cout << elements[i] << " ";
    cout << std::endl;
}

void PriorityQueue::printAsTree(int i, int level)
{
    if (i >= elements.size()) {
        return;
    }
    printAsTree(2 * i + 2, level + 1);
    cout << std::string(4 * level, ' ') << elements[i] << std::endl;
    printAsTree(2 * i + 1, level + 1);
}

