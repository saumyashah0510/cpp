#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{

    int n = grid.size();
    vector<vector<int>> status(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({startX, startY});
    status[startX][startY] = 0;

    while (!q.empty())
    {
        pair<int, int> p;
        p = q.front();
        q.pop();

        int curr_row, curr_col;
        curr_row = p.first;
        curr_col = p.second;

        // right move
        for (int j = 1; curr_col + j < n && grid[curr_row][curr_col + j] != 'X'; j++)
        {
            if (status[curr_row][curr_col + j] == -1)
            {
                status[curr_row][curr_col + j] = status[curr_row][curr_col] + 1;
                q.push({curr_row, curr_col + j});
                if (curr_row == goalX && curr_col + j == goalY)
                {
                    return status[curr_row][curr_col + j];
                }
            }
        }
        // bottom move
        for (int j = 0; curr_row + j < n && grid[curr_row + j][curr_col] != 'X'; j++)
        {
            if (status[curr_row + j][curr_col] == -1)
            {
                status[curr_row + j][curr_col] = status[curr_row][curr_col] + 1;
                q.push({curr_row + j, curr_col});
                if (curr_row + j == goalX && curr_col == goalY)
                {
                    return status[curr_row + j][curr_col];
                }
            }
        }

        // left move
        for (int j = 1; curr_col - j >= 0 && grid[curr_row][curr_col - j] != 'X'; j++)
        {
            if (status[curr_row][curr_col - j] == -1)
            {
                status[curr_row][curr_col - j] = status[curr_row][curr_col] + 1;
                q.push({curr_row, curr_col - j});
                if (curr_row == goalX && curr_col - j == goalY)
                {
                    return status[curr_row][curr_col - j];
                }
            }
        }

        // up move
        for (int j = 1; curr_row - j >= 0 && grid[curr_row - j][curr_col] != 'X'; j++)
        {
            if (status[curr_row - j][curr_col] == -1)
            {
                status[curr_row - j][curr_col] = status[curr_row][curr_col] + 1;
                q.push({curr_row - j, curr_col});
                if (curr_row - j == goalX && curr_col == goalY)
                {
                    return status[curr_row - j][curr_col];
                }
            }
        }
    }
    return -1;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
