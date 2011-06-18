struct Edge {
	Node u, v;
	virtual Node next(const Node & u) {};
	Rect rect();
};

struct DirectedEdge : public Edge {
	virtual Node next(const Node & u) {};
};

struct UndirectedEdge : public Edge {
	virtual Node next(const Node & u) {};
};

