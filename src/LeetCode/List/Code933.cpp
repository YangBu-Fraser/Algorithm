/**
 * 933. Number of Recent Calls
 * 
 * You have a `RecentCounter` class which counts the number of recent requests within a certain time frame.
 * 
 */

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while (t - q.front()>3000)
        {
            q.pop();
        }
        return q.size();
    }
};
