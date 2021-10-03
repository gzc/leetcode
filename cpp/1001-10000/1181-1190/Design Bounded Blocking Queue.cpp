// copy form https://leetcode.com/problems/design-bounded-blocking-queue/discuss/394855/C%2B%2B-Mutex-and-Condition-Variable-w-Predicate
class BoundedBlockingQueue {
private:
    mutex m_queue_mutex;
    condition_variable m_queue_changed;
    queue<int> m_queue; // m_queue_mutex
    int m_capacity; // m_queue_mutex
    
public:
    BoundedBlockingQueue(int capacity) {
        // Initialize queue and capacity
        m_capacity = capacity;
    }
    
    void enqueue(int element) {
        // Add to front of queue
        // If full, block caller until enqueue succeeds
        {
            unique_lock<mutex> lk(m_queue_mutex);

            // Grab the lock with queue size < capacity
            m_queue_changed.wait(lk, [this] {return m_queue.size() < m_capacity;});

            m_queue.push(element);
        }
        
        // Avoid waiters waking up and immediately blocking by unlocking
        // before notifying
        m_queue_changed.notify_one();
    }
    
    int dequeue() {
        // Remove from front of queue
        // If empty, block caller until dequeue succeeds
        int ret;
        {
            unique_lock<mutex> lk(m_queue_mutex);

            // Grab the lock with queue size > 0
            m_queue_changed.wait(lk, [this] {return m_queue.size() > 0;});

            ret = m_queue.front();
            m_queue.pop();
        }
        m_queue_changed.notify_one();
        
        return ret;
    }
    
    int size() {
        // returns size of queue
        unique_lock<mutex> lk(m_queue_mutex);
        return m_queue.size();
    }
};
