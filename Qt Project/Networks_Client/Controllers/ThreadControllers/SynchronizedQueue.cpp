#include "SynchronizedQueue.h"

using namespace std;

void SynchronizedQueue::enqueue(shared_ptr<Message> message) {
    _mutex.lock();
    _queue.push_back(message);
    _mutex.unlock();
}

shared_ptr<Message> SynchronizedQueue::dequeue() {
    _mutex.lock();
    shared_ptr<Message> message = _queue.front();
    _queue.pop_front();
    _mutex.unlock();

    return message;
}