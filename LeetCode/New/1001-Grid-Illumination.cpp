	class Solution {
	public:
		vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
			vector<int> res;
			map<int, int> hor_map, ver_map, add_map, sub_map;
			for (auto a = lamps.begin(); a != lamps.end(); a++) {
				int x = (*a)[0];
				int y = (*a)[1];
				insertToMap(hor_map, x);
				insertToMap(ver_map, y);
				insertToMap(add_map, x + y);
				insertToMap(sub_map, x - y);
			}
			for (auto a = queries.begin(); a != queries.end(); a++) {
				int x = (*a)[0];
				int y = (*a)[1];
				if (isLit(hor_map, x) || isLit(ver_map, y) || isLit(add_map, x + y) || isLit(sub_map, x - y)) {
					res.push_back(1);
					turnOffLamps(lamps, *a, hor_map, ver_map, add_map, sub_map);
				} else {
					res.push_back(0);
				}
			}
			return res;
		}
	private:
		void turnOffLamps(vector<vector<int>>& lamps, vector<int> loc, map<int, int>& hor, map<int, int>& ver, map<int, int>& add, map<int, int>& sub) {
			int x = loc[0];
			int y = loc[1];
			for (auto a = lamps.begin(); a != lamps.end(); a++) {
				for (int i : {x - 1, x, x + 1}) {
					for (int u : {y - 1, y, y + 1}) {
						if ((*a)[0] == i && (*a)[1] == u) {
							auto _hor = hor.find(i);
							if (_hor != hor.end()) {
								_hor->second -= 1;
								if (_hor->second == 0) {
									hor.erase(_hor);
								}
							}
							auto _ver = ver.find(u);
							if (_ver != ver.end()) {
								_ver->second -= 1;
								if (_ver->second == 0) {
									ver.erase(_ver);
								}
							}
							auto _add = add.find(i + u);
							if (_add != add.end()) {
								_add->second -= 1;
								if (_add->second == 0) {
									add.erase(_add);
								}
							}
							auto _sub = sub.find(i - u);
							if (_sub != sub.end()) {
								_sub->second -= 1;
								if (_sub->second == 0) {
									sub.erase(_sub);
								}
							}
						}
					}
				}
			}
		}
		bool isLit(map<int, int>& namp, int a) {
			return (namp.find(a) != namp.end());
		}
		void insertToMap(map<int, int>& mp, int a) {
			auto rec = mp.find(a);
			if (rec != mp.end()) {
				rec->second += 1;
			} else {
				mp.insert(pair<int, int>(a, 1));
			}
		}
	};