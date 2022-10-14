#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)

struct state {
    int puzzle[9];
    int depth;
    int evaluation;
    bool operator>(const state &s) const {
        return evaluation > s.evaluation;
    }
};

state start = { {0, 0, 0,
                0, 0, 0,
                0, 0, 0},
                0,
                0};
state goal = { {1, 2, 3,
                4, 5, 6,
                7, 8, 0}, // puzzle
                0,           // depth
                0};        // evaluation
std::priority_queue <state, std::vector<state>, std::greater<state> > open;
std::stack<state> open2;
std::vector<state> closed;
int count = 0;
int max = 0;

bool IsFinished(state s)
{
    for (int i = 0; i < 8; i++) {
       if (s.puzzle[i] != goal.puzzle[i]) {
           return false;
       } 
    }
    return true;
}

int ManhattanOne(int n, int place)
{
    if (goal.puzzle[n] == 0) {
        return 0;
    }
    int q, r;
    q = abs(place / 3 - n / 3);
    r = abs(place % 3 - n % 3);
    return q + r;
}

int manhattan(state s)
{
    int eval = 0;
    std::map<int, int> goalplace;
    for (int i = 0; i < 9; i++) {
        goalplace[goal.puzzle[i]] = i;
    }
    for (int i = 0; i < 9; i++) {
        eval += ManhattanOne(goalplace[s.puzzle[i]], i);
    }
    return eval;
}

bool IsSamePuzzle(state s1, state s2)
{
    for (int i = 0; i < 9; i++) {
        if (s1.puzzle[i] != s2.puzzle[i]) {
            return false;
        }
    }
    return true;
}

bool InClosed(state s)
{
    for (int i = 0; i < closed.size(); i++) {
        if (IsSamePuzzle(s, closed[i])) {
            return true;
        }
    }
    return false;
}

void AStar(std::function<int(state)> fun)
{
    if (open.empty()) {
        std::cerr << "Search have mistakenly stopped!" << std::endl;
    }
    if (max < open.size() + closed.size()) {
        max = open.size() + closed.size();
    }
    count++;
    state now = open.top();
    open.pop();
    closed.push_back(now);
    if (IsFinished(now)) {
        std::cout << "Finished!" << std::endl;
        return;
    }
    state s = now;    
    int zero;
    for (int i = 0; i < 9; i++) {
        if (now.puzzle[i] == 0) {
            zero = i;
            break;
        }
    }
    if (zero - 3 >= 0) {
        std::swap(s.puzzle[zero - 3], s.puzzle[zero]);
        if (not InClosed(s)) {
            s.depth++;
            s.evaluation = fun(s) + s.depth;
            open.push(s);
        }
        s = now;
    }
    if (zero % 3 != 0) {
        std::swap(s.puzzle[zero - 1], s.puzzle[zero]);
        if (not InClosed(s)) {
            s.depth++;
            s.evaluation = fun(s) + s.depth;
            open.push(s);
        }
        s = now;
    }
    if (zero % 3 != 2) {
        std::swap(s.puzzle[zero + 1], s.puzzle[zero]);
        if (not InClosed(s)) {
            s.depth++;
            s.evaluation = fun(s) + s.depth;
            open.push(s);
        }
        s = now;
    }
    if (zero + 3 < 9) {
        std::swap(s.puzzle[zero + 3], s.puzzle[zero]);
        if (not InClosed(s)) {
            s.depth++;
            s.evaluation = fun(s) + s.depth;
            open.push(s);
        }
    }
    AStar(fun);
    return;
}

int main()
{   
    rep(i, 9){
        std::cin >> start.puzzle[i];
    }
    start.evaluation = manhattan(start);
    open.push(start);
    open2.push(start);
    AStar(manhattan);

    std::cout << count << std::endl;

    return 0;
}