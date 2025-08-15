class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneSet(bank.begin(), bank.end());
        if(!geneSet.count(endGene)) return -1;

        queue<pair<string, int>> q; // {gene, steps}
        q.push({startGene, 0});

        vector<char> choices = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;
        visited.insert(startGene);

        while(!q.empty()) {
            auto [gene, steps] = q.front(); q.pop();
            if(gene == endGene) return steps;

            for(int i = 0; i < gene.size(); ++i) {
                char original = gene[i];
                for(char c : choices) {
                    if(c == original) continue;
                    gene[i] = c;
                    if(geneSet.count(gene) && !visited.count(gene)) {
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = original;
            }
        }
        return -1;
    }
};
