class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int cntOnes = 0, flips0 = 0;
		for (auto it : s)
		{
			if (it == '1')cntOnes++;
			else flips0++;
			flips0 = min(flips0, cntOnes);
		}
		return flips0;
	}
};