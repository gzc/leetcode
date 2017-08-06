// https://discuss.leetcode.com/topic/95378/concise-c-solution-with-regular-expression-12-lines
class Solution {
public:
    string solveEquation(string equation) {
    // normalize the equation, add 1 for x's which have no coefficient: x => 1x
    equation = regex_replace(equation, regex("(^|[+=-])x"), "$011x");

    // calculate coefficients for both sides
    auto pos = equation.find('=');
    auto l = coef(equation.substr(0, pos));
    auto r = coef(equation.substr(pos + 1));

    // l.first x + l.second = r.first x + r.second => ax = b
    int a = l.first - r.first;
    int b = r.second - l.second;

    return a != 0 ? "x=" + to_string(b/a) : b != 0 ? "No solution" : "Infinite solutions";
}

pair<int, int> coef(string s) {
    // split the side into form of (+/-)123x
    auto e = regex("(^|[+-])\\d+x?");
    regex_token_iterator<string::iterator> it(s.begin(), s.end(), e), end;

    int a = 0, b = 0;
    for (; it != end; it++)
        (it->str().back() == 'x' ? a : b) += stoi(*it);

    return {a, b};
}
};
