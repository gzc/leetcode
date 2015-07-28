class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i=0; i<input.size(); i++) {
            char c = input[i];
            if (ispunct(c))
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
        }
        return output.size() ? output : vector<int>{stoi(input)};
    }
};