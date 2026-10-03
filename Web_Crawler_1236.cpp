//
// Created by Anh Le on 9/12/26.
//

string getHostName(const string &url)
{
    int start = 7;
    int end = url.find('/', start);
    if (end == string::npos) return url.substr(start);
    return url.substr(start, end-start);
}
vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    const string hostName = getHostName(startUrl);
    unordered_set<string> visited;
    queue<string> q;
    q.push(startUrl);
    visited.insert(startUrl);

    while (!q.empty())
    {
        string url = q.front();
        q.pop();
        for (string &link : htmlParser.getUrls(url))
        {
            if (visited.count(link) == 0 && hostName == getHostName(link))
            {
                visited.insert(link);
                q.push(link);
            }
        }
    }
    return vector<string>(visited.begin(), visited.end());
}