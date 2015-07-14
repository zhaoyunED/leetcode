Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X


//UNION FIND
class UF
{
private:
    int* id;     // id[i] = parent of i
    int* rank;  // rank[i] = rank of subtree rooted at i (cannot be more than 31)
    int count;    // number of components
public:
    UF(int N)
    {
        count = N;
        id = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = 0;
        }
    }
    ~UF()
    {
        delete [] id;
        delete [] rank;
    }
    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];    // path compression by halving
            p = id[p];
        }
        return p;
    }
    int getCount() {
        return count;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (rank[i] < rank[j]) id[i] = j;
        else if (rank[i] > rank[j]) id[j] = i;
        else {
            id[j] = i;
            rank[i]++;
        }
        count--;
    }
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if(n==0)    return;
        int m = board[0].size();
        UF uf = UF(n*m+1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&board[i][j]=='O') // if a 'O' node is on the boundry, connect it to the dummy node
                    uf.connect(i*m+j,n*m);
                else if(board[i][j]=='O') // connect a 'O' node to its neighbour 'O' nodes
                {
                    if(board[i-1][j]=='O')
                        uf.connect(i*m+j,(i-1)*m+j);
                    if(board[i+1][j]=='O')
                        uf.connect(i*m+j,(i+1)*m+j);
                    if(board[i][j-1]=='O')
                        uf.connect(i*m+j,i*m+j-1);
                    if(board[i][j+1]=='O')
                        uf.connect(i*m+j,i*m+j+1);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!uf.connected(i*m+j,n*m)){ // if a 'O' node is not connected to the dummy node, it is captured
                    board[i][j]='X';
                }
            }
        }
    }
};



//BFS

void bfsBoundary(vector<vector<char> >& board, int w, int l)
{
    int width = board.size();
    int length = board[0].size();
    deque<pair<int, int> > q;
    q.push_back(make_pair(w, l));
    board[w][l] = 'B';
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop_front();
        pair<int, int> adjs[4] = {{cur.first-1, cur.second}, 
            {cur.first+1, cur.second}, 
            {cur.first, cur.second-1},
            {cur.first, cur.second+1}};
        for (int i = 0; i < 4; ++i)
        {
            int adjW = adjs[i].first;
            int adjL = adjs[i].second;
            if ((adjW >= 0) && (adjW < width) && (adjL >= 0)
                    && (adjL < length) 
                    && (board[adjW][adjL] == 'O')) {
                q.push_back(make_pair(adjW, adjL));
                board[adjW][adjL] = 'B';
            }
        }
    }
}

void solve(vector<vector<char> > &board) {
    int width = board.size();
    if (width == 0) //Add this to prevent run-time error!
        return;
    int length = board[0].size();
    if  (length == 0) // Add this to prevent run-time error!
        return;

    for (int i = 0; i < length; ++i)
    {
        if (board[0][i] == 'O')
            bfsBoundary(board, 0, i);

        if (board[width-1][i] == 'O')
            bfsBoundary(board, width-1, i);
    }

    for (int i = 0; i < width; ++i)
    {
        if (board[i][0] == 'O')
            bfsBoundary(board, i, 0);
        if (board[i][length-1] == 'O')
            bfsBoundary(board, i, length-1);
    }

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'B')
                board[i][j] = 'O';
        }
    }
}