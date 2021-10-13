/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
    
    private:
    int thread_num;
    string hostname;
    queue<string> q;
    unordered_set<string> seen;
    int working = 0;
    bool done;
    mutex m;
    condition_variable cv;
    
    string extractHostName(const string& url){
        int start = url.find('/') + 2;
        int end =  url.find('/', start);
        if(end == string::npos) 
            return url.substr(start);
        return url.substr(start, end - start);
    }
    vector<thread> workers;
    
    // this a worker thread that will be doing tasks.
    void startWorker(HtmlParser* parser){
        while (done == false) {
            unique_lock<mutex> ul(m);
            
            cv.wait(ul, [&]() {
                return !q.empty() || done;
            });
            
            if (done) {
                return;
            }
            
            string item = q.front();
            q.pop();
            working++;
            
            ul.unlock();
            vector<string> urls = parser->getUrls(item);
            ul.lock();
            
            for (const string& url : urls) {
                if (seen.count(url) > 0 || (extractHostName(url) != hostname)) continue;
                seen.insert(url);
                q.push(url);
            }
            working--;
            
            if (q.empty() && working == 0) {
                done = true;
            }
            
            cv.notify_all();
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        // get the hostname for this url.
        // mark it as seen.
        hostname = extractHostName(startUrl);
        seen.insert(startUrl);
        done = false;
        // get number of supported threads
        thread_num = thread::hardware_concurrency();
        // push the first task to do.
        q.push(startUrl);
        
        // start bunch of worker threads.
        for(int i = 0; i < thread_num; i++){
            workers.emplace_back(&Solution::startWorker, this, &htmlParser);
        }
        
        // join those threads so that crawl is a blocking call 
        for(auto &t : workers){
            t.join();
        }
        // return every unique processed string
        return vector<string>(seen.begin(), seen.end());
    }
};
