
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}

bool sortcol1(const vector<int>& v1, const vector<int>& v2)
{
  if (v1[0]==v2[0])
  {
    return v1[1] < v2[1];
  }
    return v1[0] < v2[0];
}

for a/b ->
floor a/b
ceil (a + b - 1) / b                                       

sqrt using ~~~ binary search
learning keep n=2**30 or something and then keep o halving it 
if ans initially zero +k*ans+k<=x then add that to ans
long long int_sqrt (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}

To calculate ⌊log2(a)⌋ for a positive integer a:
Don't use log2(a) or similar.
Do use __lg or an approach based on __builtin_clz or __builtin_clzll.
 The "clz" stands for "count leading zeroes" and it does exactly what
  it says — on the binary representation of the number. 
If you have access to C++20, there is also the bit_width library function.
Warning: __builtin_clz(0) and __builtin_clzll(0) are undefined behavior. Also all these functions starting with __ are specific to GCC and you're technically not meant to use them, but it's fine in competitive programming.

vector<vector<int> > a(n, vector<int>(2));

  freopen("input.txt", "r", stdin);       
     freopen("output.txt", "w", stdout);  

    void dfs(int s)
  {
    f[s]=true;
    for (int i = 1; i <= k; ++i)
    {
      if (f[i]) continue;
        if(a[s]>a[i] && a[s] < b[i])
            dfs(i);
        else if(b[s] > a[i] && b[s] < b[i])
            dfs(i);
    }
  }

int cd(long long n) {
  return floor(log10(n) + 1);
}

if(is_sorted(a,a+n) and is_sorted(b,b+n))

    bool my_compare(pair<string, int> &p1, pair<string, int> &p2)
    {
    if (p1.second != p2.second ) return p1.second > p2.second ;
    return p1.first < p2.first;
    }

  void o_pattern(int a, int b)
  {
    for (int i = 0; i < 2; ++i)
    {
      /* code */
    }
  }
  void _pattern(int a, int b)
  {
    for (int i = 0; i < 2; ++i)
    {
      /* code */
    }
  }

  bool sortcol1(const vector<int>& v1, const vector<int>& v2)
{
  if (v1[1]==v2[1])
  {
    return v1[0] < v2[0];
  }
    return v1[1] < v2[1];
}


ll gcd( ll a, ll b )
        {                   
          if(b==0)
          {
               return a;
          }
          else
          {
               return gcd( b, a%b );
          }
        }


 int powisshit(int a)
  {
    int n=1;
    for (int i = 0; i < a; ++i)
    {
      n*=2;
    }

    return n;
  }

char ch;
  char ch;
  // char(ch^' ');
  cin >> ch;
  cout << char(ch^' ');

bool num(ll a)
{
    return __builtin_parity(a);//////////////////
}



$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 SEGMENT TREE /////////////////////////////////////////////
vector<int> arr(100, 0);
vector<int> segTree(400, 0);
void build(int ind, int start, int end){
    if(start == end) // leaf node
    {
        segTree[ind] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * ind, start, mid);
    build(2 * ind + 1, mid + 1, end);
    segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
}
void update(int ind, int start, int end, int pos, int val){
    if(start == end){
        segTree[ind] = val;
        arr[pos] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(pos <= mid)
        update(2 * ind, start, mid, pos, val);
    else
        update(2 * ind + 1, mid + 1, end, pos, val);
    segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
}
int query(int ind, int start, int end, int left, int right){
    // completely overlapping
    if(start >= left && end <= right){
        return segTree[ind];
    }
    if(start > right || end < left){
        return 0;
    }
    int mid = (start + end) / 2;
    int ansLeft = query(2 * ind, start, mid, left, right);
    int ansRight = query(2 * ind + 1, mid + 1, end, left, right);
    return ansLeft + ansRight;
}
