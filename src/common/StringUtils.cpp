#include "StringUtils.h"
#include <sstream>
vector<string> splitString(const string &input, const string &separator)
{
    vector<string> result;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = input.find(separator, start)) != string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + separator.length();
    }
    result.push_back(input.substr(start));

    return result;
}

vector<int> splitInts(const string &input, const string &separator)
{
    vector<int> result;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = input.find(separator, start)) != string::npos)
    {
        result.push_back(stoi(input.substr(start, end - start)));
        start = end + separator.length();
    }
    result.push_back(stoi(input.substr(start)));

    return result;
}

vector<float> splitFloats(const string &input, const string &separator)
{
    vector<float> result;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = input.find(separator, start)) != string::npos)
    {
        string str = input.substr(start, end - start);
        // cout << "str1-" << str << endl;
        result.push_back(stof(str));
        start = end + separator.length();
    }
    string str = input.substr(start);
    if (!str.empty())
    {
        // cout << "str2-" << str << endl;
        result.push_back(stof(str));
    }

    return result;
}

// Hàm nhận một vector<int> và trả về một chuỗi
string joinVector(const vector<int> &vec, const string &separator)
{
    ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        oss << vec[i];
        if (i < vec.size() - 1)
        {
            oss << separator;
        }
    }
    return oss.str();
}