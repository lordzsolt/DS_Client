#include "../../Models/MessageModels/Message.h"

#include <mutex>
#include <deque>
#include <memory>

class SynchronizedQueue {
public:

    /**
    * WARNING: Enqueuing null_ptr leads to undefined behaviour.
    */
    void enqueue(std::shared_ptr<Message> message);

    std::shared_ptr<Message> dequeue();

private:
    std::deque<std::shared_ptr<Message>> _queue;
    std::mutex _mutex;
};