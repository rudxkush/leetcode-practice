class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // insert all the string in set for O(1) locating the valid Gene.
        unordered_set<string> geneSet;
        for(auto& gene : bank) 
            geneSet.insert(gene);
        
        unordered_set<string> visitedSet;
        // perform BFS from startGene and try to reach the endGene
        // note that the first reach is always gonna be sorted in the BFS.
        queue<pair<string, int>> q; // gene, hops
        q.push({startGene,0});
        vector<char> choices = {'A', 'C', 'G', 'T'};
        while(!q.empty()) {
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(gene == endGene) return steps;
            for(int i = 0; i < gene.length(); ++i) {
                for(auto& ch : choices ) {
                    string original = gene;
                    gene[i] = ch;
                    if(geneSet.find(gene) != geneSet.end() && visitedSet.find(gene) == visitedSet.end()) {
                        visitedSet.insert(gene);
                        q.push({gene, steps + 1});
                    }
                    gene = original;
                }
            }
        }
        return -1;
    }
};