#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::getline;
using std::string;
using std::vector;
using std::map;
using std::strcmp;
using std::logic_error;
using std::rand;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

vector<string> split(const string& str) {
    vector<string> result;
    typedef string::size_type string_size;
    string_size str_size = str.size();
    string_size i = 0;

    while (i != str_size) {
        while (i != str_size && isspace(str[i]))
            ++i;

        string_size j = i;
        while (j != str_size && !isspace(str[j]))
            ++j;

        if (j != i) {
            result.push_back(str.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

Grammar read_grammar(istream& in) {
    string line;
    Grammar grammar;

    while(getline(in, line)) {
        if (strcmp(line.c_str(), "end") == 0) {
            break;
        }
        Rule rule = split(line);
        if (!rule.empty()) {
            grammar[rule[0]].push_back(Rule(rule.begin() + 1, rule.end()));
        }
    }
    return grammar;
}

bool is_bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw logic_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);
    return r;
}

void generate_sentences(const Grammar& grammar, const string& word, vector<string>& result) {
    if (!is_bracketed(word)) {
        return result.push_back(word);
    }

    auto it = grammar.find(word);
    if (it == grammar.end()) {
        throw logic_error("word not found");
    }

    const Rule_collection& rules = it -> second;
    const Rule& rule = rules[nrand(rules.size())];
    for (const string& s: rule) {
        generate_sentences(grammar, s, result);
    }
}

/**
 * Input:
 * <noun> cat
 * <noun> dog
 * <noun> table
 * <noun-phrase> <noun>
 * <noun-phrase> <adjective> <noun-phrase>
 * <adjective> large
 * <adjective> brown
 * <adjective> absurd
 * <verb> jumps
 * <verb> sits
 * <location> on the stairs
 * <location> under the sky
 * <location> wherever it wants
 * <sentence> the <noun-phrase> <verb> <location>
 */
int main() {
    Grammar grammar = read_grammar(cin);
    vector<string> result;
    generate_sentences(grammar, "<sentence>", result);
    for (const string& s: result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
