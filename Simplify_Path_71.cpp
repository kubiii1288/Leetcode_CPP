//
// Created by Anh Le on 4/3/26.
//
void normalize_string(string &path)
{
    string ans;
    for (char a: path)
    {
        if (a == '/' && ans.size() > 0 && ans.back() == '/')
            continue;
        ans.push_back(a);
    }
    path = ans;
    if (path.size() > 0 && path.back() == '/')
        path.pop_back();
}
void get_directory_vector(string &path, vector<string> &parts)
{
    string dir;
    for (char c : path)
    {
        if (c == '/')
        {
            if (!dir.empty())
            {
                parts.push_back(dir);
                dir.clear();
            }

        } else dir.push_back(c);
    }
    parts.push_back(dir);
}

string simplifyPath(string &path) {
    normalize_string(path);
    vector<string> parts;
    get_directory_vector(path,parts);
    vector<string> final_path;
    for (string &dir : parts)
    {
        if (dir == ".")
            continue;
        if (dir == "..")
        {
            if (!final_path.empty())
                final_path.pop_back();
        }
        else final_path.push_back(dir);
    }
    string ans;
    for (string &dir : final_path)
    {
        ans.push_back('/');
        ans.append(dir);
    }

    return ans.empty() ? "/" : ans;
}