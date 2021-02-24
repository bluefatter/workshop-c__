#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::find;
using std::find_if;
using std::search;
using std::isalnum;

typedef string::const_iterator iter;

bool not_url_char(char c) {
    /**
     * Characters in addition to alphanumerics that can appear in a URL
     *
     * STATIC CONST METHOD VARIABLE: all call share one instance!!!
     */
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    /**
     * find function if not found return url_ch.end()
     */
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

iter url_end(iter begin, iter end) {
    return find_if(begin, end, not_url_char);
}

iter url_beg(iter begin, iter end) {
    static const string sep = "://";

    iter i = begin;
    while ((i = search(i, end, sep.begin(), sep.end())) != end) {
        if (i != begin && i + sep.size() != end) {
            iter beg = i;
            while (beg != begin && !not_url_char(beg[-1]))
                --beg;
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        i += sep.size();
    }
    return end;
}

vector<string> find_urls(const string& str) {
    vector<string> result;
    iter begin = str.begin(), end = str.end();

    while (begin != end) {
        begin = url_beg(begin, end);

        if (begin != end) {
            iter after = url_end(begin, end);
            result.emplace_back(begin, after);
            begin = after;
        }
        ++begin;
    }
    return result;
}

int main() {
    string url = "http://1.comh";
    vector<string> urls = find_urls(url);
    for (string& u: urls) {
        cout << u << endl;
    }
    return 0;
}
