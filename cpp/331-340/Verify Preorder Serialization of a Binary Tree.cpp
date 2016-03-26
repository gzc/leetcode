class Solution {
    
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    
    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
    
public:
    bool isValidSerialization(string preorder) {
        
        vector<string> myres = split(preorder, ',');
        stack<string> mystack;
        
        for(int i = 0;i < myres.size();i++) {
            if(mystack.size() == 1 && mystack.top() == "#") return false;
            else if(mystack.empty() || myres[i] != "#") mystack.push(myres[i]);
            else {
                if(mystack.top() != "#") mystack.push(myres[i]);
                //else if(mystack.size() == 1 && mystack.top() == "#") return false;
                else {
                    mystack.push("#");
                    bool con = true;
                    while(con) {
                        mystack.pop();
                        mystack.pop();
                        mystack.pop();
                        con = !mystack.empty() && (mystack.top() == "#");
                        mystack.push("#");
                    }
                }
            }
        }
        
        return mystack.size() == 1 && mystack.top() == "#";
    }
    
};