#include <cstdint>
#include <bits/stdc++.h>

#include <cmath>

// CPP standard

#define CPP20
 
/*
 * macros
 */
 
#define ci std::cin
#define co std::cout
 
#define endl '\n'
#define _ ' '
 
#define sort std::sort
#define all(C) (C).begin(), (C).end()
#define sz(x) (int)(x).size()
#define rev std::reverse
#define shuffle std::shuffle 
#define memset std::memset
 
#define max std::max
#define min std::min
 
#define pow std::pow
#define gcd std::gcd
#define lcm std::lcm
#define sqrt std::sqrt
 
#define swap std::swap
 
#define pub push_back
#define emb emplace_back
#define pob pop_back
#define pof pop_front
#define puf push_front
 
#define loop(n) for(li i = 0; i < n; ++i)
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define fort(i, a, t) for(size_t i = a; i < t; ++i)
#define forl(i, a, l) for(li i = a; i < l; ++i)
#define bforn(i, n) for(li i = n-1; i >= 0; --i)
#define bfort(i, n) for(size_t i = n-1; i >= 0; --i)
 
/*
 * types
 */
 
typedef std::string string;
 
typedef long long ll;
typedef long int hli;
typedef long long int li;
typedef unsigned long long ull;
typedef unsigned long long int uli;

typedef long double ld;
 
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<li> vli;
typedef std::vector<uli> vuli;
typedef std::vector<double> vd;
typedef std::vector<long double> vld;
typedef std::vector<char> vch;
typedef std::vector<std::string> vst;
 
typedef std::vector<vi> vvi;
typedef std::vector<vll> vvll;
typedef std::vector<vli> vvli;
typedef std::vector<vch> vvch;
 
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::pair<li, li> pli;
typedef std::pair<double, double> pdd;
 
typedef std::vector<pii> vpii;
typedef std::vector<pll> vpll;
typedef std::vector<pli> vpli;
typedef std::vector<pdd> vpdd;
 
typedef std::queue<li> qli;
 
/*
 * custom IO for containers
 */
 
#if defined(CPP20)

template <typename T> 
concept iterable_exc_string = 
requires (T a) { a.begin(); } && 
requires (T a) { a.end(); } && 
!std::common_with <T, std::basic_string <char>>;

template <typename T> 
requires iterable_exc_string <T>
std::istream &operator>> (std::istream &in, T &a) {
  for (auto &i : a) in >> i;
  return in;
}

template <typename T> 
requires iterable_exc_string <T>
std::ostream &operator<< (std::ostream &out, T &a) {
  for (auto &i : a) out << i << _;
  return out;
}

#endif

/* 
 * yes_no impl
 */
 
namespace yes_no_impl{
    const string YESNO[2] = {"NO", "YES"};
    const string YesNo[2] = {"No", "Yes"};
    const string yesno[2] = {"no", "yes"};
    void YES(bool t = 1) {co << YESNO[t] << endl;}
    void NO(bool t = 1) {YES(!t);}
    void Yes(bool t = 1) {co << YesNo[t] << endl;}
    void No(bool t = 1) {Yes(!t);}
    void yes(bool t = 1) {co << yesno[t] << endl;}
    void no(bool t = 1) {yes(!t);}
}
 
using namespace yes_no_impl;
 
/*
 * some functions, rarely used
 */
 
template<typename T> bool cmin(T &x,const T &y){if(x>y){x=y;return 1;}return 0;}
template<typename T> bool cmax(T &x,const T &y){if(x<y){x=y;return 1;}return 0;}
 
template<typename T> T abs(T num1, T num2){if(num1 >= num2){return num1-num2;}else{return num2-num1;}}
 
/*
 * adjacent cells for FibMatrix, with diagonal
 * order: 2 horizontal cells, 2 vertical cells, 4 diagonal cells
 */
 
vi xs = {-1, 1, 0, 0, -1, -1, 1, 1};
vi ys = {0, 0, -1, 1, -1, 1, -1, 1};

/**
 * rearrange zeros numbers at the end of the array
 */

void rearrange(vi& v){
    int cnt = 0;
    int n = sz(v);

    forn(i, 0, n){
        if(v[i] != 0){
            v[cnt] = v[i];
            cnt++;
        }
    }
    while(cnt < n){
        v[cnt] = 0;
        cnt++;
    }
}

void solve(){
    int n; ci >> n;
    vi v(n); ci >> v;

    rearrange(v);
    co << v << endl;
}

#define FILE_IO

int main(){
    std::ios_base::sync_with_stdio(false);
    ci.tie(nullptr), co.tie(nullptr);
    co.precision(20), co.setf(std::ios::fixed);

    #if defined(FILE_IO)
    {
        freopen("data/input_w1t9.txt", "r", stdin);
        freopen("data/output_w1t9.txt", "w", stdout);
    }
    #endif

    #if defined(TIME_CODE)
    
    clock_t tStart = clock();
    
    #endif
    
    uli t; ci >> t;
    while(t--){
        solve();
    }

    #if defined(TIME_CODE)

    double time_res = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    co << "Running time: " << time_res << " seconds\n";

    #endif

    return 0;
}