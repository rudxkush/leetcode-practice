class RandomizedSet {
    unordered_map<int, int> valToIndex;
    vector<int> values;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) return false;

        int lastVal = values.back();
        int idx = valToIndex[val];

        values[idx] = lastVal;
        valToIndex[lastVal] = idx;

        values.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % values.size();
        return values[idx];
    }
};
