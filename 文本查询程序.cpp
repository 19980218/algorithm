#include<iostream>
#include<istream>
#include<fstream>
#include<ostream>
#include<string>
#include<list>
#include<vector>
#include<array>
#include<deque>
#include<algorithm>
#include<iterator>
#include<map>
#include<utility>
#include<set>
#include<memory>
#include<sstream>
using namespace std;
using namespace placeholders;
using line_no = vector<string>::size_type;
class Queryresult;
class Textquery{
    public:

        Textquery(ifstream&);
        Queryresult query(const string&) const;

    private:
        shared_ptr<vector<string>> file;
        map<string,shared_ptr<set<line_no>>> wm;
    };
Textquery::Textquery(ifstream &is):file(new vector<string>)
{
    string text;
    while(getline(is,text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

class Queryresult{
    friend ostream& print(ostream&, const Queryresult&);
    public:
        Queryresult(string s,shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
            sougth(s),lines(p),file(f){}
    private:
        string sougth;
        shared_ptr<set<line_no>> lines;
        shared_ptr<vector<string>> file;

};
Queryresult Textquery::query(const string &sougth) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sougth);
    if (loc == wm.end())
        return Queryresult(sougth, nodata, file);
    else
        return Queryresult(sougth, loc->second, file);
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
ostream &print(ostream & os, const Queryresult &qr)
{
    os << qr.sougth << "occurs" << qr.lines->size() << " " << make_plural(qr.lines->size(),"time","s") << endl;
    for(auto num:*qr.lines)
        os << "\t(line" << num + 1 << ")" << *(qr.file->begin() + num) << endl;
    return os;
}
void runQueries(ifstream &infile)
{
    Textquery tp(infile);
    while(true)
    {
        cout << "enter word to look for , or q to quit:";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout,tp.query(s)) << endl;
    }
}
int main()
{
    ifstream infile;
    infile.open("text1.txt");
    runQueries(infile);
    return 0;
}
