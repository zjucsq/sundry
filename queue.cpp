

condition_varaible cv1, cv2;


class queue {
    mutex mx;

    void push(int val) {
        cv1.wait(mx, !isfull());
        queue.push(val);
        cv2.notify_one();
    }


    int pop() {
        cv2.wait(mx, !isempty());
        queue.pop();
        cv1.notify_one();
    }
}