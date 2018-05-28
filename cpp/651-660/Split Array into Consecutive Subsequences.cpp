class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> backs;

		// Keep track of the number of sequences with size < 3
		int need_more = 0;

		for (int num : nums) {
			if (! backs[num - 1].empty()) {	
                // There exists a sequence that ends in num-1
				// Append 'num' to this sequence
				// Remove the existing sequence
				// Add a new sequence ending in 'num' with size incremented by 1 
				int count = backs[num - 1].top();
				backs[num - 1].pop();
				backs[num].push(++count);

				if (count == 3)
					need_more--;
			} else {	
                // There is no sequence that ends in num-1
				// Create a new sequence with size 1 that ends with 'num'
				backs[num].push(1);
				need_more++;
			}
		}
		return need_more == 0;
	}
};
