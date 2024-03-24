struct TrieNode
{
    TrieNode *links[26];
    int cnt = 0;
    bool flag = false;
    bool contains(int x)
    {
        return links[x] != NULL;
    }
    void put(char ch, TrieNode *node)
    {
        links[ch - 97] = node;
    }
    TrieNode *get(int x)
    {
        return links[x];
    }
    void increment()
    {
        cnt++;
    }
    void set()
    {
        flag = true;
    }
    bool doesSatisfy()
    {
        return flag;
    }
};
void insert(string &word, struct TrieNode *root)
{
    auto temp = root;
    for (auto x : word)
    {
        if (!temp->contains(x - 97))
        {
            temp->put(x, new TrieNode());
        }
        temp = temp->get(x - 97);
        temp->increment();
    }
    temp->set();
}
int dfs(int ind, string &word, struct TrieNode *root)
{
    if (ind == word.size())
        return 0;
    root = root->get(word[ind] - 97);
    int ans = root->cnt + dfs(ind + 1, word, root);
    return ans;
}