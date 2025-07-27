vector<int> parent;

int find(int x)
{
       if(x == parent[x])
        return x;
        
        return find(parent[x]);
}

void unionSet(int X,int Z)
{
	int x = find(X);
	int y = find(Z);
	
	if(x == y)
	    return;
	
	parent[x] = y;
}
