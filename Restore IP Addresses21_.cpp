class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>result;
		int temp = 256;
		string s1, s2, s3, s4;
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				for (int k = 1; k <= 3; k++)
				{
					for (int m = 1; m <= 3; m++)
					{
						if (i + j + k + m == s.length())
						{
							s1 = to_string(stoi(s.substr(0, i)));
							s2 = to_string(stoi(s.substr(i, j)));
							s3 = to_string(stoi(s.substr(i + j, k)));
							s4 = to_string(stoi(s.substr(i + j + k, m)));
							if (stoi(s1) < temp&&stoi(s2) < temp&&stoi(s3) < temp&&stoi(s4) < temp)
							{
								string test = s1 + "." + s2 + "." + s3 + "." + s4;
								if (test.length() == s.length() + 3)
									result.push_back(test);
							}
						}
					}
				}
			}
		}
		return result;
	}
};