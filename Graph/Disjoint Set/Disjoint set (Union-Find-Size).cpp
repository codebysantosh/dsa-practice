vector<int> parent;
vector<int> size;

int find (int x) {
    if (x == parent[x]) 
        return x;

    return parent[x] = find(parent[x]);
}

void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) 
        return;

    if(size[x_parent] > size[y_parent]) {
        parent[y_parent] = x_parent;
        size[x_parent] += size[y_parent];
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    } else {
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    }
}
