class AuthenticationManager {
    int ttl = 0;
    unordered_map<string, int> tokens;
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        auto it = tokens.find(tokenId);
        if (it == tokens.end()) {
            return;
        }
        if (it->second <= currentTime) {
            tokens.erase(it);
        } else {
            it->second = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto it = tokens.begin();
        while (it != tokens.end()) {
            if (it->second <= currentTime) {
                it = tokens.erase(it);
            } else {
                it++;
            }
        }
        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
