void makeCombiUtil(vector<int> &input, vector<vector<int>> &answer, 
                    vector<int> &temp, int n, int left, int k) {
    if (k == 0) {
        answer.push_back(temp);
        return;
    }
    for (int i = left; i < n; ++i) {
        temp.push_back(input[i]);
        makeCombiUtil(input, answer, temp, n, i + 1, k - 1);
        temp.pop_back();
    }
}