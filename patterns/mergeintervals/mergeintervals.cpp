class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> m;
        m.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            vector<int>& l = m.back();
            if(intervals[i][0]<=l[1]){
                l[1] =max(l[1],intervals[i][1]);
            }
            else{
                m.push_back(intervals[i]);
            }
        }
        return m;
    }
};