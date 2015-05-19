const int ALPHA_NUM = 26;

struct TrieNode{
     TrieNode* childs[ALPHA_NUM];
     TrieNode* father;
     char ch;
     bool isEndOfWord;
     TrieNode() :isEndOfWord(false), father(NULL), ch(0)
     {
         fill_n(childs, ALPHA_NUM, nullptr);
     }
 };


 class Solution {
     TrieNode *root;
     unordered_set<TrieNode *> visitedNodes;
     vector<string> res;
     
 public:
     Solution(){
         root = new TrieNode();
     }
     
     void insert(string word){
         TrieNode *curnode = root;
         for (auto ch : word)
         {
             int curidx = ch - 'a';
             if (curnode->childs[curidx] == NULL)
             {
                 curnode->childs[curidx] = new TrieNode();
                 curnode->childs[curidx]->father = curnode;
                 curnode->childs[curidx]->ch = ch;
             }
             curnode = curnode->childs[curidx];
         }
         curnode->isEndOfWord = true;
     }
     
     string getWord(TrieNode *curnode){
         string res = "";
         while (curnode->father != NULL)
         {
             res.push_back(curnode->ch);
             curnode = curnode->father;
         }
         reverse(res.begin(), res.end());
         return res;
     }
     
     void DFS(vector<vector<char>>& board, int r, int c, TrieNode *curnode){

         if (curnode->isEndOfWord)
         {
             if (visitedNodes.find(curnode) == visitedNodes.end())
             {
                 visitedNodes.insert(curnode);
                 res.push_back(getWord(curnode));
             }
         }
         
         pair<int, int> pos[4] = {{0,1},{0,-1},{1,0},{-1,0}};
         
         for(int i = 0;i < 4;i++)
         {
             int nr = r + pos[i].first;
             int nc = c + pos[i].second;
             if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '-')
             {
                 int curidx = board[nr][nc] - 'a';
                 if (curnode->childs[curidx] != NULL)
                 {
                     board[nr][nc] = '-';
                     DFS(board, nr, nc, curnode->childs[curidx]);
                     board[nr][nc] = curidx + 'a';
                 }
             }
         }
     }
     
     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         for (int i = 0;i < words.size();i++)
             insert(words[i]);
             
         for (int j = 0; j < board.size(); ++j)
         {
             for (int k = 0; k < board[j].size(); ++k)
             {
                 int curidx = board[j][k] - 'a';
                 if (root->childs[curidx] != NULL)
                 {
                     board[j][k] = '-';
                     DFS(board, j, k, root->childs[curidx]);
                     board[j][k] = curidx + 'a';
                 }
             }
         }
         return res;
     }
 };
