class Solution {
public:

    struct TrieNode{
        bool flag = false;
        string str;
        TrieNode* child[26];

        bool containChar(char c){
            return child[c - 'a'] != NULL;
        }
        
        void putNode(char c, TrieNode* node){
            child[c - 'a'] = node;
        }

        TrieNode* getNode(char c){
            return child[c - 'a'];
        }

        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containChar(word[i])){
                node->putNode(word[i], new TrieNode());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
        node->str = word;
    }

    void checkWord(int i, int j, TrieNode* node, vector<vector<char>>& board, vector<vector<bool>>& vis, set<string>& s){
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0)
            return;

        node = node->getNode(board[i][j]);
        if(vis[i][j] || !node)
            return;

        if(node->isEnd())
            s.insert(node->str);

        vis[i][j] = 1;
        checkWord(i+1, j, node, board, vis, s);
        checkWord(i-1, j, node, board, vis, s);
        checkWord(i, j+1, node, board, vis, s);
        checkWord(i, j-1, node, board, vis, s);
        vis[i][j] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> s;
        for(auto word:words)
            insert(word);

        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(),0));

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                checkWord(i, j, root, board, vis, s);
            }
        }   

        vector<string> ans(s.begin(), s.end());
        return ans;
    }
};
