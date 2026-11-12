//
// Created by kubiii on 10/22/26.
//
struct Table
{
    int nextID = 1;
    int numCol = 0;
    unordered_map<int,vector<string>> rows;
};
class SQL {
public:
    unordered_map<string, Table> db;
    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < names.size();i++) {
            db[names[i]].numCol = columns[i];
        }
    }

    bool ins(string name, vector<string> row) {
        auto target = db.find(name);
        if (target == db.end() || target->second.numCol != row.size()) return false;
        int nextID = target->second.nextID++;
        target->second.rows[nextID] = row;
        return true;
    }

    void rmv(string name, int rowId) {
        auto table = db.find(name);
        if (table == db.end()) return;
        table->second.rows.erase(rowId);
    }

    string sel(string name, int rowId, int columnId) {
        auto targetDB = db.find(name);
        if (targetDB == db.end()) return "<null>";
        auto targetRow = targetDB->second.rows.find(rowId);
        if (targetRow == targetDB->second.rows.end()) return "<null>";
        if (columnId > targetDB->second.numCol || columnId < 1) return "<null>";
        return targetRow->second[columnId-1];
    }

    vector<string> exp(string name) {
        auto table = db.find(name);
        if (table == db.end()) return {};
        vector<int> sortedRow;
        sortedRow.reserve(table->second.rows.size());
        for (auto &[id, data] : table->second.rows) {
            sortedRow.push_back(id);
        }
        sort(sortedRow.begin(), sortedRow.end());
        vector<string> ans;
        for (int id : sortedRow) {
            string rc;
            rc.append(to_string(id));
            for (string &col : table->second.rows[id]) {
                rc.push_back(',');
                rc.append(col);
            }
            ans.push_back(rc);
        }
        return ans;
    }
};