//
// Created by kubiii on 10/23/26.
//
class Solution {
public:
    struct LetterLog {
        string id;
        string content;

        string getString() const { return id + " " + content; }
    };

    struct DigitLog {
        string id;
        string content;

        string getString() const { return id + " " + content; }
    };

    struct LComp {
        bool operator()(const LetterLog& a, const LetterLog& b) const {
            if (b.content == a.content)
                return a.id < b.id;
            return a.content < b.content;
        }
    };

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<DigitLog> digit_logs;
        vector<LetterLog> letter_logs;
        for (string& log : logs) {
            int delimeter_index = log.find_first_of(' ');
            string id = log.substr(0, delimeter_index);
            string content = log.substr(delimeter_index + 1,
                                        log.size() - delimeter_index - 1);
            if (isdigit(content[0])) {
                digit_logs.push_back({id, content});
            } else
                letter_logs.push_back({id, content});
        }
        sort(letter_logs.begin(), letter_logs.end(), LComp());
        vector<string> ans;
        for (LetterLog& l : letter_logs) {
            ans.push_back(l.getString());
        }
        for (DigitLog& l : digit_logs) {
            ans.push_back(l.getString());
        }
        return ans;
    }
};