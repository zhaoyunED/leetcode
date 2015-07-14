Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

//DFS
//×îºó·µ»Ø hash[node];
unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> hash;
    
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
        if(!node)
            return NULL;
        
        if(hash.find(node) == hash.end())
        {
            hash[node]= new UndirectedGraphNode(node->label);
            
            for(auto child: node->neighbors)
            {
                UndirectedGraphNode *nchild = cloneGraph(child);
                hash[node]->neighbors.push_back(nchild);
            }
        }
        
        return hash[node];
}


//BFS

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> record;
        if(node == NULL)
            return node;
 
        deque<UndirectedGraphNode*> queue;
        queue.push_back(node);
 
        while(!queue.empty()) {
            UndirectedGraphNode *nextNode = queue.front();
            queue.pop_front();
 
            if(!record.count(nextNode)) {
                UndirectedGraphNode *newNode = new UndirectedGraphNode(nextNode->label);
                record[nextNode] = newNode;
            }
            for(int i = 0; i < nextNode->neighbors.size() ; i ++) {
                UndirectedGraphNode *childNode = nextNode->neighbors[i];
                if(!record.count(childNode)) {
                    UndirectedGraphNode *newNode = new UndirectedGraphNode(childNode->label);
                    record[childNode] = newNode;
                    queue.push_back(childNode);
                }
                record[nextNode]->neighbors.push_back(record[childNode]);
            }
        }
        return record[node];
    }