/* AUTHOR:- RAJAT SHAHI */
/* THERE IS NO TALENT HERE... THIS IS HARDWORK... THIS IS OBSESSION... */

#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
using lld = long double; //use double if TIME LIMIT is tight

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using plld = pair<lld, lld>;

using vi = vector<int>;
using vll = vector<ll>;
using vbool = vector<bool>;
using vstring = vector<string>;
using vlld = vector<lld>;
using vpll = vector<pll>;
using vpi = vector<pi>;
using vplld = vector<plld>;

// unordered_map,unordered_set
#define   ump     unordered_map
#define   ust     unordered_set

//pairs
#define   mp      make_pair
#define   ff      first
#define   ss       second

//vectors
#define   pb      push_back
#define   eb      emplace_back
#define   pf      push_front
#define   popf    pop_front
#define   popb    pop_back
#define   ub      upper_bound
#define   lb      lower_bound

#define   sz(v)   int((v).size())
#define   all(v)  v.begin(),v.end()
#define   rall(v) v.rbegin(),v.rend()

//LOOPS
#define   rep(i,a,n)    for(int i=a ; i< n;  ++i)
#define   for0(i,n)     rep(i,0,n)
#define   for1(i,n)     rep(i,1,n)
#define   per(i,n,a)    for(int i=n-1; i>= a; i--)
#define   foreach(i,container)  for( auto& i : container)

//bits
#define   ppc     __builtin_popcount
#define   ppcll   __builtin_popcountll

//general (testcases,files,etc...)
#define   testcases    int t; cin >> t; while (t--)
#define   fileIO       freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define   gcd(m,n)     __gcd(m,n)
#define   lcm(m,n)     m*(n/gcd(m,n))
#define   endl         "\n"

const long long INF = 1e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const lld PI =  acos( (lld) - 1);

// direction vectors
int DX8[] = {1, -1, 0, 0, -1, 1, -1, 1}; // for eight directions
int DY8[] = {0, 0, 1, -1, 1, 1, -1, -1}; // for eight directions
int DX4[] = {1, -1, 0, 0}; // for 4 directions
int DY4[] = {0, 0, 1, -1}; // for 4 directions


//------------------------------------------------------------------------------
// debugging
#define   debug(x) cerr << #x << " = " << x << endl;

// taking input in the array
template<class T>
void readarray(T &arr)
{
    foreach(i, arr) cin >> i;
}

// printing the array
template<class T>
void writearray(T &arr)
{
    foreach(i, arr) cout << i << " ";
}

//myceil and floor function for int and ll
template<class T>
T myceil(T x, T y)
{
    return (x % y == 0) ? (x / y) : ((x / y) + 1);
}

// debugging the array
template<class T>
void debug_array(string s, T &arr)
{
    cerr << s << endl;
    foreach(i, arr) cerr << i << " ";
    cerr << endl;
}
//------------------------------------------------------------------------------

// GLOBAL VARIABLES AND FUNCTIONS WILL GO HERE




class graph
{
private:
    int v;
    vll *adj_list;
    ll *parent;
    ll *dist;
public:

    graph(int n)
    {
        this->v = n;
        this->adj_list = new vll[this->v];
        this->parent = new ll[this->v];
        this->dist = new ll[this->v];
    }

    void add_edge(int s, int d, bool bidir = true)
    {
        adj_list[s].pb(d);
        if(bidir)
        {
            adj_list[d].pb(s);
        }
    }

    bool BFS(int src, int des, vll &str, int& len)
    {
        vbool visited(this->v);
        queue<ll> q;

        if(src == des)
        {
            str.pb(des);
            len = 0;
            return true;
        }

        q.push(src);
        visited[src] = true;
        dist[src] = 0;
        parent[src] = src;


        while(not q.empty())
        {
            ll curr = q.front();
            q.pop();

            if(curr == des)
            {
                len = dist[curr];
                while(parent[curr] != curr)
                {
                    str.pb(curr);
                    curr = parent[curr];
                }
                str.pb(curr);
                return true;
            }

            for(auto i : adj_list[curr])
            {
                if(not visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    dist[i] = dist[curr] + 1;
                    parent[i] = curr;
                }
            }


        }

        return false;
    }



    void is_path(int s, int d)
    {
        vll str;
        int len = 0;
        if(BFS(s, d, str, len))
        {
            cout << "PATH EXISTS" << endl;
            cout << "PATH:" << endl;
            cout << "------------------" << endl;
            reverse(all(str));

            rep(i, 0, sz(str) - 1) cout << str[i] << "--->";
            cout << str[sz(str) - 1];

            cout << endl << "distance from src to des= " << len << endl;
        }
        else
        {
            cout << "PATH DOESN'T EXISTS" << endl;
        }
    }


};





//-------------------------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int e;
    cin >> e;


    graph g(n);

    rep(i, 0, e)
    {
        int s, d;
        cin >> s >> d;
        g.add_edge(s, d);
    }


    cout << "enter the source" << endl;
    int src;
    cin >> src;
    cout << "enter the destination" << endl;
    int des;
    cin >> des;

    g.is_path(src, des);


}

// If you are not able to solve, then try brute-force and try to optimize
// Always try on edge cases before submitting the solution
// Try the base cases if there is stack overflow in recursion
// If you are using iterators then check delete operations
// Not able to find the bugs then try the debug statements
// Not able to solve any problem then go for the easiest ones
// if 1<=N<=100 and 1<=M<=100 then check on (n=1,m=1),(n=1,m=100),(n=100,m=1),(n=100,m=100)