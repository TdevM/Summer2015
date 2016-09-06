class QueueusingStacks {
    stack<T> s1;
    stack<T> s2;

    void enqueue(const T & el) {
        s1.push(el);
    }
    void dequeue() {
        while (!s1.isEmpty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.isEmpty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
}
