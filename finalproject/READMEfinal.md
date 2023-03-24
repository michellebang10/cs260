1) Create a design
- Design is included in finalprojdesigns.pdf

2) Create some tests
- Idea of tests are included in finalprojdesigns.pdf

3) Implementation of graph class
- Add new vertex: addNode(string name)
- Add new edge: addEdge(GraphNode * person, GraphNode * pal, int level)
- Shortest Path Algorithm: shortestPath(string name)
- Minimum spanning tree: minimumSpanningTree()
- (all included in graph.cpp file)

4) Analyze the time complexity of all your graph behaviors 
- I have put comments in my code of time complexity next to each function, but I will elaborate more on the 4 main functions.
- addNode(): Time complexity of O(1) as it just adds a node to our graph, so it'll always take the same amount of time.
- addEdge(): Time complexity of O(1) as it just adds an edge to our graph, so it'll always take the same amount of time. 
- shortestPath(): Time complexity of O(n+m) where n is the number of nodes and m is the number of edges. For each node, we are looking at all its edges, so we go through all nodes and edges through this algorithm. 
- minimumSpanningTree(): Time complexity of O(mlogn) or O(mlogm) or O(m^2). For this one, I got help from GeeksForGeeks. For regular comparison edge sorting, the time complexity is O(mlogm). And the find/union method take O(logn). Since the number edges can be at most the number of nodes squared, O(mlogn) = O(mlogm). The reason I wrote O(m^2) as another possible time complexity is because I actually used bubble sort to order my edges. Since bubble sort has a time complexity of O(m^2), I think this time complexity is accurate for my specific MST algorithm. 

5) Code inputs/outputs
- My code inputs can be found under graphdriver.cpp
- Outputs:

Testing if a node that is not in the graph exists:

Does Tiana exist?: Tiana does not exists :(


Testing if an edge that is not added to graph exists:

Does Tiana and Cathy's friendship exist?: The friendship does not exist :(


Testing a node that is added to the graph exists:

Does Tiana exist?: Tiana exists!



Testing an edge that is added to graph exists:

Does Tiana and Cathy's friendship exist?: The friendship exists!


Current graph: 

Miche[Friends: ]

Tiana[Friends: Megan: 70, Cathy: 80, ]

Cathy[Friends: Tiana: 80, ]

Megan[Friends: Tiana: 70, ]


Tesing shortest path on simple case: 

Shortest Path from Tiana: 

node     dist    parent

Tiana      0      null

Megan      70      Tiana

Cathy      80      Tiana

Miche      inf      null


Testing shortest path on more complex case: 

Current graph: 

Miche[Friends: Megan: 20, Cathy: 60, ]

Tiana[Friends: Megan: 70, Cathy: 80, ]

Cathy[Friends: Tiana: 80, Miche: 60, ]

Megan[Friends: Tiana: 70, Miche: 20, ]


Shortest Path from Tiana: 

node     dist    parent

Tiana      0      null

Megan      70      Tiana

Cathy      80      Tiana

Miche      90      Megan


Testing shortest path from different node: 

Shortest Path from Miche: 

node     dist    parent

Miche      0      null

Megan      20      Miche

Cathy      60      Miche

Tiana      90      Megan


Testing MST on basic tree: 

Current graph: 

Miche[Friends: Megan: 20, Cathy: 60, ]

Tiana[Friends: Megan: 70, Cathy: 80, ]

Cathy[Friends: Tiana: 80, Miche: 60, ]

Megan[Friends: Tiana: 70, Miche: 20, ]


Minimum Spanning Tree: 

Megan  20  Miche

Cathy  60  Miche

Tiana  70  Megan

Total: 150


Testing MST on more complex case: 

Current graph: 

Miche[Friends: Megan: 20, Cathy: 60, Helen: 90, ]

Tiana[Friends: Megan: 70, Cathy: 80, ]

Cathy[Friends: Tiana: 80, Miche: 60, Grace: 50, ]

Megan[Friends: Tiana: 70, Miche: 20, ]

Helen[Friends: Miche: 90, Vyna: 85, ]

Vyna[Friends: Helen: 85, ]

Grace[Friends: Cathy: 50, ]


Minimum Spanning Tree: 

Megan  20  Miche

Cathy  50  Grace

Cathy  60  Miche

Tiana  70  Megan

Helen  85  Vyna

Miche  90  Helen

Total: 375


Testing on empty graph 

Current graph: 


Shortest Path from Miche: 

This node does not exist.


Minimum Spanning Tree: 

This is an empty graph.

