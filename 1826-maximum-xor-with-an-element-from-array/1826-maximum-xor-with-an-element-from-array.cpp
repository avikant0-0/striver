class Solution {
public:
    class Trie {
        struct Node {
            Node* child[2] = {nullptr, nullptr};
        };

        Node* root = new Node();

    public:
        void insert(int num) {
            Node* node = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!node->child[bit]) {
                    node->child[bit] = new Node();
                }
                node = node->child[bit];
            }
        }

        int maxXOR(int x) const {
            int ans = 0;
            Node* node = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (x >> i) & 1;
                int opposite = 1 - bit;
                if (node->child[opposite]) {
                    ans |= (1 << i);
                    node = node->child[opposite];
                } else {
                    node = node->child[bit];
                }
            }
            return ans;
        }
    };

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Sort nums for efficient insertion
        sort(nums.begin(), nums.end());

        int m = queries.size(), n = nums.size();
        vector<int> answer(m, -1);

        // Prepare queries with original indices
        vector<tuple<int, int, int>> q1;
        for (int i = 0; i < m; ++i)
            q1.emplace_back(queries[i][0], queries[i][1], i);

        // Sort queries by their max limits
        sort(q1.begin(), q1.end(), [](const auto& a, const auto& b) {
            return get<1>(a) < get<1>(b);
        });

        // Process the queries efficiently
        int i = 0;
        Trie trie;
        for (const auto& [x, mi, idx] : q1) {
            // Insert all eligible numbers before this query
            while (i < n && nums[i] <= mi) {
                trie.insert(nums[i]);
                ++i;
            }
            // If there is something in the Trie, compute the max XOR
            if (i > 0) {
                answer[idx] = trie.maxXOR(x);
            }
        }

        return answer;
    }
};
