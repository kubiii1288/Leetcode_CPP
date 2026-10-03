//
// Created by Anh Le on 9/10/26.
//

int best = 0;
int dfs(Node* root)
{
    int longest = 0;
    int secondLongest = 0;
    for (Node* child : root->children)
    {
        int rs = 1 + dfs(child);
        if (rs >= longest)
        {
            secondLongest = longest;
            longest = rs;
        } else if (secondLongest < rs)
        {
            secondLongest = rs;
        }
    }
    best = max(best, longest + secondLongest);
    return longest;
}
int diameter(Node* root) {
    dfs(root);
    return best;
}